# Mach virtual memory bootstrap

**Date:** 2026-11-25  
**Scope:** Standalone Legacy QEMU, 512 MiB, uniprocessor.

## Observations

| Check | Recorded result |
| --- | --- |
| Firmware memory map | Validated against live pmap regions |
| pmap bootstrap | Natural return observed |
| First physical allocation | 524,288 bytes, 128 distinct data pages |
| Remaining-page change | 129 pages, including one page-table page |
| Resident page descriptors | 117,987 initialized entries |
| Resident PFNs | Unique, ordered and checked against remaining memory ranges |

The first allocation was independently checked by walking the live page tables. Resident metadata backing pages did not overlap the verified earlier allocation.

An unsupported dynamic kernel collection format blocked typed allocation initialization after resident-page setup. The subsequent research progressed through typed allocator and VM initialization, as recorded in checkpoints 98–102.

## Limits

These observations concern the standalone address-space implementation. They do not qualify Linux-hosted shadow page tables, SMP TLB shootdowns or host memory ownership.

**Source records:** checkpoints 85–86, 93–102. This is a selected overview; the later allocator details require a dedicated report.
