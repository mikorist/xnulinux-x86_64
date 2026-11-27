# CP640: Monterey and Tahoe utility dependency comparison

**Outcome: scoped source comparison PASS; Tahoe build and ABI remain unqualified.** November 27, 2026.

Ryzen compares the 25 successfully regenerated CP630/639 utility source units and their directly referenced pinned source paths from actual Monterey compiler dependency manifests against the clean Tahoe research reference.

| Scope | Identical | Changed | Missing at same path |
| --- | ---: | ---: | ---: |
| Source units | 21 | 3 | 1 |
| Unique direct pinned paths | 121 | 64 | 1 |

Changed units are qsort, trees and inet_ntop; crc16 is absent at the original path. Only three units have all directly referenced pinned paths identical. All 25 also reference other generated, exported or toolchain inputs not qualified for Tahoe. Source similarity does not establish ABI or binary compatibility. The first dependency parser incorrectly included phony target rules; a separate corrected version reads the first logical dependency rule. The original attempt is retained.

No Tahoe compilation or dependency installation, no kernel runtime test or implementation gate change. CP631-640 completes the work series: Tahoe research descriptor and provisional dependency pins, independent public userspace source tests, physical Clang dependency repair, reproducible source staging and a scoped binary readiness assessment, additional Monterey regeneration, and targeted Tahoe source comparison. Stage A release remains HOLD; Monterey remains the active implementation target.

Next: continue Monterey build-source closure and hosted/AMD qualification, Tahoe release mapping and version-specific generated headers. Attribution and common pinned binary environment remain separate distribution tasks.

Primary evidence SHA-256: `e9c3f4d70ab8143543a3192ee8144afb88596e23d43035db82e75ffd62ee6aae`.
