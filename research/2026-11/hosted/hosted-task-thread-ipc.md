# Hosted task, thread and IPC resource lifecycle research

November 26, 2026. Checkpoints 358 through 377. Monterey XNU 8020.140.41, source commit `27b03b360a988dfd3dfdf34262bb0042026747cc`.

## Resource dependencies

The private component candidate now allocates task and selected thread records through separate Linux slab caches, using verified Monterey sizes of 1,616 and 2,680 bytes respectively. The latter comprises a 1,904-byte thread record and an untouched 776-byte BSD tail. Native XNU zone initialization and BSD thread construction are not performed.

Four simultaneous private task records share an immutable task ledger template while owning separate balances, counters, I/O statistics and IPC metadata. The test uses a shared borrowed map, not four native address spaces. Per client cycle, all 19 task allocations and 15 selected-thread allocations are released. Dynamic thread identities range from 101 to 136; references follow 2:3:2:0 across attachment, publication, clearing and detachment. Per-thread CPU-time ledgers remain zero. Native CPU time and I/O event accounting are not active.

The thread construction path checks the pinned admission predicate, 64 fixture combinations, and actual halted and suspended parent rejections. Three injected cancellation stages for each of 36 attachments unwind 108 failed constructions. Five worker-preparation cancellation boundaries unwind the typed caches, ledger templates, IPC metadata and RNG before READY is published.

## IPC and startup geometry

The linked ZALLOC phase contains 206 records, including 149 direct zone descriptors and 57 other callbacks. The inventory is static evidence, not execution of the phase. The original IPC table size arithmetic is checked against independent expected arrays of 256 entry and 64 request descriptors. Private metadata uses bounded sizes 21, 42 and 85, with 20, 41 and 84 usable names; the worker reserves 42 entries. A selected-field projection uses eight verified offsets in a 120-byte IPC space record, with Linux lock/RNG sidecar storage separate from the native-layout prefix.

Exhaustion, reuse, stale lookup and foreign unbind are checked. Retirement now rejects a bound owner or outstanding names without consuming the table. No native IPC rights, port objects, messages, hazard pointers, native locks or native table growth are established.

## Reproducible regression

Two fresh builds and two client cycles per isolated QEMU TCG Linux guest were repeated from an archive of the private Git candidate. Both runs verify 255 input files, 94 marker groups and 184 required marker occurrences per target. The provider finishes each guest run with eight allocations, eight frees, sixteen closes and zero active sessions.

| Linux kernel | Result | Serial log SHA-256 |
|---|---|---|
| `7.3.5-2-liquorix-amd64` | PASS | `406ca865562557df2ab9e7bf01fe0177f98301d0901cf98ad1da772e52d9728d` |
| `6.19.14-2-liquorix-amd64` | PASS | `47599c1d72b89d46b4c1a35429f895369c22109dea8fccbed2f4bd3cdb33c212` |

Input manifest SHA-256: `6de89456c4506019f6fe15600eb9feea0e18a16b8905b960c2b07c7c4b030eee`.

A separate clean extraction replay ran 41 scripts, including startup coverage, and reproduced 111 manifest outputs byte-for-byte using retained reference objects and linked image. It is not a fresh source-only XNU build. The private Git candidate remains held for file-level provenance, licensing and public reproduction review.

## Remaining work

Native zones, task/thread creation, active pmap, execution-context transition, native scheduler dispatch, actual Mach IPC and remaining startup callbacks are still open. No physical module load, hosted XNU boot, or Darwin userspace execution is claimed. This is a scoped research report, not a complete individual-checkpoint publication.

Previous report: [Hosted task ownership and ledger research](hosted-task-ledger.md).
