# Intel transition mechanisms and negative controls

**Date:** 2026-11-25  
**Source checkpoints:** 181–189.  
**Scope:** Independent freestanding CPU experiments and cooperative Linux guest execution; not a complete XNU world switch.

## Freestanding transition lane

The initial probe used independently allocated page-table roots, different backing pages at the same virtual address, and separate stacks. The assembler's original ELF32 relocation errors were retained; the corrected build used relative references and an appropriate descriptor representation. Checkpoint 181 executed five phase-controlled QMP NMIs and one expected native page fault, with actual interrupted stack and CR3 checked. The harness recognized the expected debug-exit status 33 and exited zero.

Checkpoint 184 added TSS/IST1 and separate GS bases. Seven phase NMIs and 4,096 transitions passed. The runner issued 237 stress NMI requests, but this initial guest did not report a delivered count; it required nonzero delivery only.

| Checkpoint | Cold boots | Transitions | Phase NMIs | Observed stress NMIs |
| --- | ---: | ---: | ---: | ---: |
| 185 | 3 | 12288 | 21 | 719 |
| 187 | 3 | 12288 | 21 | 726 |

The histogram in checkpoint 185 was [0,17,44,0,0,0,0,658], and checkpoint 187 recorded [0,31,26,1,0,0,0,668]. These classify actual CR3, interrupted RSP and GS state. Invalid combinations were absent. Not every valid transition window received asynchronous coverage. These are separate experiment series, not a single cumulative benchmark.

Checkpoint 186 verified two negative controls: missing host GS restoration and absence of asynchronous NMI coverage. Both were rejected with the expected failure marker and debug-exit 35. The first attempted failure capture had interleaved serial output and was rejected by the strict parser; a deterministic rerun produced unambiguous evidence. Fault logging remains a research limitation.

## Protected mappings

Checkpoint 187 replaced the shared RWX large-page mapping with owned 4 KiB mappings, RX code/rodata, RW/NX data, write protection, NX and three stack guards. Sixteen deliberate native fault cases per boot (48 total) checked missing pages, writes to read-only code, execution from NX data, stack guards and absent backing-page identity aliases. The runner required the exact success marker and expected exit status. The page-table and shared writable transition state still do not establish isolation from hostile kernel code.

ELF SHA-256: `a9461699598c13bad5e5e86318e9fedeb1e93040778fab28383ce74fd63d2297`.

## Cooperative Linux lane

Checkpoint 182 verified 64 bounded calls on a Linux guest with native kernel FPU handling, selected control-state snapshots and user XMM15 preservation across module insertion. Initial API and stack-frame compatibility problems were recorded. This was same-context execution.

Checkpoint 183 used Linux-managed borrowed address spaces, not raw CR3 substitution. It recorded 2,051 checked borrows, distinct roots, three controlled NMIs and correct parent/child data isolation; checkpoint 187 independently repeated the same test. The count is not a count of actual CR3 writes.

Checkpoint 188 combined the address-space and SIMD tests with two workers. Both attempted QMP/HMP NMI delivery strategies failed the strict per-CPU coverage requirement: CPU0 observed 346 and 264 callbacks respectively, CPU1 zero. QEMU exit zero was not a passing test; module initialization returned an error.

Checkpoint 189 changed the test to a cooperative cross-CPU APIC NMI path. Three independent two-vCPU boots passed: 12,288 entries, 12,288 nofault rejections, 384 sends and 295 observed active-window callbacks (149 on CPU0, 146 on CPU1). Both CPU coverage gates passed, no state mismatches were recorded, and normal unload/shutdown succeeded. The active window includes more than the assembly leaf; unobserved sends do not establish lost NMIs.

Module SHA-256: `5c051beb09241a4c138fe2058551f60705a1395891b3b19b05493d29178cdec3`.

## Limits and evidence

The freestanding experiments use owned mappings and private exception state. The Linux experiments retain Linux ownership of address spaces, IDT/IST, GS and FPU. The guest-only NMI callback is not approved for production use. No complete foreign kernel transition, actual XNU pmap, full XSAVE, PCID-enabled validation, nested NMI, machine check or double-fault qualification is established. The original per-boot logs, negative controls and manifests remain in the local research archive.
