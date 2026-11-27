# Dependency provenance and publication gates

This inventory records selected actual research inputs, not a final software bill of materials. License labels are recorded findings, not a completed legal review.

| Component | Recorded revision | Publication consideration |
| --- | --- | --- |
| XNU | 8020.140.41 | Preserve APSL notices and file-level provenance |
| FKI | Upstream xnulinux | Preserve GPL boundary |
| LLVM | 58c46bae21181fb4240cf964461bea738d96d50e | Review upstream and local patch notices |
| cctools-port | e101a6940dcb5988808a16626bc43851f00dc05f | Review component-specific terms |
| Portable IIG | ea6d147d668ca15d490da638012243fcd705f30d | Verify generator and generated-output provenance |
| Apple libpthread | 486.100.11 | Per-file review; copyright-only file on hold |
| Apple libdispatch | 1324.41.2 | Review Firehose source and notices |
| BearSSL | 0.6 / 8ef7680081c61b486622f2d983c0d3d21e83caad | MIT, preserve notices |
| NetBSD | netbsd-10 / 35be686b2c783eca603eb8a8d017d89d78ccea65 | Selected DRBG files, BSD-2-Clause |
| Mbed TLS | 3.6.7 / 068ff080b369adfac81509f9b57b2afabaf82dc5 | Recorded Apache-2.0 option; review notices |
| Apple HFS | 583.100.10 / f88a0764a6e0f7c7907c69c90174cde7fc26149b | Mixed recorded APSL notices; hold pending file-level review |
| xpwn | 20c32e5c12d1b22a9d55a59a0ff6267f539b77f4 | GPLv3 host-only HFS fixture utility |

No restricted corecrypto source was adopted as the public provider. Apple proprietary libraries, system disks and restricted components are not part of the publication bundle.

Host-only tools and linked target code must be inventoried separately. Exact license obligations, modifications and corresponding source requirements must be checked before redistribution.

## Approved Intel open-source policy

All mandatory port code, tools and dependencies must have available source under appropriate open-source licenses. GPL-2.0-only Linux FKI and APSL-2.0 XNU code remain separate with original notices and provenance. Linux module compatibility metadata must be truthful; non-GPL-compatible classification does not mean the source is closed. Audit actual imports against each target Module.symvers and MODPOST. Do not bypass GPL-only exports through forwarding, false license declarations or hidden symbol lookup. The new shared ABI and owned adapter MIT marking is a proposal pending attribution and license review. Proprietary macOS userspace is separate, not a mandatory closed component of the minimal open runtime. See [checkpoint 199–200 research](../research/2026-11/hosted/split-memory-service.md). Technical audits do not replace legal review.

## CP602 dependency audit (CP605-610)

Three compiler dependency lists yield 402 unique paths: 328 match tracked upstream content, 44 match recorded generated outputs (42 configuration and two MIG headers), and 30 are candidate-local files. All 27 local header dependencies match the direct predecessor; three C units remain separately tracked. CP605 verifies the retained commpage patch lineage and unchanged APSL header. Content identity is not original authorship, complete generation or license clearance. The full integrated source remains held. See [current provenance report](../research/2026-11/hosted/commpage-reproduction-599-612.md).

CP614 traces the 27 inherited headers to historical retained candidates and records their BSD-2-Clause markers, not final authorship clearance. CP618 verifies installed compiler source/patch identity and 290 resource headers; CP619 regenerates the two link metadata inputs. CP620 compares 1,114 current and 1,089 historical object inputs by byte identity. These are distinct from clean-source regeneration. See [CP613-620](../research/2026-11/checkpoint-613-620.md).
