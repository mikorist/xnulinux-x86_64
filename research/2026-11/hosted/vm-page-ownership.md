# Native VM page descriptors and hosted page ownership

**Date:** 2026-11-25  
**Source checkpoints:** 201–204.  
**Scope:** Selected original XNU VM source and linked leaf instructions, bounded Linux-backed page services, physical and isolated guest tests.

## Physical split service (201)

The previously qualified exact FKI provider and APSL PE client were loaded and unloaded in normal dependency order on the physical Intel i5-7500T, Linux 7.3.5-2-liquorix-amd64, following scoped authorization and preflight. The physical CPL0 test recorded 256 serial sessions, 512 bootstrap hostcalls, 5,376 integration checks and 3,840 memory checks. All 768 page allocations had matching frees; all 256 sessions closed. Provider removal while the client was resident was rejected, as expected. Normal client/provider unload succeeded.

The initial log verifier failed because three old lines had rotated out of the kernel log. The corrected assessment verified a contiguous 1,591-line overlap and four new records, without a recorded kernel fault or warning in that delta. Preserve both findings. Physical evidence SHA-256: `28d1e2600d6110c8d20cbf5c4f41fd5ece57366765ff095b4c62575be4978baf`.

## Exact linked descriptor initialization (202)

The native XNU pmap bootstrap depends on native page tables, CPU state, locks and allocator initialization. It was not transplanted into Linux. Instead the actual linked 80-byte vm_page_init leaf from the pinned standalone kernel was extracted unchanged and executed in an isolated Linux userspace mapping with RX code and guarded writable metadata.

DWARF established a 56-byte descriptor, offset field at byte 24 and ppnum at byte 48. On the physical CPU, four pinned runs of 4,096 alternating descriptor positions each checked the full object and surrounding canaries. All 16,384 initializations passed, comparing 917,504 descriptor bytes and 66,191,360 canary bytes. The page numbers were synthetic and never dereferenced.

Code SHA-256: `7a64e9cee7c545d08cfb2a7dd45e640f846ec4a54c4351522f3cc9c62be2e0d8`. Result: `edeb538192c269432668a5c3c9e7b2d6ac8e1017a8f5ec8314a7d55810f8ba22`.

## Source-backed ownership (203)

The original vm_page_init body and full struct vm_page were extracted from pinned sources with Apple and CMU notices. The Kbuild ELF client compared the initialized descriptor against the native instruction evidence. A new private serial adapter associates a logical ppnum with an opaque FKI handle; it is not a physical page frame number. Reserved identifiers, stale ownership, bounds and wrap are rejected. No host PFN or pointer is exposed.

Two distinct live pages, full-page patterns, a subsequent complete reread, newly allocated zero pages and explicit/automatic cleanup were checked. The original FKI provider was unchanged from checkpoint 200. After strengthening the initial test, 22 final isolated boots passed, including all twenty representative 6.x kernels and two current Liquorix boots. Both modules used ordinary exported symbols only.

## Original source-level zero and partial-copy operations (204)

The original vm_page_zero_fill and vm_page_part_copy bodies were retained with provenance. New hosted pmap page-zero/copy adapter functions invoke bounded FKI services; they are not the native XNU pmap implementations. Tests checked full and partial copies, unchanged source and unaffected bytes, descriptor identity, zeroing, stale handles, invalid ranges and reserved fields. Full native vm_page_copy was deliberately excluded because object locking and code-signing validation were not implemented. A duplicate getter macro introduced during generation was removed before the first build.

| Checkpoint | Final guest boots | Guest memory checks | Physical memory checks | Physical descriptors / alloc/free |
| --- | ---: | ---: | ---: | ---: |
| 203 | 22/22 | 3041280 | 138240 | 768 |
| 204 | 22/22 | 6037504 | 274432 | 768 |

Each physical test recorded 256 sessions, 512 successful bootstrap calls, 5,376 integration checks and zero active sessions after cleanup. The pageops physical test additionally recorded 512 zeros and 512 copies. Expected dependency rejection and normal unload passed. The source log records no new panic/oops/BUG/CPU warning in the checked deltas; subsequent checkpoint 205 exposed a weakness in the earlier warning matcher, so these historical results should not be promoted to the later stronger warning gate without rechecking.

| Evidence | SHA-256 |
| --- | --- |
| VM-MATRIX.json (203) | `32ae53c3fa903095891b693467a8cc8e85dc1dab18f9c46771ea8bb7513fcc42` |
| Physical result (203) | `1c0d2f2bbc64691360e7bc59205153513b8f41ddf04006119bcd79d91a6ba5bf` |
| PAGEOPS-MATRIX.json (204) | `0407060fd605dca2df6459a26cd0e4407caa839e6708db49e9c6682a99fa6eb8` |
| Physical result (204) | `258d1cf5c73b5a448045c50614f7ada7ed167487d951ffb7a8f0095d78490a76` |

No completed native pmap, native VM allocator, independent XNU address space, full code-signing copy path or world switch is established. The original source-level client remains serial. The exact kernel, module and source manifests remain private pending reviewed export.
