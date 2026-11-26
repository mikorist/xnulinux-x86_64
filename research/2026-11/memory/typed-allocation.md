# Standalone typed allocator qualification

**Date:** 2026-11-25  
**Scope:** Standalone diagnostic kernel, checkpoints 98–102.

The standalone executable reports dynamic kernel collection format, which the original typed allocation parser rejected. A restricted consumer adaptation retained the original type-view copying and segregation policy, rather than changing the reported kernel collection format globally.

The first fixed-type parser run processed 1,192 records but exposed a separate local capacity defect: a size class requested 22 zones against a 20-slot temporary array. The isolated correction retained the 200-zone policy budget and global MAX_ZONES of 650, while bounding local storage.

| Final replay check | Result |
| --- | --- |
| Fixed records processed | 1,192 |
| Variable records processed | 356 |
| ZALLOC callbacks | 206 |
| Distinct fixed-record zones | 213 |
| VM bootstrap | Natural return observed |
| PERCPU phase | Completed |

The final fixed and variable records were independently checked in guest dumps. The verifier also corrected its earlier assumption that the kernel map address should remain constant during relocation.

Limits: no general allocator stress qualification, complete stack high-water analysis, hosted memory qualification or negative native contract suite.
