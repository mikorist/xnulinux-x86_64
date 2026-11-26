# Vendor-aware machine-layer contracts and early runtime validation

Reviewed checkpoints 458-477, November 26, 2026. XNU Monterey 8020.140.41, pinned source commit `27b03b360a988dfd3dfdf34262bb0042026747cc`. This follows the [full executable and early AMD report](amd-machine-layer.md).

## Scope and environments

Independent builds on Intel Core i5-7500T Linux and Ryzen 7 5700X WSL2 used the retained custom Clang 24 and ld64-711 toolchains. QEMU 10.0.13 and 10.2.1 respectively supplied isolated EPYC Milan TCG diagnostic guests. These are model-based, instrumented standalone experiments, not physical AMD boot tests. Native Ryzen Linux KVM evidence is separately documented in [the CP460 report](native-amd-kvm.md).

| Checkpoints | Verified result | Remaining boundary |
| --- | --- | --- |
| 458 | Measured legacy clock contract; 10,008 vectors on each host; XNU pre-admission preview | Timer activation, SMP, hosted time |
| 459-462 | Vendor-aware performance capability enumeration; actual unsupported LBR/KPC service results on Milan | AMD PMU backend, complete ownership and native performance capture |
| 463-464, 471 | MCA discovery and ten legacy emulated banks independently observed; read-only actual XNU bank snapshot | SMCA, error delivery and handling, physical qualification |
| 465-466, 468-470 | PAT decoding, physical address width, variable MTRR validation, real virtual snapshot, legacy range lookup and XNU bounds helpers | Combined effective types, native extensions, actual AMD MTRR initialization, Linux alias accounting |
| 467 | Standard AVX state size 832 bytes and actual XNU XSAVE ABI projection | Context switching and additional extended state |
| 472 | All 35 CP471 Mach-O sections and 47,188 non-STAB symbol tuples match across hosts | Full binary identity; string table sizes differ by 80 bytes |
| 473-474 | Legacy AMD TLB counts projected into the actual XNU ABI | Shared TLB, missing large-page L2 counts, full admission |
| 475 | Corrected AMD extended feature bit collision with the XNU invariant TSC bit | Physical clock stability and AMD clock activation |
| 476-477 | MONITOR metadata published only for valid line geometry; Milan reports zero line sizes, leaving the metadata pointer null | Actual idle instruction and power-state behavior |

Common decoder tests used strict GCC warnings and UBSan on both hosts. Multiple freestanding Mach-O objects reproduced byte-for-byte. Actual guest-memory checks validate the projected structures before the deliberate AMD admission stop, not merely compiled declarations. The original Intel full standalone verifier passed on CP458, CP459, CP462, CP466, CP470 and CP475 images on the Intel host. The last of these verifies read-only HFS+ root, file read, negative lookup, unchanged RAM disk, owned signed Darwin PID 1 at ring 3, BSD syscall and Mach trap return.

## Latest reviewed candidate

CP477 links 1,102 inputs with zero undefined symbols on both hosts. Static and offline mapping checks pass. The complete images have different SHA256 values; CP472 section equivalence applies to CP471, not automatically to later candidates.

- Intel build: `0cffa4d2aa1245ce8f157d612869cf72e3a0b4a8ae282abf7bb87521fd349acc`.
- Ryzen build: `14ae17e787163c5cd68deace201e38da8e1ea6e8ffc40028958a05ed00b0cb0e`.
- CP477 aggregate evidence SHA256: `22a368dab6c5d05fbcfa0690b83f155351880917b25c75e683650d5a333eb96e`.
- CP475 full Intel runtime evidence SHA256: `3cd1b315664f4e2edbd43fe0ee0876a134970c8caa6250a26f5e9277c00bb8dd`.

Both CP477 Milan runs passed the prior discovery assertions and stopped deliberately with the CPU publication pointer still null. CP477 itself had not completed the full Intel PID 1 regression at this review boundary.

## Qualification and release boundaries

The native Ryzen Linux KVM CP426 replay is strict PASS (94/94 on each of Linux 7.3.5 and 6.19.14), with SRSO Safe RET for that tested configuration. Guest TSA, guest CPU feature dependency and Hyper-V SRSO exposure remain separate open items. The broader original aggregate/control HOLD remains recorded. No mitigation was changed.

Actual AMD admission, required downstream machine initialization, microcode and commpage semantics, APIC/topology, native MCA handling, full AMD standalone boot, and complete Linux-hosted runtime are not qualified. Linux retains ownership of physical resources in the hosted design. This is a documentation increment; the full experimental source candidate and retained-input regeneration remain subject to provenance, licensing, integration and public replay review. All twenty checkpoint evidence hashes were verified in the private review. This report does not constitute a complete individual-record publication or a product release.
