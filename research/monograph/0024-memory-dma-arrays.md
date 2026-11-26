# 24. Fixed-array contracts in memory descriptor and DMA methods

**Date:** 2026-11-25  
**Source checkpoint:** 45 (R0024)  
**Scope:** Compile-only providers and extracted structural preflight fixtures.

The memory-descriptor method uses a logical count bounded by a fixed 32-element array, while its wire representation contains 33 port descriptors and object references. The pinned provider rejects zero count and null entries. The adapter replaced silent count clamping and pointer-array aliasing with explicit bounds and typed local arrays, preserving metadata checks.

PrepareForDMA has an in/out segment count and a fixed 32-segment result. The prototype snapshots caller capacity, validates returned count before publishing output and preserves full 64-bit segment fields. This does not protect against a provider writing outside its supplied array before returning and does not establish DMA rollback.

Eighteen measured wire types and 54 layout assertions plus five ABI assertions covered nine synchronous methods. Two compile attempts failed on the experimental include path and a null-pointer diagnostic in layout assertions. Both were corrected without additional warning demotions.

| Object | Bytes | SHA-256 |
| --- | ---: | --- |
| IOMemoryDescriptor.iig.cpo | 183752 | `1ca3f9e73307a06d6a8ea6f9fe6041eb054c4edac04ca79108b9f45ce5cd66ec` |
| IODMACommand.iig.cpo | 204408 | `2b751c1f5ea462bec2a3e537e4579effd59f0f5398229222d309ef2f2f09436a` |

The extracted preflight prefixes and shared copy helper passed 66 host checks. Initial fixture compilation required removal of extraction-only unused locals and an unavailable initializer-list dependency; the subsequent driver mistakenly expected 64 checks, corrected to the actual 66. Tests covered boundary counts, descriptor shape, buffer extent, output capacity, overlap and canaries at both valid wire alignments.

CreateWithMemoryDescriptors wire sizes were 868/84 bytes, PrepareForDMA 140/596. No metadata-dependent casts, actual handler, memory allocation, IOMMU or DMA operation was exercised.

Independent probes reached 79, including 13/17 generated units. Total artifacts 948/984; 36 missing. Accepted link 869 inputs and 261 undefined remained unchanged. Original scripts and evidence remain local.
