# Hosted component integration and canonical Git replay

Date: 2026-11-26. Research checkpoints 318 through 337. Target XNU: Monterey 8020.140.41, Apple source commit `27b03b360a988dfd3dfdf34262bb0042026747cc`.

## Reproduction baseline

The checkpoint 317 component candidate was first replayed with explicit target, headers, kernel image and output directory (318). Inspection of the actual Kbuild dependency outputs found 28 translation units and a 140-file build/replay closure within 181 retained files; the minimal closure passed a current-kernel guest replay (319). The initial manual translation-unit count was corrected against the actual Makefile. A committed private Git snapshot then reproduced the original result on both selected kernels (320). Notice inventory is not redistribution clearance.

## Owned services and worker integration

Checkpoints 321 through 327 linked selected, ordinary Linux worker callbacks to a persistent private boot-derived PRNG runtime, with joined worker lifetimes and a common concurrent start gate. Original UUID consumer and elapsed-clock operations run inside the bounded callback harness. A private dead-name metadata table is shared; it has no native Mach port objects. Pre-service rejection, preparation rollback, duplicate and premature execution rejection, and retirement are exercised. The initial generic negative log filter matched a positive marker containing the word FAILURE; the marker was renamed and the full test rerun. Neither a native scheduler nor native SMP is established.

Checkpoints 333 and 334 strengthened the private result boundary and actual metadata owner API. In each final client cycle, two workers attempt 24 jobs; 20 results are committed, two staged results are discarded after injected second-clock rejection, and two are rejected before generation. The generator advances for all 22 successful generation calls, with five reseeds; 44 accepted elapsed samples and a provider sequence delta of 49 are observed. The two existing post-commit error diagnostics are distinct from pre-commit rejection. No output is committed for a rejected second-clock sample. The private metadata API also accepts 63 names, rejects exhaustion without modifying the output, verifies reuse with stale-name rejection and drains the table. Duplicate owner creation does not request additional entropy. These tests do not establish native IPC capabilities or native task creation.

## Native startup dependency scope

Checkpoints 328 through 332 qualified original private stack geometry (65 valid vectors and two rejected inputs), inspected 179 named direct call or jump sites in three compiled bootstrap routines, and bound three additional original phase-1 callbacks: stack geometry, zone record-count arithmetic, and release BSD argument data. The first zone extraction retained an unmatched conditional; the license notices were preserved, the preamble corrected, and the successful build repeated. The startup table contains 2,724 records; phase 1 contains 155. Coverage is 86 private scalar, 46 private counter, 16 metadata-only, three additional private callbacks and four unbound records. This is neither native phase completion nor a complete call graph; indirect targets and native execution bindings are not established.

## Final replay

Checkpoint 335 adds an independently runnable MIT-licensed evidence verifier with synthetic unit tests. Checkpoints 336 and 337 rebuilt the final private component candidate from 191 digest-checked inputs, using fresh output directories, Kbuild, import and vermagic checks, and exact serial marker counts in diskless, networkless two-vCPU QEMU TCG guests. Both the handoff candidate and a private canonical Git archive passed on:

| Linux target | Required marker patterns | Outcome |
| --- | ---: | --- |
| 7.3.5-2-liquorix-amd64 | 62 | PASS |
| 6.19.14-2-liquorix-amd64 | 62 | PASS |

The count includes singleton lifecycle/completion markers, so it is not directly comparable to the earlier 49 repeated marker groups. The final provider teardown reports eight allocations and frees, sixteen closes and zero active sessions per guest. The private Git archive identity was checked before replay. These results do not involve physical module loading.

Evidence manifest SHA-256: checkpoint 336 `2a090fa095925a42384f99bda950f7e05ae444e9c1f01573d8f748f3c1802f8c`; checkpoint 337 `221467d38b1198967ca5f3a591377be8ec0f09b88cea26cb68e585e96a3c45f3`. The full private manifests and logs are retained by the project, not distributed here.

The [public evidence verifier](../../../tests/hosted/monterey/replay-verifier/README.md) can be tested independently with Python 3. The full integrated source package is held for file-level provenance and license review, clean regeneration and selective integration. Historical full replay and individual-record publication also remain open. No complete hosted XNU boot, native context switch, live Mach IPC, BSD execution, Darwin userspace or macOS application execution is claimed.
