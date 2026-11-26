# Executing selected linked XNU code and testing hostcalls

**Date:** 2026-11-25  
**Source checkpoints:** 190, 191, 195.  
**Scope:** Native x86_64 code execution in Linux userspace and controlled Linux guest services.

## Original linked instructions

The pinned XNU vstart path directly establishes its own IDT, GS, page tables and CPU descriptor/MSR state. It cannot simply be called under Linux's ownership model.

Checkpoint 190 instead extracted selected actual linked Mach-O pages from the existing strict standalone kernel candidate. The original relative addresses and instruction bytes were preserved, using RX text, read-only data and inaccessible gaps. The tested functions were PE_boot_args, PE_parse_boot_argn and PE_parse_boot_arg_str with their original in-image dependencies. The boot arguments were a fixed owned fixture, not actual firmware.

Three isolated Linux guest boots passed 30 parser checks and 114 total checks, including six expected child faults on protected or absent mappings. There was no ELF recompilation of the parser and no kernel privilege execution. Payload SHA-256: `1225912b870287bfbc44e0ba674a1242e92a6bd5a4e153160c1b60c902b128d2`.

## Versioned hostcall prototype

Checkpoint 191 introduced a newly written Mach-O entry adapter and a fixed 112-byte pointer-free hostcall record. The Linux-side GPL module supplied actual RNG and UTC services through a private ioctl gateway. The code executed in Linux ring 3, not ring 0. The operation numbers correspond semantically to existing services but do not assert compatibility with the ARM ABI.

Three cold Linux guest boots each ran 64 successful sessions, 128 hostcalls and 580 assertions: 192 sessions, 384 calls and 1,740 assertions overall. Negative cases covered invalid envelopes, sequencing, unsupported requests, unauthorized caller, copy failure and response corruption. Normal close/unload succeeded. An obsolete no_llseek reference was corrected after the initial build failure. No security policy change was used.

Entry SHA-256: `c1ad23a9e83f8b73138d2eb07ca6dd2e57dd18f141b2b948aa932c4fe06e624f`.

## Actual PE seed consumer

Checkpoint 195 combined the entry with unchanged linked instructions from the original XNU seed, device-tree and boot argument functions. The 11-page mapping retained original relative addresses and separated executable, read-only and writable non-executable pages. An extractor initially rejected permission narrowing; that diagnostic was corrected, not a runtime fault.

The owned device-tree fixture was populated from Linux RNG data. The original seed consumer read all 64 bytes, erased the tree value, and on repeat returned zero with a zeroed output. Canary, argument parsing and clock-bracketing checks passed. Seed contents were not logged.

| Execution | Sessions | Service calls | Assertions |
| --- | ---: | ---: | ---: |
| Isolated Linux guest, kernel-module ioctl | 256 | 512 | 7480 |
| Physical i5-7500T Linux process, five runs | 1280 | 2560 | 36075 |

The physical tests used Linux userspace getrandom/clock_gettime, not a live kernel module. Four runs were pinned to individual CPUs and one was unpinned. This is actual physical CPU execution of selected original linked XNU instructions, but not physical ring-0 execution of those bytes.

RESULT.json SHA-256: `c0df0535a1324f9b2ced0ec73ec9cabf3ef906d4a1b3176505c25efb31158226`.

No general Mach-O loader, complete XNU boot, Darwin runtime, production entropy assurance or privileged world switch follows from these experiments. Original manifests and command records remain local pending review.
