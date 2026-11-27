# Testing and evidence

The platform is developed through independent build reproduction, cross-vendor CPU-model probes, negative controls, and separately qualified native hardware execution. A working kernel on one model is insufficient to establish PC-platform compatibility. See [platform scope and evidence](platform-scope.md).

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

Intel and AMD share the same source tree, FKI ABI, build system and Darwin runtime. CPU-specific behavior is selected by detected capabilities and vendor-specific adapters where required. Intel remains the established physical reference lane. AMD development and component regressions proceed in parallel now, without waiting for the complete Intel hosted baseline.

AMD development uses isolated QEMU TCG guests on Intel and a Ryzen 7 5700X WSL2 development host. On the Intel host, QEMU 10.0.13 lists EPYC-v1, EPYC-Rome-v1, EPYC-Milan-v1, EPYC-Genoa-v1 and Opteron_G5-v1. Select a documented model, such as EPYC-Milan-v1 for a Zen 3 approximation, using the following CPU selection fragment, not a complete boot command:

```sh
-accel tcg -cpu EPYC-Milan-v1
```

Verify actual guest vendor, CPUID capabilities and QEMU warnings before interpreting results. A listed model does not guarantee that TCG implements every advertised feature. An Intel KVM guest with an AMD vendor string is not an AMD hardware test. Keep the same pinned XNU sources and two selected Linux kernel targets; build separately for each kernel. Select additional CPU models according to actual risks, rather than running a full matrix on every checkpoint.

| Lane | Evidence boundary |
| --- | --- |
| Physical Intel | Actual Intel hardware behavior in tested scope |
| Intel guest | Isolated Intel-model behavior under the recorded accelerator |
| AMD-model TCG guest on Intel | Emulated AMD-model behavior, not physical AMD qualification |
| AMD-model TCG guest on Ryzen WSL2 | Emulated guest behavior on an AMD compute host, not native AMD qualification |
| Nested KVM on Ryzen WSL2 | Hardware-assisted virtualized component replay: 94/94 functional marker groups on both kernels; strict SRSO HOLD |
| Physical AMD Linux | CP460 native KVM strict 94/94 component replay on both guest kernels, SRSO Safe RET; guest TSA HOLD and full XNU boot unqualified |

Record host and guest CPU, effective capabilities, accelerator, kernel, source and input hashes, exact command, test results and limitations. Progress from vendor/feature and build probes to standalone, hosted component and integrated regressions. Real AMD hardware, such as an authorized contributor system or rented physical machine, is required before claiming physical AMD support. QEMU is a development tool, not a required production dependency. The Ryzen development environment is operational. CP460 establishes scoped native AMD Linux KVM component qualification, not full AMD XNU execution. See the [native AMD KVM report](../research/2026-11/hosted/native-amd-kvm.md). See the [checkpoint 437 report](../research/2026-11/hosted/osfmk-cross-host-reproduction.md) for actual Ryzen nested KVM component results and the SRSO boundary. Technical results are reported through the regular evidence review cycle.

## Current strict replay and evidence snapshot (CP612)

CP561 introduced a strict offline Intel standalone evidence gate with 19 rejected negative controls. It distinguishes a diagnostic exit from verified HFS contents, ENOENT, unchanged disk, owned Darwin PID 1 in user mode and native Mach/BSD returns. CP602-604 recorded six qualifying Broadwell TCG UP runs. The corresponding Milan replays reach the RTC/lock-timeout observation boundary; they are not AMD PID 1 runs. CP525 native Linux SMCA inventory is distinct from XNU hardware execution. See [latest report](../research/2026-11/hosted/commpage-reproduction-599-612.md) and [native inventory context](../research/2026-11/hosted/amd-startup-498-555.md).

## Ordinary standalone boot acceptance

CP621 establishes a missing evidence channel, not a demonstrated boot failure. An ordinary boot qualification must record exact candidate identity, configuration, a bounded timeout, an independent userspace completion observation and distinct failure/incomplete outcomes. A loader marker or exit code alone is insufficient. Establish the Intel control before comparing AMD. This is an acceptance requirement, not an implemented test or a new PASS. See [CP621](../research/2026-11/checkpoint-621.md).
