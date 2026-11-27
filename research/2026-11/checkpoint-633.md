# CP633: Public structural validator replay

**Outcome: dual-host GCC PASS; Clang 19 on the Intel development host HOLD.** November 27, 2026.

Two independent fresh, clean public checkouts at c6076e925f6e2d4ebbe0c9946edba994ce88d8c7 contain identical hashes for all five files of the MIT-licensed [structural validator test](../../tests/hosted/monterey/mach-header-validator/README.md). The existing C11 runner was executed unchanged, with warnings as errors and undefined behavior sanitizer (UBSan).

| Host | Compiler | Result |
| --- | --- | --- |
| Intel | GCC 14.2.0 | 229 checks, 0 failures |
| Ryzen | GCC 15.2.0 | 229 checks, 0 failures |
| Ryzen | Clang 21.1.8 | 229 checks, 0 failures |
| Intel | Clang 19.1.7 | Link failed: missing libclang_rt.ubsan_standalone.a |

Three executions completed successfully (687 checks), with empty stderr. The failed build is retained as evidence. No sanitizer flags were removed. No host packages or kernel configuration were changed. This is a fresh public source test, not evidence of byte-identical distributable binaries, full legal clearance, XNU runtime, or release readiness.

Next: document compiler runtime requirements and independently replay the public Python verifier. Continue Tahoe release association research separately.

Primary evidence SHA-256: `39dc32ede4804d324324e1ad426a6aeea7c87e2fdf20846f2c8f6919e88178bb`.
