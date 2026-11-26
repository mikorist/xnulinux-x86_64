# Topology, Darwin ABI, extended-state metadata and build reproducibility

Reviewed checkpoints 478-497, November 26, 2026. XNU Monterey 8020.140.41, pinned source commit `27b03b360a988dfd3dfdf34262bb0042026747cc`. Continues the [CP458-477 machine-layer report](amd-machine-layer-followup.md).

Independent builds used the existing Clang 24 and ld64-711 toolchains on Intel Linux and Ryzen 7 5700X WSL2. Standalone diagnostics used QEMU EPYC-Milan-v1 and Broadwell-v2 TCG models; these are not native AMD runtime qualification.

| Checkpoints | Reviewed result |
| --- | --- |
| 478-480 | Full Intel CP477 PID 1 regression; vendor-aware commpage ERMS helper; separate native, virtual Linux and emulated patch revision provenance. |
| 481-484 | Per-vCPU APIC topology, bounded LLC arithmetic (21,056 vectors per host), actual UP XNU topology previews; full Intel CP484 PID 1. |
| 485-486 | Embedded source path caused seven divergent sections. Canonical file-prefix mapping restored all 35 section contents and 47,206 non-STAB tuples; corrected Intel and AMD runtime replay passed. |
| 487-489 | Sparse two-package, six-vCPU topology: distinct addressable slots and active CPUs. Linux LLC membership masks agree on both CPU models; Milan numeric cache IDs and original combined matrix remain HOLD. Transactional membership validator passed captured and negative fixtures. |
| 490-491 | Actual UP membership preview; corrected AMD generic Darwin host subtype from ALL to ARCH1 (type 7, subtype 4, family unknown). Actual loader grading helper verifies generic slice eligibility without claiming x86_64h support. |
| 492-494 | Read-only enabled XSAVE observation: Intel Linux XCR0 0x1f, 1088 bytes; Ryzen WSL2 XCR0 7, 832 bytes. Guarded XGETBV is not invoked before OSXSAVE. Transactional AVX refresh tested with captured early metadata and synthetic post-activation data. |
| 495-497 | Early refresh helper originally emitted MOVUPS before SIMD context activation and caused #UD. Corrected compilation with general registers only, independently reproduced both runtime section inventories and actual Milan diagnostic; audit of 25 rebuilt objects and full Intel standalone regression passed. |

## Latest reviewed candidate

The corrected CP495-v2 image links 1,109 inputs with zero undefined symbols on both hosts. All 35 Mach-O section geometries and contents, all 47,220 non-STAB symbol tuples, normalized header and remaining text bytes agree. The complete binaries are not byte-identical: the symbol string tables differ by 136 bytes.

- Intel image SHA256: `63d04b742bd4660d767d6c46f2f0667f690b7ecc4fb06e5938c78323f1661c73`.
- Ryzen image SHA256: `32fe2834947a198f2b407ba3ff617df5cc4c5f288c9d554e0481d37021897971`.
- CP495 aggregate evidence SHA256: `8bc3675b24b8f29b24a06e76c98431d862e0e5875cbcf58fd39977cd855db5d5`.
- CP497 full Intel regression evidence SHA256: `e5c8c2d850126de8a83a9b2b4a60772ff1fe65f0ddf46c6554b108cce45d81a0`.

The same corrected candidate completes the original instrumented Intel standalone verifier: read-only HFS+ root, real file read, negative lookup, unchanged RAM disk, owned signed Darwin PID 1 at ring 3, BSD syscall and Mach trap return. CP490's 180-second timeout and CP495's initial invalid-opcode failure remain retained failures. The corrected full Intel regression uses a 300-second wall-clock limit without weakening verifier assertions.

The reusable instruction audit examines decoded register operands and selected state-instruction mnemonics in 25 rebuilt machine-layer objects. It detects the original MOVUPS negative control and distinguishes declared Mach-O jump-table data from instructions. This is not an exhaustive transitive call graph or proof against every implicit x87 instruction.

## Boundaries

The actual AMD UP guest still stops deliberately before CPU publication. The local XSAVE refresh preview uses a synthetic post-activation record, not actual XNU FPU initialization, context switching or a hosted ownership transfer. Linux SMP topology observations are not XNU SMP qualification. Native Ryzen CP460 strict component/SRSO PASS (94/94 on each selected Linux guest kernel) remains scoped; guest TSA and Hyper-V SRSO exposure remain separate open items.

All twenty checkpoint evidence hashes were verified privately. The full candidate source and retained-input regeneration still require integration, provenance, licensing and independent public build review. This is a documentation increment, not a release or a complete public replay package.
