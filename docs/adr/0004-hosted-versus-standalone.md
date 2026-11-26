# ADR 0004: Separate standalone and hosted qualification

- Date: 2026-11-25
- Status: Accepted project direction

## Context

Standalone tests isolate XNU initialization and provider compatibility. They do not exercise the Linux-hosted kernel boundary.

## Decision

Keep standalone reference tests and hosted FKI tests distinct. QEMU remains an isolated test environment, not a mandatory production dependency. Pursue hosted integration in parallel rather than waiting for a complete standalone desktop.

## Consequences

Each result must specify its execution environment. A physical hosted claim requires actual physical Linux-hosted evidence; a standalone mount or user program cannot establish it.

See [roadmap](../roadmap.md).
