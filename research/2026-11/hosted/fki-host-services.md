# Intel FKI ordinary Linux-context qualification

**Date:** 2026-11-25  
**Source records:** checkpoints 159, 161, 175, 178–180.  
**Scope:** Static interface audit, host compile probes and isolated Linux guest execution. No hosted XNU execution.

## Independent ABI work

The reference FKI inventory distinguished the existing ARM64 out-of-tree and in-tree interfaces and the separate XNU machine-layer ABI. Matching LP64 structure sizes did not establish semantic portability. The private experimental capability contract passed 65,548 native checks including negative negotiation cases; cross-target compile probes passed.

## Ordinary host services

The GPL Linux module prototype collected Linux-provided boot entropy and checked wall-clock data in ordinary host context. It was built against the recorded Liquorix 7.3.5-2-liquorix-amd64 headers. The actual package kernel was booted in an isolated QEMU guest without a debugger. Module initialization and unload succeeded under the existing guest signing policy. An initial verification failure was caused by console log filtering, not a failed module lifecycle.

The one-shot bootstrap packet remained a private, unapproved contract. A freestanding Mach-O consumer compiled but was not linked into XNU. Sixteen Linux runtime checks covered local packet ownership, validation, one-shot consumption and erasure. No raw entropy is included in this report.

## Concurrent local ownership

Checkpoint 180 used two Linux CPUs in a QEMU guest:

| Test group | Trials |
| --- | ---: |
| Two competing consumers | 32 |
| Consumption versus cancellation | 32 |
| Total | 64 |

All trials passed, 128 workers joined, module unload and guest shutdown succeeded. The recorded winner distribution was not sufficient to claim both cancellation outcomes were observed. Allocation and RNG failure injection, hotplug, unload racing workers and independent join bounds remained untested.

Checkpoint 180 RESULT.json SHA-256: `b45fdaaa807a97703aa76aad0ee715914d6fb3b35abb4ad3c534d07874b7a8c5`.

## Qualification boundary

This is an actual Linux module runtime milestone, not an Intel world switch or XNU boot inside Linux. No module was loaded on the physical host. Cross-context ownership, architecture entry/return, actual XNU metadata adaptation, host memory and CPU-state integration remain mandatory gates.

See the [host interface design](../../../docs/subsystems/host-interface.md) and [qualification matrix](../../../docs/qualification-matrix.md). Original scripts and sanitized evidence require review before public reproduction.
