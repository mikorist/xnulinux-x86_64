# Source-backed VM objects, references and resident hashing

**Date:** 2026-11-26  
**Source checkpoints:** 208–211.  
**Scope:** Original source subsets, native Linux userspace fixtures and bounded physical CPL0 tests.

## Original object template and reference path (208)

The pinned 224-byte vm_object template and actual source declarations, initialization/reference functions and queue macros were retained with provenance. Original DWARF established object size 224, lock offset 8, size offset 24, ref offset 40 and uplq offset 176; vm_page size 56. Native XNU locking requires XNU thread/CPU state, so the source-level fixture uses real pthread locking out of line. The original lock field is reserved, not interpreted as a Linux lock. Packed handles are private arena identifiers, not native packed kernel addresses.

Three native physical Linux userspace runs each tested 4,096 initializations, queue insert/remove operations and four CPU-pinned reference workers. Totals were 12,288 checked initializations, 36,864 inserts and removals each, and 393,216 reference increments. Each four-worker reference test reached 131,073. An initial extraction cut inside a license comment; corrected boundaries preserved the original notices.

Result SHA-256: `4e3e0283801609e88ee13a90433ebc41f8fbefb282b75054e000f507fa95297a`.

## CPL0 source subset (209)

The same extracted source was adapted to Kbuild with actual Linux rwsem and explicit ownership assertions. Two private descriptors were paired with actual FKI pages and coherent aliases. Queue links were removed before mapping/backing cleanup. Native vm_object_deallocate was not executed; the test object was discarded after cleanup with the final reference path still open.

The first runtime passed but the verifier expected 2,688 instead of 2,816 checks. The corrected final 22 guest boots recorded 61,952 checks, 2,816 object-init rounds and 5,632 descriptor/queue/alloc/free/map/unmap operations each. The physical CPL0 run passed 128 rounds, 2,816 checks and 256 corresponding operations. Normal unload and strict runtime log checks passed.

OBJECT-MATRIX SHA-256: `e6c8173dba2621dc9427f11bdf05ccea8d39757ced56d8c8b9508e770abccf59`. Physical result: `25fd44a517fd058df01edb00a9fdde6338f9de46a4579c3c10467d7b5910c6ea`.

## Resident lookup subset (210)

The full original vm_page_lookup and vm_page_remove_internal, original hash macro and selected insertion/removal statements were retained. The complete vm_page_insert_internal and vm_page_remove functions were not transplanted. The new restricted anonymous internal object wrapper rejects unsupported pager, shadow, ledger, wired, purgeable and other unimplemented states.

The Linux userspace fixture exercised 16 buckets and 24 synthetic descriptors across two objects, including real hash collisions and the original slow lookup path after clearing the hint. Duplicate offsets, foreign ownership, head/non-head removal and canaries were checked. The nonfinal reference-release adapter is new code, not original deallocation; it rejects the last release.

After strengthening duplicate and ledger checks, three ordinary native runs and one ASan/UBSan/leak-detection run passed: 1,024 rounds, 2,628,620 checks, 24,576 inserts/removes and 4,096 nonfinal reference releases. No resident descriptors remained.

Result SHA-256: `62ea382b7ac90b8085b4060a77b804f0457ea9fdb2655cc5ed07e4877816822d`.

## Actual page binding and resident hash in CPL0 (211)

The resident source subset was compiled with real Linux spinlock/rwsem, retaining the original object association, offset, hash, queue, resident count and hint semantics for the restricted path. Two actual FKI pages were paired with private descriptors and mapped aliases; native resident metadata was removed before unmap/free. The FKI provider was unchanged. Ordinary exported imports were audited for both modules.

Twenty-two final guest boots passed 118,272 checks and 5,632 insert/remove/backing alloc/free/map/unmap operations each. The physical test passed 128 rounds, 5,376 checks and 256 corresponding operations, including nonfinal releases. Final reference one remained intentionally retained; the isolated arena was discarded. No new warning or fault marker was recorded, and modules unloaded normally.

RESIDENT-MATRIX SHA-256: `0fe05cd9016416246b23082da1f54fe2549f5c47c34b3c99ba21a604997e3739`. Physical result: `22d1f3f1ec30651eb5b75ce912c12fe632929bd6f629b99388b36659e2bde496`.

The native userspace many-descriptor fixture must not be represented as the two-page physical kernel fixture. This is restricted source-level resident and object validation, not a general pager, ledger, zone, VM object lifecycle, concurrent kernel object-reference or pmap implementation.
