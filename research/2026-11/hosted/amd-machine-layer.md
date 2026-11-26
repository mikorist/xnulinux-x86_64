# Full executable reproduction and early AMD machine-layer research

Reviewed checkpoints 438-457, November 26, 2026. XNU Monterey 8020.140.41, source pin `27b03b360a988dfd3dfdf34262bb0042026747cc`.

## Full-image reproduction

Independent Intel and Ryzen WSL2 build environments reproduced all 1,089 selected named link inputs. The strict ld64-711 link with undefined symbols treated as errors produced the same 21,513,632-byte Mach-O executable on both hosts:

```text
SHA256 4ee4d297ffd30b12b235e3b8772fb1ab0fe3dc6fa10d25572b854eef06d032a9
```

The evidence includes retained text-only source and generated inputs. Complete independent regeneration of those inputs, public source provenance clearance and a clean public rebuild remain open. This is not a release artifact.

The unchanged executable reached an owned, signed Darwin PID 1 under Broadwell-v2 TCG on both hosts. The instrumented verifier confirmed a real read-only HFS+ root, a 39-byte file read, an ENOENT negative lookup, an unchanged RAM disk, BSD getpid and a Mach task-self trap. It is not Apple launchd or a complete Linux-hosted boot. The initial EPYC Milan experiment reached the original XNU Unsupported CPU panic.

## AMD-aware discovery

Historical AMD ports and Monterey patch inventories were inspected as research references; third-party patch code was not imported. Original discovery and projection candidates preserve actual vendor, family, model, topology and cache descriptors without assigning an Intel family to AMD. Rome, Milan and Genoa TCG models passed capacity and descriptor cross-checks on Intel and Ryzen hosts. TCG does not advertise the full AMD topology extension; the emulator-specific diagnostic explicitly retains separate provenance and does not qualify physical cache geometry. Ryzen CPUID observed under Hyper-V is not bare-metal evidence.

The next candidate replaced cpuid.o and added three discovery/projection objects. Both strict 1,092-input links succeeded with zero undefined symbols. All 35 final sections match in content, addresses, sizes and flags, but the complete files differ. The Intel image has SHA256 `fae8f163d4ae8dccd6cdab2202b2b645e44c4df07d50ca1726af4bdc08e9d112`; the Ryzen image has SHA256 `9705dd7cf8248cd61589ec6d675c942d29eb5845d53b0170ab557c8811cd996c`.

In both isolated EPYC Milan runs, actual XNU early initialization populated the unpublished CPU information structure with AuthenticAMD, family 19h, model 1, 32 KiB L1 instruction and data caches, 512 KiB L2 and 32 MiB L3. The test deliberately stopped before admission to unqualified machine paths. The CPU information publication pointer remained null. Both Broadwell early controls passed; the complete Intel-host Broadwell regression with the new candidate also reached the owned PID 1 at ring 3, getpid=1, uid=0 and Mach task-self port 515. This is instrumented standalone evidence only.

## Remaining boundaries

AMD admission and full AMD standalone boot remain open. Downstream work includes LBR/PMU, machine-check semantics, microcode reporting and ownership, TSC calibration, PAT/MTRR, commpage and APIC/scheduler topology. Strict SRSO qualification remains HOLD: extended IBPB support was absent in the observed WSL2 and default WHP views even after an owner firmware update. System-mode TCG cannot establish physical microcode protection. No mitigation was weakened. Native AMD Linux or supported future hypervisor exposure is required for final qualification; functional experiments can proceed independently.

No new complete hosted boot, native AMD or production security claim is made. The AMD source candidate is withheld pending integration, provenance review and reproducible public build/test packaging. This report documents selected confirmed research milestones rather than exporting the private research journal or all individual records.

**Subsequent qualification (CP460):** [native AMD KVM component replay](native-amd-kvm.md) passed strict 94/94 on both selected guest kernels with SRSO Safe RET. Earlier HOLD above refers to the historical Hyper-V/TCG evidence. Guest TSA remains a separate HOLD, and AMD admission remains open.
