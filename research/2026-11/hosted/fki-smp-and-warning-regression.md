# Multi-session FKI ownership and a corrected warning gate

**Date:** 2026-11-25  
**Source checkpoints:** 205–206.  
**Scope:** Concurrent callers of a mutex-serialized FKI provider, not concurrent native XNU VM execution.

The provider was extended to four independent bounded sessions, two page slots per session, monotonic opaque IDs and session-scoped handles. The separate GPL-2.0-only test driver exports nothing, is not an APSL dependency, and directly uses Linux's scheduling/test APIs. The APSL client and FKI provider retain only ordinary imports in the audited target symbol manifests.

The tests use bound workers with rendezvous and join, verify actual CPU coverage, and check independent writes, cross-session rejections, stale identity, capacity, sequence handling, copy/free and copy/close races. Four pages were allocated concurrently; the configured eight-page maximum was not exercised simultaneously. The provider mutex serializes operations, so this is not a lock-free claim.

An initial compile failed on a same-width but incompatible pointer typedef. The actual wire typedef was used in the corrected source. The stack-work lifecycle and rendezvous readiness were also made explicit.

## Checkpoint 205: functional success, clean-pass claim withdrawn

Twenty representative 6.x guest logs passed a subsequent warning scan. The two current Liquorix guest boots and the physical run had functionally successful checks but emitted a workqueue warning. The old verifier looked only for WARNING: CPU: and missed WARNING: kernel/workqueue.c. The original functional evidence remains historical; those three runs are not clean passes.

The initial series recorded 2,816 rounds and 87,296 SMP checks across 22 boots. Physical testing recorded 128 rounds, 3,968 SMP checks and all four CPUs. Both race outcomes occurred. No remaining modules or crash was reported. The preexisting W taint does not prove that this test caused it.

## Checkpoint 206: corrected implementation and verifier

The test driver switched to the documented create_workqueue API, allowing the target headers to select appropriate bound-workqueue flags. The provider, APSL client, original XNU functions and ABI were unchanged. The log gate was strengthened to include WARNING:, cut here, BUG:, Oops: and panic. A first corrected runtime was clean but the new verifier itself contained an incorrect regular-expression character class; the original attempt was retained, and literal matching corrected.

All 22 final isolated cold boots passed the strengthened gate.

| Race outcome | Final guest totals | Physical run |
| --- | ---: | ---: |
| Copy before free | 1128 | 83 |
| Free before copy | 1688 | 45 |
| Copy before close | 1151 | 87 |
| Close before copy | 1665 | 41 |

The final series recorded 2,816 rounds, 87,296 SMP checks, 28,160 allocations/frees and 16,896 session closes. The physical four-CPU run passed 128 rounds and 3,968 SMP checks, 283,776 combined checks including the serial PE/VM regression, and 1,280 matching allocations/frees. All three modules unloaded normally; active sessions were zero. The verified 1,551-line log overlap had no new warning or fault marker; taint and uptime were recorded with no restart or security-policy change.

Final matrix SHA-256: `f432178cfa4cbe5be76f7e6790f03d4992f16b38903eac632691216827e2d271`. Physical result SHA-256: `83c56792f77ad4ee7f510c9e8f9e1518656653f654384f75b3640d7b3a18e836`.

The original 205 matrix SHA-256 is `b3aa17136b8a993bf0a126947c750f96f23c0cdcb74cce556382b970b4d6a2a6`; do not count it again as a final clean regression. Existing build-time tool warnings remain distinct from runtime warnings. No native XNU scheduler, concurrent original VM client or actual page-table switch was demonstrated.
