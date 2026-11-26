# IOKit initialization and the path to BSD

**Date:** 2026-11-25  
**Scope:** Standalone Legacy uniprocessor research.

## Startup observations

| Check | Recorded result |
| --- | --- |
| SYSCTL callbacks | 1,666 returned |
| Registered OIDs | 1,663 checked in 133 parent lists |
| EARLY_BOOT callbacks | All eight returned |
| Startup entries | 2,724 reached |
| IOKit C++ initialization | Natural return observed |
| CPU publication | One validated CPU published through the native platform path |
| BSD pre-root calls | 77 returned in the later crypto-qualified diagnostic image |

The initial platform configuration blocked CPU enumeration and then panicked because a usable platform driver was missing. A restricted Legacy UP platform candidate matched the real root nub; its startup exposed the missing PRNG provider.

After genuine PRNG registration, the platform published CPU capacity, the bootstrap thread resumed, commpage initialization returned and BSD entry was reached. The subsequent pthread and full diagnostic crypto integration removed additional BSD initialization blockers.

## Limits

The platform candidate does not establish general ACPI, PCI, power management, physical device drivers or SMP support. IOKit initialization is distinct from complete device matching. RTC and calendar initialization remained defective in the recorded pre-root run.

**Source records:** checkpoints 114–115, 119–121, 126–131 and 142–143.
