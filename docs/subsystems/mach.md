# Mach: memory and IPC

## Memory bootstrap

The standalone tests validated firmware memory descriptors, pmap initialization, a first 512 KiB physical allocation and 117,987 resident page descriptors in the 512 MiB fixture. Later tests observed the natural return of VM bootstrap and the PERCPU phase.

The typed allocation path processed 1,192 fixed and 356 variable records after resolving separate format and temporary-storage blockers. See [typed allocation](../../research/2026-11/memory/typed-allocation.md).

## Mach IPC initialization

Checkpoint 105 observed all 44 startup callbacks, including 37 kobject registration callbacks and waitq, host notification, MIG, voucher and IPC initialization.

| Live structure | Observed result |
| --- | --- |
| IPC spaces and maps | Four distinct nonnull pointers |
| Wait queues | 512 entries |
| Voucher hash heads | 127 self-linked heads |
| MIG table | 1,031 buckets |
| Occupied MIG message IDs | 364 distinct IDs |

These are initialization observations, not successful user-space send/receive or port-right ownership tests.

## Next qualification

Hosted page-table ownership, allocator stress, SMP invalidation, live IPC semantics and user-mode return remain separate from these standalone results.
