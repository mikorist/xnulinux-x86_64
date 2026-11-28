# Reproduction and evidence index

Independent Intel/Ryzen reproduction and native AMD KVM component qualification are recorded in the [platform evidence overview](platform-scope.md). The public reproduction bundle is under preparation. The historical observations are documented, but a clean public replay has not been performed.

| Experiment | Required evidence |
| --- | --- |
| Toolchain | Exact pins, patch provenance, compiler probe and output object |
| Strict link | Ordered input hashes, linker command, executable header and undefined-symbol result |
| Root mount | Matching kernel, loader, RAM disk, boot plan and replay assertions |
| Named file read | Matching kernel and owned fixture, lookup/read result and disk integrity comparison |

See [selected evidence manifest](../research/2026-11/evidence-manifest.md).

Do not publish raw register traces or entropy-bearing logs without review. Export minimal reviewed evidence and license-compatible reproduction scripts instead. Historical result hashes identify artifacts; they are not a replacement for the artifacts or build procedures.

A reproduction run must use its own output directory and independently check both verifier outcome and actual guest boundary.

## Retained reproduction evidence through CP612

CP602: matching unstripped 1,114-input kernel, ordered input manifest, loader and fixture across Intel/Ryzen; six strict Broadwell TCG UP passes. CP605-610 verify patch lineage, dependency identity and generated-header closure. All 44 generated dependencies match recorded generation outputs; 27 inherited candidate-local headers match the direct predecessor. Clean full-source generation and public replay remain open. The [current report](../research/2026-11/hosted/commpage-reproduction-599-612.md) records candidate identifiers. The [history audit](../research/2026-11/history/engineering-history-through-612.md) distinguishes 371 verified primary evidence hashes from older entries using other formats.

## CP621 follow-up

The exact CP602 relink with three regenerated and 1,111 retained inputs is not a clean full-source build. Four independent observer-free smoke launches did not yield a validated completion signal. Keep this HOLD distinct from the six earlier observed Intel standalone passes. See [CP613-620](../research/2026-11/checkpoint-613-620.md) and [CP621](../research/2026-11/checkpoint-621.md).

## CP629 retained artifact boundary

CP627 ordinary Intel-model owned PID 1 completion passes on both hosts with identical kernel, root, loader and initrd. CP629 validates their identity via the Monterey descriptor. HFS was transferred, not independently regenerated on Ryzen. Clean-source and complete public replay remain HOLD. Tahoe uses separate future source/build/runtime qualification. See [CP627](../research/2026-11/checkpoint-627.md) and [CP629](../research/2026-11/checkpoint-629.md).

## Retained-input boundary through CP835

CP639 establishes exact dual-host relink with 28 regenerated and 1,086 retained inputs, not full clean-source reproduction. CP637 shows reproducibility within each GCC environment but different cross-environment binaries for the public C test; CP638 reproduces a self-contained private source package. Distribution still requires attribution, common pinned binary reproduction and separate approval. See [CP639](../research/2026-11/checkpoint-639.md) and [distribution plan](maintainers/distribution-plan.md).

CP700 reproduces the exact CP602 executable with 95 regenerated and 1,019 retained inputs. CP745-747 establish scoped dual-host compiler and Blocks compile/link regressions; CP754 reaches 249 staged SDK headers. CP755 reproduces an instrumented object from one shared preprocessed input and passes 229 native checks per host; independent preprocessing and final binaries still differ. No complete common native build or source-only kernel replay is established. See [CP643-755 research update](../research/2026-11/updates-643-755/README.md).

Latest evidence: CP816-835: accepted regenerated inputs increased from 692 to 764 of 1,114; 350 remain retained. Historical assembler identities and residual Batch 01 recipes are resolved within their tested scope. Twelve historical UIO compatibility objects now match, while 17 distinct derived C++ dependency paths remain HOLD. Complete retained-input links match CP602 on both hosts. No new boot, full clean-source build, runtime, licensing or release qualification. [Research update](../research/2026-11/updates-816-835/README.md).
