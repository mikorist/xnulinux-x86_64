# Failed approaches and diagnostic lessons

Selected historical findings, not an exhaustive failure archive.

| Attempt | Observed problem | Research response |
| --- | --- | --- |
| Stock Debian LLD | Required Mach-O kernel flags/layout unavailable | Pinned ld64 toolchain |
| Original IIG parser flags | Missing SDK type environment | Scoped parser prelude |
| Modern IORPC output | Monterey ABI mismatch | Version-specific adapter research |
| Early console compilation | Premature SIMD instruction | Isolated scalar build |
| PIT calibration under contention | Repeated acceptance failures | Measured ACPI PM reference |
| Typed allocator | Temporary zone array too small | Bounded local capacity |
| Missing platform personality | IOKit startup panic | Restricted Legacy UP candidate |
| Missing initialized PRNG | Platform startup failure | Real provider research |
| Missing pthread provider | BSD initialization panic | Static diagnostic integration |
| Missing filesystem provider | ENODEV at mountroot | Resident HFS research |
| First HFS replay verifier | Inlined function missed breakpoint | Verify actual installation boundary |
| HFS sizing expression | Device-not-available exception | Integer-only regression |
| Initial host HFS utility | Disposable fixture damaged | Independent utility and verification |

A verifier failure is not automatically a kernel failure. A QEMU cleanup exit of zero is not proof that the kernel reached its intended boundary. Keep original logs and distinguish the two.
