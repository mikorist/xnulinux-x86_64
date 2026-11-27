# Reproducible x86_64 image and AMD machine lifecycle

November 27, 2026. Selected milestones from checkpoints 556-598. Monterey XNU 8020.140.41, source pin `27b03b360a988dfd3dfdf34262bb0042026747cc`. See the [preceding startup report](amd-startup-498-555.md).

Both development hosts independently build and run standalone diagnostic guests. Broadwell-v2 and EPYC-Milan-v1 are QEMU TCG CPU models. Neither the Intel-model run on Ryzen nor Milan on either host establishes physical AMD XNU execution.

| Checkpoints | Observed result |
| --- | --- |
| 556-561 | Intel regression exposed intermittent commpage initialization failure. A separate strict evidence gate distinguished diagnostic exit from actual userspace success; 19 negative controls rejected. |
| 562-566 | Complete unstripped 1,114-input image reproduced byte-for-byte; canonical loader reproduced across hosts; full Intel-model standalone regression passed. |
| 567-578 | Private CPU reporting, legacy platform path and LAPIC initialization/configuration returned; UP i386_smp_init returned. |
| 579-585 | UP topology and CPU thread initialization returned; smp_init and normal FPU initialization returned, including the standard 832-byte AVX save area. |
| 586-591 | Original clock configuration, read-only MTRR initialization, PAT initialization and machine_init returned. |
| 592-593 | Thread machine template returned; RTC timer policy observed; downstream lock-timeout initialization reached. |
| 594-598 | Intel strict regressions on CP589 and CP593 passed; CP593 image and canonical loader independently matched on both hosts. |

At CP562, both independently linked unstripped images were 21,490,112 bytes with SHA256 `d2eff1076f62867784c1ca56f21242ff7cd5938594403e7739b6cd02a5dcbc3b`. Debug information was retained. The 1,114 ordered input digests, 35 sections and non-debug symbol tuples agreed. Some inputs were retained objects; this is not a clean full-source build.

The strict Intel-model gate requires verified HFS file contents, negative lookup (ENOENT), unchanged disk, the project's Darwin PID 1 test program running in user mode, and native Mach/BSD call returns. Earlier timeout and commpage-failure results remain recorded; subsequent passes do not erase them. The canonical CP593 Intel-model regression passed on both development hosts.

The Milan diagnostic path advanced beyond machine_init, but global CPU admission remains unqualified. UP initialization does not qualify multiple CPUs, timer delivery, physical hardware or Linux-hosted execution. CP593 reaches a feature-query boundary inside lock-timeout initialization; the complete clock_init return is not yet established. Guest and host security qualification remain separate.

Selected retained evidence SHA256:

| Checkpoint | Evidence digest |
| --- | --- |
| 561 | `4b33e4122ad786ef25be875e5f81a0e31ad4bef3f2b905505018ffc4ceee1a3a` |
| 562 | `8692dee85f8fd380496b67e9f161b417289b988c194928a1f86b224ac6d9bb15` |
| 565 | `6f29873b31d7121aa49bcb85f61dd9b215bfad7a11887637ca1d7c8334ad3439` |
| 582 | `2dfbac71646bb9fa5063d37da7126c03fc0d011914983c22ee7428b29b4a71d7` |
| 585 | `b41058c5487b9b0e6baa1a26e48c4448c479054e0e825ad24396b134393477dc` |
| 591 | `56400bc30b1c4f03f58a2f27c151e9e5d72335346787b10a7a494fe287dd7c4d` |
| 593 | `68b8d7f1bfdbc415b12653476268ee992b84c208f37b34a1080e4c7334db5dde` |
| 598 | `2712e2d4ad026dfa8be3e5832ba0fe8a85af00b3f0e39571d8dedd9870313c08` |

These are identifiers of retained private evidence, not public replay artifacts. The [CP599-612 report](commpage-reproduction-599-612.md) records the subsequent initialization correction and provenance work. This report is documentation only.
