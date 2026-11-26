/* SPDX-License-Identifier: MIT */
/* Synthetic regression for the structural validator. No kernel image input. */
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "validate.h"

enum { SEG = 32, SEC = SEG + 72, UUID = SEG + 152, LEN = UUID + 24 };
static unsigned char fixture[LEN];
static void put32(unsigned char *p, uint32_t v)
{
    for (unsigned i = 0; i < 4; ++i)
        p[i] = (unsigned char)(v >> (8 * i));
}
static void put64(unsigned char *p, uint64_t v)
{
    put32(p, (uint32_t)v);
    put32(p + 4, (uint32_t)(v >> 32));
}
static unsigned checks, failures;
static void expect(const char *label, int ok)
{
    ++checks;
    if (!ok) {
        ++failures;
        fprintf(stderr, "FAIL: %s\n", label);
    }
}
int main(void)
{
    unsigned char copy[LEN];
    const uint64_t image_size = 8192;
    put32(fixture, 0xfeedfacf);
    put32(fixture + 4, 0x01000007);
    put32(fixture + 12, 2);
    put32(fixture + 16, 2);
    put32(fixture + 20, LEN - 32);
    put32(fixture + SEG, 0x19);
    put32(fixture + SEG + 4, 152);
    memcpy(fixture + SEG + 8, "__TEXT", 6);
    put64(fixture + SEG + 24, 0x1000);
    put64(fixture + SEG + 32, 0x1000);
    put64(fixture + SEG + 40, 4096);
    put64(fixture + SEG + 48, 256);
    put32(fixture + SEG + 64, 1);
    memcpy(fixture + SEC, "__text", 6);
    memcpy(fixture + SEC + 16, "__TEXT", 6);
    put64(fixture + SEC + 32, 0x1010);
    put64(fixture + SEC + 40, 16);
    put32(fixture + SEC + 48, 4112);
    put32(fixture + UUID, 0x1b);
    put32(fixture + UUID + 4, 24);
    expect("valid", validate_mh(fixture, LEN, image_size) == 0);
    expect("null", validate_mh(NULL, LEN, image_size) == -EINVAL);
    for (size_t n = 0; n < LEN; ++n)
        expect("short prefix", validate_mh(fixture, n, image_size) == -EINVAL);
    const struct { const char *name; size_t off; uint32_t value; } cases[] = {
        {"magic", 0, 0}, {"CPU", 4, 12}, {"file type", 12, 1},
        {"count", 16, UINT32_MAX}, {"command bytes", 20, UINT32_MAX},
        {"zero command", SEG + 4, 0}, {"misaligned command", SEG + 4, 73},
        {"oversize command", SEG + 4, UINT32_MAX}, {"short segment", SEG + 4, 64},
        {"section count", SEG + 64, UINT32_MAX},
        {"section segment name", SEC + 16, 0},
        {"section address", SEC + 32, 0},
        {"section size", SEC + 44, UINT32_MAX},
        {"section file range", SEC + 48, UINT32_MAX},
        {"segment file range", SEG + 40, UINT32_MAX},
        {"UUID length", UUID + 4, 16}
    };
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); ++i) {
        memcpy(copy, fixture, LEN);
        put32(copy + cases[i].off, cases[i].value);
        expect(cases[i].name, validate_mh(copy, LEN, image_size) == -EINVAL);
    }
    memcpy(copy, fixture, LEN);
    put64(copy + SEG + 24, UINT64_MAX - 8);
    expect("overflowing VM range", validate_mh(copy, LEN, image_size) == -EINVAL);
    memcpy(copy, fixture, LEN);
    put32(copy + 24, 0x20000000);
    expect("different structural flags", validate_mh(copy, LEN, image_size) == 0);
    expect("short image", validate_mh(fixture, LEN, 4096) == -EINVAL);
    printf("synthetic structural validation: %u checks, %u failures\n", checks, failures);
    return failures != 0;
}
