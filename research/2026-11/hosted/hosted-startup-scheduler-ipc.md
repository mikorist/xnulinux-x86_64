# Early startup, cooperative scheduler-facing execution and private IPC

**Date:** 2026-11-26  
**Checkpoints:** 288–317

## Startup and CPU state

288 executed original thread timer arithmetic on actual FKI elapsed intervals and rejected wrong epoch, duplicate stop, backwards time and overflow. Not per-thread CPU time. 289 original tunable callback used the actual PE parser with six private tunables. 290 verified original RELEASE_X86_64 thread template and original thread_bootstrap: 1,904 bytes, four timers cleared, priority 95. Not a runnable thread. 291 used two actual Linux workers with distinct 4,608-byte CPU records and explicit active-thread ownership; foreign task rejected, publication cleared before join. No GS modification.

292 iterated 79 original plain-C scalar startup records from 2,724 exact linked descriptors. 293 added seven typed records through five verified wrappers, all 86 private scalar callbacks. 294 verified 16 SFI registration classes as metadata with unbound continuation identities. 295 migrated 46 paired counter records using original bodies, retained 92 values and isolated 92 other slots each cycle. 296 qualified two offline processor registration records with reverse-order/duplicate/bounds tests; initial macro failure retained. 297 closed the integrated CPU/thread/startup milestone on both targets with identical sources and two guest lifecycles each.

314 independently cross-checked the full linked startup table, giving a precise phase-1 partition:

| Phase 1 class | Records | Scope |
| --- | ---: | --- |
| Private scalar callbacks | 86 | Original source bodies in bounded state |
| Private counter callbacks | 46 | Paired storage migration |
| SFI registration | 16 | Metadata only |
| Unassigned | 7 | Still open |
| Total phase 1 | 155 | Not native phase completion |

Phase 8 contains the 46 paired counter records; the complete linked table contains 2,724. Do not equate this audit or the 148 classified records with completion of early boot.

## Scheduler-facing integration

298 two Linux workers shared one source-backed processor set; distinct CPU processor fields, offline identity and cross-CPU rejection. 299 original pset assignments/node and five lifecycle queues initialized on verified layout. 300 original non-RT runqueue and bitmap operations tested all 96 priorities (816-byte queue, urgency 37); first failed build retained. 301 embedded the original queue in each offline processor and exercised native-layout thread links. 302 original strict RT operations covered all 31 priorities (1,040-byte queue, 24-byte realtime projection) and deadline ordering. 303 original idle-cache, load-average and embedded timer assignments checked against an oracle; no online transition.

304 used actual Linux workers to select three records each by original priority queue and execute six local C callbacks exactly once, restoring boot-thread identity. No native stack switch. 305 verified failure cancellation after second selected callback and same-worker recovery. 306 accounted original timer bodies using 32 actual FKI elapsed samples over 16 attempts with two injected failures and fresh recoveries. 307 completed two guest lifecycles on each selected kernel.

308–309 original private IPC dead-name entry table (24-byte entries, 63 usable) exercised allocation, freelist, generation, lookup, stale rejection, exhaustion and drain. No real Mach port objects. 309's separate task-record implementation was blocked by tool safety checks, no candidate and no retry; independent IPC regression completed. This is an explicit unresolved dependency, not a silently implemented task path.

310 original running timer setup, deadline and expiry (120-byte timer_call, two processor slots) tested synthetic time. 311 six strict/non-strict RT deadline-choice vectors qualified boundary behavior. 312 two live Linux producers, 16 gated rounds, 32 native-layout queue records and isolated second queue. 313 actual same-epoch FKI elapsed samples drove exact-once private expiry callbacks, rejected backwards/foreign epoch. 315–316 tested 4,096 mixed operations each on 64 records, with independent ordered-array and deadline/priority oracles, bitmap, membership and full drain. 317 integrated these gates and private IPC on both target kernels.

| Two-kernel integrated evidence | SHA-256 |
| --- | --- |
| CPU/thread/startup (297) | 87e753da668b8f737f08f2e47f811cbb096606081016ef7fefdde1771f79c12c |
| Cooperative callbacks (307) | 872cec6a28cd0442e23b05fff59ac965f7cb6114ae29d65a5e71fb3dcf94afe6 |
| Private IPC (309) | a2d049941a918d7743405d2dff6396f3a795b8873cdfbe5b2e2dfaa60df25300 |
| Startup audit (314) | 6c0e6338d52f52ecff8fe6df6215c142c99e04b1d098ba9d13fec955f86d1d5c |
| Scheduler/timers/IPC (317) | 5f74d140df583c40cccb204747e972881938b70ebd2df9b1c58396bdecb12f66 |

317: identical source and two-cycle serial marker groups on Linux 7.3.5-2 and 6.19.14-2; each provider eight allocations/frees, sixteen closes, zero active. This is a meaningful integrated cooperative milestone. Native stack/context switching, genuine task creation, full startup phase execution, real Mach port IPC and hosted XNU boot remain unproven. No physical module load for this candidate. Do not estimate a percentage of boot completion from queue or callback counts.

## Publication-side evidence verification

The saved 317 two-kernel result was independently rehashed for this documentation update: all 181 common input digests matched both source trees, and each target evidence digest matched the recorded file. Both targets record 49 distinct marker groups, each appearing twice (98 markers per target), with identical group counts. This is a file-integrity and recorded-result check, not a new boot. The startup audit explicitly marks native phase completion false; phase 1 has seven unassigned records and phase 8 has two unassigned records. Other component tests are not automatically assigned to linked startup-table records.
