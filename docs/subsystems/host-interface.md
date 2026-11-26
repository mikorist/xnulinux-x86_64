# Linux host interface: design boundary

**Status:** Through checkpoint 216, selected original XNU PE/VM source subsets, split FKI page services, mapping races and restricted empty-object final release have passed scoped physical CPL0 tests. Separate native Linux userspace ownership and process-isolation fixtures have passed. The physical results above remain historical. Through checkpoint 317, separate Linux guest tests integrate FKI-backed process mappings, indexed VM ownership, PE metadata, clock/entropy and cooperative scheduler-facing callbacks. Complete hosted XNU and world switch remain targets. See [physical ring-0 evidence](../../research/2026-11/hosted/physical-ring0.md), [mapping lifetime](../../research/2026-11/hosted/mapping-lifetime.md) and [final reference](../../research/2026-11/hosted/vm-final-reference-and-address-spaces.md).

Linux owns the physical resources. The shared x86_64 port separates the GPL FKI implementation from the APSL XNU loader and hosted kernel side, with an explicit versioned interface.

The recorded project requirements call for separate CPU and memory contexts, an architecture-specific world switch, preserved host interrupt handling and validated lifecycle behavior. The ARM64 path is a reference for semantics, not an Intel implementation.

| Qualification area | Acceptance evidence needed |
| --- | --- |
| CPU context | Correct entry and return without corrupting host state |
| Memory | Explicit ownership and validated mappings |
| Interrupts and faults | Correct host/guest routing, including exceptional paths |
| FPU and SIMD | Preserved state across execution contexts |
| Scheduling and SMP | Independently tested concurrency and CPU lifecycle |
| I/O and userspace | Repeatable hosted filesystem and user-program execution |

These are requirements rather than implementation instructions. The standalone test harness must not be mistaken for the production FKI layer.

See [ADR 0004](../adr/0004-hosted-versus-standalone.md).
