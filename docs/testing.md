# Testing and evidence

## Evidence classes

| Class | What it establishes |
| --- | --- |
| Compile-only | A particular translation unit builds |
| Relocatable link | A defined object set links as MH_OBJECT |
| Strict executable link | Executable layout and symbol closure for the audited input set |
| Standalone runtime | Observed kernel behavior in a specified guest |
| Hosted runtime | Behavior through the Linux hosting boundary |
| Physical hosted runtime | Behavior on an identified physical x86_64 Linux host, with CPU vendor and model recorded |

A successful diagnostic capture can have exit code zero while the guest has panicked. A test result therefore needs an explicit observed boundary and assertions, not only a process exit code.

## Recorded standalone environment

Legacy firmware, QEMU TCG, Broadwell-v2, one vCPU, 512 MiB, no network, no physical disk passthrough. Debugger and QMP connections use local Unix sockets in isolated replay directories.

## Reproduction policy

Record the source pin, input manifest, compiler/linker version, configuration, exact command, output hashes, assertion results, exception classification and limitations. Preserve failed attempts. Use separate replay directories rather than overwrite historical evidence.

For physical hosted tests, add host kernel version, CPU model, module versions and recovery plan. Hosted qualification remains separate.

See [root mount](../research/2026-11/filesystem/first-root-mount.md) and [file read](../research/2026-11/filesystem/first-file-read.md).

## Planned cross-vendor x86_64 test strategy

Intel and AMD share the same source tree, FKI ABI, build system and Darwin runtime. CPU-specific behavior is selected by detected capabilities and vendor-specific adapters where required. Intel remains the first physical hosted baseline; short CPU portability probes may accompany shared-interface changes without delaying it. Full AMD regressions follow the stable Intel baseline.

AMD development can begin on an Intel Linux host using isolated QEMU TCG guests. QEMU 10.0.13 lists EPYC-v1, EPYC-Rome-v1, EPYC-Milan-v1, EPYC-Genoa-v1 and Opteron_G5-v1. Begin with EPYC-v1 or a documented suitable alternative, using the following CPU selection fragment, not a complete boot command:

```sh
-accel tcg -cpu EPYC-v1
```

Verify actual guest vendor, CPUID capabilities and QEMU warnings before interpreting results. A listed model does not guarantee that TCG implements every advertised feature. An Intel KVM guest with an AMD vendor string is not an AMD hardware test. Keep the same pinned XNU sources and two selected Linux kernel targets; build separately for each kernel. Select additional CPU models according to actual risks, rather than running a full matrix on every checkpoint.

| Lane | Evidence boundary |
| --- | --- |
| Physical Intel | Actual Intel hardware behavior in tested scope |
| Intel guest | Isolated Intel-model behavior under the recorded accelerator |
| AMD-model TCG guest on Intel | Emulated AMD-model behavior, not physical AMD qualification |
| Physical AMD | Independent real AMD qualification, with appropriate authorization |

Record host and guest CPU, effective capabilities, accelerator, kernel, source and input hashes, exact command, test results and limitations. Progress from vendor/feature and build probes to standalone, hosted component and integrated regressions. Real AMD hardware, such as an authorized contributor system or rented physical machine, is required before claiming physical AMD support. QEMU is a development tool, not a required production dependency. No AMD runtime result is asserted by this plan.
