# Inactive root ownership, expansion and cancellation

**Date:** 2026-11-26  
**Checkpoints:** 226–242

226 established a four-level ownership fixture on four real zeroed FKI pages. These hold opaque link/leaf records, **not hardware page-table entries**. Leaf tickets retain source-backed object references; root destruction refuses live leaves, and rollback reclaims private allocations in reverse ownership order. Seven injected unpublished hierarchy failures and the prior object rollback passed.

228–229 tested competing publication by two workers. Each successful competition published one link and reclaimed the loser. 230 added cancellation before publication and worker join ordering for five injected boundaries. These are deliberate boundary injections, not actual allocator exhaustion. 231's separate mutant removed the cancellation predicate: the guest correctly rejected premature publication with EUCLEAN before READY and reclaimed all 27 allocations. This is expected rejection, not a successful candidate.

232–234 tested phase-ordered expansion against root destruction: a held lifetime reference requires EBUSY; destroy-first rejects stale acquisition without allocation. Workers joined before teardown. This is not stochastic arbitrary concurrent pmap destruction.

235/237 checked stale generation rejection across repeated logical slot reuse. 236/239 exercised same-leaf retirement with exactly one winner and stale loser; distinct-leaf destruction remains unqualified.

| Final series | Boots | Evidence |
| --- | ---: | --- |
| 227 | 21 | 3150 hierarchy allocations/frees, 147 rollback cases, 672 roots |
| 229 | 21 | 672 competitions, 320/352 winners, all losers reclaimed |
| 233 | 21 | 105 cancellations, 672 successful competitions |
| 234 | 21 | 840 expansions, 168 held-reference vetoes, 168 stale acquisitions |
| 237 | 21 | 315 generation reuse pairs |
| 239 | 21 | 1344 same-leaf competitions, exactly one retirement per pair |

All six series recorded 251,328 baseline workload checks apiece and zero residual sessions; those repeated checks are not unique functionality. Existing matrix results were reused for independent verification rather than rerun unnecessarily.

238 extracted the original pmap_reference and reference wrappers from the pinned XNU sources. GCC14 userspace UBSan with pthread adapter passed 16,384 retains and releases across four threads, original reference preserved until final release. 241 applied the source-backed reference path in a current-kernel Linux guest to an inactive FKI root: intermediate destroy refused, both pages freed and sessions closed on final release. The first successful guest had suppressed kernel markers; a logging-only replay with loglevel 8 was retained. This still lacks the full native pmap layout, translation and TLB/PCID teardown.

240 records the maintainer's decision to reduce current development regression to two exact Linux targets (7.3.5-2-liquorix-amd64 and 6.19.14-2-liquorix-amd64). No boot in that checkpoint. 242 verified the new single-command checkpoint workflow, byte-preserving archive rotation, recovery and duplicate retry using a copy of the history; technical baseline unchanged.

| Recorded evidence | SHA-256 |
| --- | --- |
| INACTIVE-ROOT-MATRIX (227) | 94e234edcd14e5dae83786a60080cc8cacfe0ea46171fc0d503bff5d27f05fb2 |
| ROOT-EXPAND-MATRIX (229) | 92aa11567a8e8dd5e68a16c21a8a6f4f3c6ee0a10736044468c7ff3e093951d2 |
| Negative control (231) | 610963cae2a4e604688c5396839be76304bffdb3f630e6ad4bcaa50a82ccc54e |
| ROOT-EXPAND-ROLLBACK-MATRIX (233) | 5b1a7801243a3e0af494d93d5e4d0036b685a4aff8a4fe9d7134de7d0d580fce |
| ROOT-LIFETIME-MATRIX (234) | b5bb34983f5b10dc63de7f03e38dfc9ab98314b30060bd2bf035a8fa112f19ef |
| ROOT-GENERATION-MATRIX (237) | c2a4762f9320041d3eecbfef0673ee345c5983f3147476a22ad204cb1727821a |
| LEAF-RETIRE-MATRIX (239) | 45582b7b4d5e5c7b1ddb49a85cc8ee32b1af845694626f9a0f299358a6914737 |
| Guest reference serial (241) | fbb6c590a884252505bde009c3d3ec93a5eb9e10b26575c6819176ed51d03973 |

No actual hardware table activation, raw CR3 changes or physical module insertion in these series. Source-based reference semantics and ownership gates are prerequisites, not completion of native pmap.
