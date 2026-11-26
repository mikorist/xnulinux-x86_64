# ADR 0001: Independent XNU versions

- Date: 2026-11-25
- Status: Accepted

## Context

The upstream ARM64 implementation uses XNU 12377.121.6. The Intel research targets XNU 8020.140.41 and Monterey-era x86_64 hardware, including Haswell.

## Decision

Retain the independently pinned Intel and ARM64 source versions. Separate source trees, generated headers, configurations, toolchains, patches and build manifests. Share FKI semantics only where compatibility is established, with explicit ABI version and capability checks.

## Alternatives

A mandatory migration to the upstream XNU version was rejected as a prerequisite for the first Intel implementation. Later upgrades are separately qualified work. The subsequent approved target is XNU 12377 (Tahoe), after stable physical hosted Monterey execution; see the [roadmap](../roadmap.md).

## Consequences

Cross-version objects and headers cannot be treated as interchangeable. Matching Intel userspace and actual hardware support require independent validation. Preserve the ARM64 implementation and regression-test shared changes.

Source: approved decision in checkpoint 52.
