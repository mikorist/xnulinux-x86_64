# ADR 0002: ACPI PM reference for Legacy research

- Date: 2026-11-25
- Status: Accepted for Legacy standalone research

## Context

PIT calibration passed only five of twenty contended tests. Bounded retries improved this to eleven of twenty without resolving instability.

## Decision

Use validated ACPI PM timer measurements as the default Legacy research reference (clock contract v1, method 2). Retain PIT method 1 as an explicit compatibility path. Do not silently fall back to an unqualified clock.

## Consequences

The measured PM probe passed twenty of twenty contended tests. Frozen-reference negative fixtures were rejected. These results do not qualify UEFI, physical hardware or hosted FKI clocks.

See [firmware and clock research](../../research/2026-11/boot/firmware-and-clock.md). Source: checkpoints 116–118.
