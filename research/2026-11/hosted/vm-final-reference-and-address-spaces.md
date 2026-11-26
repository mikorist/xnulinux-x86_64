# Restricted final reference and native process address-space isolation

**Date:** 2026-11-26  
**Source checkpoints:** 214–216, with the termination audit in 212.  
**Scope:** Private anonymous empty-object release, physical source-level CPL0 and separate native Linux userspace ownership tests.

The original XNU deallocation path involves termination, shadow/collapse, pager, paging/activity references, potential reaper handoff, resident release, ledger/accounting and zone free. It is not a simple reference decrement. The restricted implementation deliberately does not claim the complete path.

## Empty-object final reference (214–215)

Selected original terminating/alive and refcount-to-zero statements were extracted from the pinned vm_object.c with exact provenance. The existing source-backed resident subset and provider stayed unchanged. Real Linux page allocation replaced the static metadata arena; a validated exclusive lock/state transition precedes wiping and freeing metadata.

The release gate rejects unsupported pager/shadow/copy/named/purgeable/tag/owner states, nonempty queues, extra references, active paging/activity/waiters and open FKI sessions. Existing mapping/backing lifecycle and hash removal must complete before final release. Repeated release is rejected; no dereference occurs after free. This is not a general public reference registry or an asynchronous reaper.

| Scope | Runs/rounds | Checks | Final metadata alloc/free |
| --- | --- | ---: | ---: |
| 22 isolated cold boots (214) | 2816 | 137984 | 2816 |
| Physical CPL0 (215) | 128 | 6272 | 128 |

The guest matrix covered all 20 representative Linux 6.x kernels and two current Liquorix boots; 5,632 resident insert/remove/backing alloc/free/map/unmap operations each and zero active sessions. The exact physical candidate passed with 256 backing allocations/frees/maps/unmaps and 128 closes. Dependency removal was rejected while the client was resident; normal unload succeeded, with no new warning/fault marker in the verified log delta.

FINAL-MATRIX SHA-256: `7772c805cc4096a065c892bdd06dd7cf40662bea582df42f4beaf9fefdb28e79`. Physical result: `ee8f3d6a18933dfebb9983c65734fa2aab39aebdca0228e6a247828cb121a176`.

## Native concurrent ownership and process isolation (216)

A separate native Linux ring-3 experiment used the existing extracted source subsets and selected final transition statements. No QEMU or new live module was used.

A bounded two-object registry uses monotonic object IDs and four reference tickets per object, protected by a registry mutex and per-object pthread rwlock. A guarded metadata arena and memfd backing remain private. Final release removes the resident metadata, closes the backing, applies the selected original state transition, destroys the lock, retires the registry slot and wipes/unmaps metadata. No raw object pointer is published.

Two pinned workers test GET versus last PUT, validating both outcomes: either a new reference ticket survives root release or the lookup rejects the retired object. Reuse, old IDs/tickets, duplicate release and capacity are also tested.

The separate address-space test uses two real Linux fork children mapping distinct memfd backings at the same owned virtual address. Inherited unrelated aliases and foreign backing descriptors are removed. Parent mapping-lifetime tickets survive root-reference release, and all backing bytes are compared. Isolated grandchildren test the expected write fault after protection downgrade and read fault after unmapping. Parent aliases are unmapped before the last tickets are released.

Three full native runs and one sanitizer race-only run recorded:

| Metric | Total |
| --- | ---: |
| GET/last-PUT races | 1024 |
| GET wins / PUT wins | 514 / 510 |
| Paired address-space rounds | 48 |
| Child mappings | 96 |
| Expected isolated SIGSEGV | 192 |
| Metadata alloc/free | 1128 / 1128 |
| Backing open/close | 1128 / 1128 |
| Retired objects | 1128 |
| Gets / releases / stale rejections | 622 / 1750 / 2060 |

An initial variable-name collision with libc was fixed, and the first successful test was retained before strengthening capacity, reuse and scheduling coverage. Intentional fault tests were excluded from the sanitizer-only run; no unexpected sanitizer error was recorded.

Result SHA-256: `57f5be613eac21a6c3340c6b50ec746ea27f80fa393899005c9e80eec77a7ea1`.

Actual Linux process isolation is demonstrated, not a separate XNU kernel address-space root. The memfd backing is separate from the FKI kernel memory service. Lifetime tickets rely on caller discipline and the bounded registry, not an adversarial kernel security boundary. Integration into real FKI/hosted VM, general concurrent resident lookup, native pmap and scheduler prerequisites remain open.
