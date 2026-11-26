# From reference tickets to actual Linux process mappings

**Date:** 2026-11-26  
**Checkpoints:** 217–225  
**Baseline:** XNU 8020.140.41, commit 27b03b360a988dfd3dfdf34262bb0042026747cc.

The native userspace ownership model of 216 was integrated into a bounded APSL-side registry using actual FKI allocations. Two objects, four typed tickets each and monotonic IDs were protected by registry mutex and per-object rwsem. Map tickets could not be dropped as ordinary references; alias removal preceded reference release. Original extracted resident metadata and selected final-reference statements remained separate from the Linux provider.

217 retained the failed initial wire pointer type build and verifier syntax error; corrected guest execution passed. 218 recorded 22 cold boots on the current Liquorix kernel and twenty representative 6.x kernels. In 2,816 rounds both GET/last-PUT and MAP_ENTER/last-PUT outcomes occurred in every boot. 79,362 ownership checks, 7,744 matched allocations/frees and retirements, 2,638 client maps/unmaps, 4,046 provider maps/unmaps, 7,744 closes and zero residual objects/sessions were recorded. CPU masks and peak session counts are per-boot values, not additive totals (clarification 220).

## Process mappings and lifetime

219 introduced a bounded provider-owned page-loan interface and actual Linux process mappings, with distinct backing at identical virtual addresses, nonexecutable permissions and real fault tests in isolated children. Loan lifetime retained a separate object ticket. Revoke required all file, VMA and page references to be gone. The provider, not the APSL client, owns the Linux VMA APIs; the initial import audit identified a GPL-only helper on the current kernel, which was explicitly audited for the GPL provider's actual VMA functionality. APSL imports remained ordinary exports. The first Makefile syntax failure was retained.

220 added initially read-only loans, denied write upgrades, invalid/stale binding checks and injected prepublication cancellation. The first preflight guessed a nonexistent kernel path; no guest launched; the exact earlier image path was reused. The current-kernel revision passed 32 pairs, 10,976 checks, 65 matched allocations/frees and revokes (including rollback), 128 expected isolated faults and zero residue.

222 introduced distinct map-entry tickets, range/permission validation, inherited VMAs surviving original process exit and file-only holds. Initial runtime passed but its counter expectation was wrong; corrected revision separated VMA-only and FD-only cases. 223 added adjacent independently owned entries and a real external page-reference veto: first backing remains retained until its external reference is released while the second mapping survives. This is not long-term pin qualification or general native map clipping.

| Final regression | Guest boots | Kernel/ownership checks | Selected lifetime evidence |
| --- | ---: | ---: | --- |
| 218 | 22 | 79362 | 2816 reference/map races per type |
| 221 | 21 | 230496 | 1344 live mappings; 336 initially RO; 2688 expected faults |
| 224 | 21 | 243936 | 1344 inherited mappings; 672 FD-only holds; 4032 expected faults |
| 225 | 21 | 245280 | 672 external-only vetoes and partial retirements; 3360 expected faults |

The final 21-boot series each covered the current kernel and all twenty representative 6.x versions, with exact common-source and per-run input/import checks. 221 also preserved the first 219 revision separately. Do not count the independently verified existing runs as new boots. All final series ended with zero active sessions/resident objects and matched allocation/cleanup counts.

| Recorded evidence | SHA-256 |
| --- | --- |
| OWNED-MATRIX (218) | 171620184e6e67e856357f563beb451b416a88cf328bdd8601f250ed56319296 |
| HOSTED-MATRIX (221) | cb8434d8e7bd25ec6f4fc83b54231538a68d43c6a2c4500198139001c5eff416 |
| MAP-ENTRY-MATRIX (224) | 7d920aff6006700c35ae6f0f57083c273cf6c4cbd1e2b3885fb4fc06ffda2f03 |
| MAP-RANGE-MATRIX (225) | e9d21fb3970b86d491730f9f9e9f86a22e168e863c4bf3e1341b0554d8cd59da |

225 also audited native map/pmap source dependencies (SOURCE-ANCHORS SHA-256 a5696fe6e1056c9fde2f4d3781a1a8fae4b17e297b38ac92ae89a5d7cd5155e3). This identified the next inactive root ownership gate, separately from activation. No physical module insertion, independent XNU translation, production authorization, general VMA concurrency or completed XNU scheduler was demonstrated. Original manifests and source logs remain private.
