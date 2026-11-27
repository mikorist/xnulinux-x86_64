# xnulinux-x86_64

**XNU for the PC: building a shared XNU/Darwin compatibility platform for Intel and AMD x86_64 Linux systems.**

An independently maintained x86_64 development project derived from [AFK-surf/xnulinux](https://github.com/AFK-surf/xnulinux), the original ARM64 implementation.

The goal is to run compatible Darwin and macOS software directly on standard x86_64 PCs running Linux, targeting both Intel and AMD x86_64 processors, using Apple's open-source XNU kernel and a Linux Foreign Kernel Interface (FKI), without requiring a conventional macOS virtual machine or a Hackintosh installation.

> [!IMPORTANT]
> **Experimental research project, not an installable release.**
>
> The Intel research has reached native standalone Darwin userspace execution, physical ring-0 execution of selected XNU components, and integrated hosted memory, clock, CPU and scheduler-facing experiments. A complete hosted XNU boot and macOS application execution on Linux have not yet been demonstrated.
>
> Parallel development is active on an Intel Core i5-7500T Debian host and an AMD Ryzen 7 5700X WSL2 host. Ryzen is the primary compute environment; Intel remains the reference and regression host. Neither a complete hosted boot nor bare-metal AMD compatibility is established.
>
> **Current research: CP626.** Ordinary Intel-model standalone boot reaches the owned PID 1 diagnostic on diya without a debugger. Adding the missing /dev mount directory eliminates the previous reported devfs error; the success marker appears at 92.08 seconds. Original CP602 kernel unchanged. Ryzen replay, AMD admission and hosted boot remain open. [Latest result](research/2026-11/checkpoint-626.md).
>
> Checkpoint 497: independent 1,109-input strict links, all 35 runtime sections and 47,220 non-STAB symbol tuples agree; same-candidate Intel PID 1 and Milan TCG pre-admission checks pass. [Topology and state report](research/2026-11/hosted/topology-state-and-reproducibility.md).

> Checkpoint 477: independent 1,102-input strict links and Milan TCG pre-admission checks pass on both hosts; full Intel PID 1 regression through CP475. [Machine-layer follow-up](research/2026-11/hosted/amd-machine-layer-followup.md).

> Checkpoint 457: all 1,089 baseline inputs and the full standalone executable were reproduced byte-for-byte across Intel and Ryzen. A separate AMD-aware early initialization candidate passed EPYC Milan diagnostics on both hosts and the complete Intel standalone PID 1 regression. AMD admission remains HOLD. Checkpoint 460 separately confirms native Ryzen Linux KVM CP426 component replay (strict 94/94 on both guest kernels) and SRSO Safe RET; guest TSA and Hyper-V SRSO remain HOLD. See [the full-image and AMD machine-layer report](research/2026-11/hosted/amd-machine-layer.md).
>
> Most experimental development is still local. The original ARM64 project is preserved in the [arm64-reference branch](https://github.com/mikorist/xnulinux-x86_64/tree/arm64-reference). The active tree has been cleared of the original ARM-only boot path, DGX tools, screenshots and CI, while retaining potentially reusable components for review. See [the retained-component inventory](docs/README.md). No inherited component should be treated as x86_64-qualified merely because it is present.

## Beyond a conventional port

XNULINUX x86_64 is developing a complete PC-oriented compatibility platform, not merely a kernel port for one CPU or a set of CPU-specific patches. The intended platform combines a vendor-aware XNU machine layer, Linux-hosted execution and a shared Darwin runtime supporting headless, desktop and seamless application modes. The complete platform is the engineering goal, not a claim of present functionality.

Independent Intel and Ryzen builds, CPU-model experiments, negative tests, cross-vendor regressions and native hardware measurements are central to this work. The reviewed baseline includes byte-identical reproduction of the 1,089-input standalone executable, early AMD machine-layer diagnostics under Milan TCG, a full Intel PID 1 regression, and native AMD KVM component replay with strict 94/94 results on each of two Linux guest kernels. SRSO qualification applies to that native KVM configuration; guest TSA and Hyper-V SRSO remain open. See [platform scope and evidence](docs/platform-scope.md).

## Project philosophy

**Adapt XNU to the PC, not the PC to the Mac.**

The long-term goal of XNULINUX is to eliminate the need for traditional Hackintosh setups by leveraging the existing Linux hardware infrastructure and bringing XNU to standard x86_64 PC hardware.

Rather than making a PC pretend to be a Mac, we aim to make XNU work with the PC as it is.

PC is the project identity and x86_64 is the target architecture. Intel is the established reference lane; development now proceeds in parallel on Intel and AMD Ryzen systems. Full AMD compatibility has not yet been demonstrated. Linux remains responsible for physical hardware and host resources; the project aims to reuse that infrastructure rather than require Mac hardware emulation. This is an independent, experimental open-source project and is not affiliated with Apple Inc.

See [project philosophy](docs/project-philosophy.md) for the design principles.

## What we want to build

One hosted XNU kernel and a shared Darwin runtime, with three ways to use them:

| Mode | Goal |
| --- | --- |
| **Seamless** | Launch individual macOS applications (.app bundles) and use their windows alongside Linux applications on X11 or Wayland, without opening a full macOS desktop. |
| **Desktop** | Run a complete compatible macOS graphical environment, including its system services, Finder and Dock, in a Linux window or fullscreen. |
| **Headless** | Run Darwin command-line programs, development tools and services without a graphical environment or a mandatory proprietary macOS installation. |

Seamless application execution is a major practical goal of the x86_64 project. The complete desktop is a separate, optional mode. All three modes are intended to share the same hosted kernel and runtime rather than starting a separate kernel for every application.

## Intended architecture

```text
 Darwin CLI       macOS applications       macOS desktop
      |                   |                     |
      +-------------------+---------------------+
                          |
                  Shared Darwin runtime
                          |
                 XNU (x86_64)
                          |
           xnu.ko / x86_64 machine-layer adapter
                          |
                Versioned FKI interface
                          |
                  fki.ko (Linux side)
                          |
            Linux kernel on Intel or AMD CPU
```

Linux remains responsible for host resources. The shared x86_64 implementation must establish its own CPU-context, memory, interrupt, scheduling and lifecycle contracts. ARM64-specific code is a reference, not a drop-in x86_64 implementation.

CPU-specific behavior is selected by detected capabilities and vendor-aware adapters where necessary. The diagram describes the intended architecture, not a completed implementation. QEMU/KVM are development and regression environments, not intended requirements of the finished product.

## Current development status

**Current published research snapshot: November 27, 2026, CP626. Last closed regular integration review: CP497.**

The [project state manifest](PROJECT-STATE.json) is the compact status snapshot for this publication. Six completed technical review windows (CP498-617) and four subsequent checkpoints remain open; all 124 primary evidence hashes were independently checked. Historical chapters and full individual evidence clearance are tracked separately.

The current CP602 standalone candidate has 1,114 inputs, zero undefined symbols and byte-identical Intel/Ryzen builds. Six strict Broadwell-v2 TCG UP runs pass the HFS/PID 1/Mach/BSD gate. Milan TCG reaches the RTC/lock-timeout observation boundary after machine_init returns; CPU admission and complete clock return are not qualified. See [current qualification matrix](docs/qualification-matrix.md) and [CP599-612 research](research/2026-11/hosted/commpage-reproduction-599-612.md).

CP613-620: offline clock calibration agrees on both hosts; three current source units were freshly compiled on each host, and both relinks reproduced the exact 1,114-input CP602 kernel using 1,111 retained objects. The compiler patch and 290 resource headers match; both linker metadata files were regenerated. Of the current input objects, 1,069 match CP444 byte-for-byte. The remaining 45 require further provenance assessment. The historical clock candidate is unqualified and not integrated. No new guest boot was performed.

CP621: four observer-free CP602 launches reached the loader metadata-ready marker but timed out after eight seconds without a validated completion signal. This is a HOLD on ordinary boot evidence, not proof of a kernel failure. See [CP621](research/2026-11/checkpoint-621.md).

CP622 corrects the missing serial observation in CP621. Both Broadwell runs reach BSD buffer initialization; both Milan runs explicitly report that AMD admission is unqualified. No independent ordinary PID 1 completion was observed. [CP622 report](research/2026-11/checkpoint-622.md).

CP623: on both hosts the unchanged Broadwell serial output remains at 1,312 bytes from 12 through 60 seconds. The owned PID 1 fixture has no console completion output; silence cannot distinguish success from failure. [CP623 report](research/2026-11/checkpoint-623.md).

CP624: a separate owned console-reporting diagnostic builds byte-identically on both hosts and passes offline executable checks. Its diya HFS image passes read-only verification and payload extraction. No new guest run. [CP624 report](research/2026-11/checkpoint-624.md).

CP625: separate console fixture reports ordinary HFS root mount and init load attempt by 92.08 seconds, with devfs mount error 2 and no terminal marker by 100 seconds. [CP625 report](research/2026-11/checkpoint-625.md).

CP626: corrected standalone fixture reports XNUL_PID1_624_PASS at 92.08 seconds without a debugger on diya Broadwell TCG. No prior devfs error, failure marker or panic is reported. [CP626 report](research/2026-11/checkpoint-626.md).

**Next:** independently reproduce the corrected fixture and ordinary Intel-model completion on Ryzen; preserve CP602 and existing AMD admission requirements. See [roadmap](docs/roadmap.md) and [project navigation](docs/project-navigation.md).

The development infrastructure includes a dedicated Ryzen compute host in parallel with Intel. The latest reviewed evidence includes the [parallel development report](research/2026-11/hosted/parallel-intel-ryzen.md) through checkpoint 417 and the [cross-host OSFMK and AMD KVM report](research/2026-11/hosted/osfmk-cross-host-reproduction.md) through checkpoint 437, followed by the [full-image and AMD machine-layer report](research/2026-11/hosted/amd-machine-layer.md) through checkpoint 457 and the [machine-layer follow-up](research/2026-11/hosted/amd-machine-layer-followup.md) through checkpoint 477 and the [topology and extended-state report](research/2026-11/hosted/topology-state-and-reproducibility.md) through checkpoint 497.

The following results are recorded in the local development journal and experimental evidence. They describe different test environments and are not a claim that the complete hosted kernel is already running.

### Standalone Intel XNU

- Built and linked an experimental XNU 8020.140.41 x86_64 kernel from 1,089 input objects with zero undefined symbols.
- Verified Mach VM startup, kernel scheduler round trips, timer interrupts, Mach IPC initialization, IOKit and BSD startup.
- Mounted a real read-only HFS+ root filesystem and verified native file lookup and reads.
- Executed an owned, ad hoc signed Darwin Mach-O program as PID 1 at ring 3, with native BSD system calls and Mach traps.
- Reproduced standalone user-program execution with terminal-only debugger observation and verified restricted HFS filesystem rejection paths.

These milestones were established in isolated standalone QEMU tests. The PID 1 fixture is not Apple's launchd.

### Linux-hosted Intel research

| Area | Recorded progress |
| --- | --- |
| Physical Intel execution | Selected original linked XNU instructions executed in Linux userspace; separately, source-level XNU PE and VM components recompiled for bounded ring-0 execution on a physical Intel Core i5-7500T. |
| FKI and memory | Separate GPL FKI and APSL client modules; real Linux page allocation, zero/copy, alias mapping, ownership, cleanup and concurrent mapping-lifetime tests. |
| VM objects | Restricted original object initialization, resident lookup, reference and final-release paths; further owned map and inactive address-space experiments. |
| Boot metadata | Native-layout boot arguments, mapped Mach-O metadata, original PE seed consumer and source-backed initialization. |
| Clock and entropy | Negotiated Linux host services, calendar arithmetic, hosted PRNG lifecycle and concurrent consumer tests. |
| CPU and thread state | Native-layout processor and thread records, startup callbacks, processor-set and queue initialization. |
| Scheduler-facing work | Original non-realtime queue operations across 96 priorities, realtime queues across 31 priorities, priority-selected C callbacks on two Linux workers, failure cancellation/recovery and FKI elapsed-clock accounting. |
| Mach IPC | Restricted private entry-table allocation, generation, lookup, reuse and exhaustion tests. No live Mach port objects or end-to-end hosted IPC yet. |

The integrated cooperative scheduler-facing regression (checkpoint 307) passed on both selected Linux guest kernels. Checkpoints 308-317 qualified private IPC-entry lifecycle, running timer setup and expiry, realtime selection boundaries and independent 4,096-operation queue models. The checkpoint 317 integrated result records 181 identical common inputs and 49 marker groups appearing twice on each selected Linux guest kernel. This is not a native hosted boot. Checkpoints 318-337 added owned worker service lifetimes, transactional result publication, private startup callback coverage and canonical Git replay. The final private candidate passed on both selected Linux kernels with 191 verified inputs and 62 required marker patterns (58 repeated and four singleton patterns). See the [component and replay report through 337](research/2026-11/hosted/hosted-bootstrap-replay.md).

Checkpoints 338-357 added private task ownership, reference lifecycle, transactional construction, ledger templates and source-backed schema validation. Both selected Linux guests passed the 227-input candidate with 78 marker groups and 152 required marker occurrences each. See the [task and ledger report](research/2026-11/hosted/hosted-task-ledger.md).

Checkpoints 358-377 qualified private typed task/thread resources, reference and allocation rollback, source-derived IPC geometry and non-destructive metadata retirement. Both selected Linux guests passed a fresh private Git-tree replay of 255 inputs and 94 marker groups. See the [task, thread and IPC report](research/2026-11/hosted/hosted-task-thread-ipc.md).

Checkpoints 378-397 verified retained-source provenance, rebuilt 15 native reference objects from an isolated 496-input closure, and replayed both the 258-input private candidate and its 174-input runtime subset on both selected Linux guests. See the [provenance and reproduction report](research/2026-11/hosted/hosted-provenance-reproduction.md).

These are source-backed and bounded integration tests. They do **not** establish native XNU stack switching, a complete hosted world switch, native scheduler dispatch, or a booted hosted Darwin userspace.

### Cross-host reproduction and AMD component testing

Through CP497, independent 1,109-input links and matching runtime section inventories are verified on both hosts. APIC/LLC membership, Darwin generic subtype grading and guarded extended-state metadata are tested within their documented scopes. Full Intel standalone PID 1 passes on the corrected CP495 candidate (CP497); AMD remains at pre-admission. See the [CP478-497 report](research/2026-11/hosted/topology-state-and-reproducibility.md).

Through CP477, independent 1,102-input strict links and actual Milan TCG pre-admission diagnostics pass on both development hosts. Vendor-aware clock, performance, MCA, memory-type, extended-state, TLB and MONITOR metadata contracts have been tested. At that review boundary, the full Intel standalone PID 1 regression was CP475. Full AMD admission and complete hosted runtime remain open. See the [CP458-477 follow-up](research/2026-11/hosted/amd-machine-layer-followup.md).

Both hosts independently reproduced the selected 297 OSFMK C objects (290 original references, four historical compatibility references and three new strict references) and a byte-identical 4,598,216-byte relocatable Mach-O after canonicalizing input paths and timestamps. This earlier milestone was a relocatable link, not a complete kernel link. Actual Ryzen nested KVM runs now match all 94 functional marker groups on both selected guest kernels; strict qualification in that nested Hyper-V environment remains HOLD on the SRSO guest warning. See the [checkpoint 437 report](research/2026-11/hosted/osfmk-cross-host-reproduction.md).

Through checkpoint 457, all 1,089 baseline named inputs and the full strict executable match across hosts. The separate 1,092-input AMD diagnostic links have identical contents and addresses for all 35 sections, not identical complete files. Early AMD discovery executes in XNU under EPYC Milan TCG on both hosts; Intel full PID 1 regression passes on the new candidate. AMD admission and full AMD boot remain open.

**Native AMD update (CP460):** [Native AMD KVM component replay and SRSO qualification](research/2026-11/hosted/native-amd-kvm.md). Both selected guest kernels pass the original strict 94-group verifier on native Ryzen Linux. SRSO is Safe RET on host and guests. Guest TSA and CPU feature dependency remain open; full AMD XNU boot is not qualified.

## Hardware and Linux compatibility

The project targets standard x86_64 PCs, not a single CPU model. Current development proceeds on both Intel and AMD Ryzen, including investigation of older Intel generations, rather than matching a particular Mac model.

- Intel reference and regression host: Core i5-7500T (Kaby Lake), Debian Linux.
- Primary compute and AMD development host: Ryzen 7 5700X (Zen 3, 8 cores / 16 threads), Linux under WSL2.
- Older Intel target under investigation: Core i7-4770 (Haswell).
- Earlier host-service and VM regression series covered representative distribution kernels from Linux 6.0 through 6.19.
- Current focused regression targets: Linux `7.3.5-2-liquorix-amd64` and `6.19.14-2-liquorix-amd64`.

The historical kernel matrix covers specific components and configurations, not a guarantee of full XNU compatibility with every Linux release. AMD development is active in parallel with Intel; full AMD compatibility remains unqualified. A minimum supported CPU or kernel version has not yet been established. The intended implementation shares its source tree, FKI ABI, build system and Darwin runtime across Intel and AMD. Development now uses both an Intel Linux host and an AMD Ryzen 7 5700X Linux environment under WSL2. Ryzen is a primary compute and AMD development host; Intel remains a separate reference and regression host. AMD-model TCG tests, nested hardware virtualization, and bare-metal qualification remain distinct. See the [cross-vendor testing plan](docs/testing.md#planned-cross-vendor-x86_64-test-strategy).

## XNU versions

| Target | XNU source family | Status |
| --- | --- | --- |
| macOS Monterey 12.5 | `8020.140.41` | Current shared x86_64 development baseline |
| macOS Tahoe 26 | `12377` | Next planned x86_64 source target |

Monterey remains an independent target for older Intel hardware. After stable physical Linux-hosted Monterey execution is established, the next planned target is Tahoe, the final macOS generation supporting Intel. The upstream `12377.121.6` revision is a reference for that work; the exact Tahoe x86_64 source pin will be qualified separately.

The intention is to reuse validated common FKI infrastructure through version-specific adapters, without mixing incompatible source revisions or build artifacts.

## Roadmap

- [x] Standalone Intel XNU build and native test-program execution.
- [x] Bounded physical execution of selected XNU source components and FKI services.
- [x] Initial source-backed hosted VM, startup, clock and scheduler-facing integration tests.
- [x] Establish parallel Intel and Ryzen development environments.
- [ ] Complete shared x86_64 hosted machine layer, address-space and execution-context integration, with vendor-specific qualification where required.
- [ ] Native hosted task, scheduler, Mach IPC, BSD and userspace startup.
- [ ] Open headless Darwin runtime and compatible application execution.
- [ ] Optional graphical desktop and seamless application-window integration.
- [ ] Reproducible source release, installation and hardware compatibility documentation.
- [ ] Subsequent XNU 12377 / Tahoe port.
- [ ] Continue parallel AMD-model regressions and qualify native AMD execution on Linux PCs.

## Source availability and research documentation

The x86_64 work is being developed with several parallel AI-assisted research agents and a human maintainer. Successful and failed experiments are recorded with their source revisions, test conditions, evidence and limitations.

The public source tree is being reorganized separately from active local research. Reviewed x86_64 implementation files, build procedures and research documentation will be integrated incrementally into the [x86_64-port branch](https://github.com/mikorist/xnulinux-x86_64/tree/x86_64-port). There is no supported x86_64 installation command or public binary release at this stage.

The original discussion and earlier public milestone report are available in [upstream Issue #10](https://github.com/AFK-surf/xnulinux/issues/10) and the [x86_64 progress update](https://github.com/AFK-surf/xnulinux/issues/10#issuecomment-7174745326).

## Open source, licensing and attribution

The x86_64 platform implementation is intended to be fully open source, including its required build tools and dependencies. The Linux FKI and XNU sides retain separate licensing and provenance: GPL-2.0-only and APSL-2.0 respectively, with file-specific licenses preserved. See [LICENSE](LICENSE) and [LICENSES](LICENSES/). License compatibility and source redistribution remain subject to review.

Proprietary macOS system components, libraries and applications are separate from the open-source platform implementation. No proprietary Apple system images or binaries are distributed by this project. Compatibility does not grant permission to use or redistribute proprietary software; applicable licenses and hardware restrictions must be respected.

This project preserves the Git history and attribution of [AFK-surf/xnulinux](https://github.com/AFK-surf/xnulinux). The original ARM64 project remains independently maintained by its authors. Its documentation and achievements are not presented as x86_64 results.

Thanks to Heyang Zhou and the original xnulinux contributors, Apple Open Source, [macOS-DroidVM](https://github.com/Droid-VM/macOS-DroidVM), [UniXNU](https://github.com/UniXNU), and the contributors to LLVM, cctools, metal2vulkan, Mesa, virglrenderer and krunkit for their respective upstream work. Original copyright and license notices remain in the source tree and Git history.

Copyright © 2026 Heyang Zhou and contributors (original xnulinux).

macOS, Metal and XNU are trademarks of Apple Inc. This project is not affiliated with or endorsed by Apple.

## Incremental public development

Reviewed research outcomes are published chronologically, including PASS, FAIL and HOLD. Each reporting increment updates this README and the affected status documents. The 20-checkpoint technical integration review remains separate; unqualified code is not promoted merely because its results are published. The first public increment includes the [research journal](research/README.md), [qualification matrix](docs/qualification-matrix.md) and [standalone Intel Mach-O metadata validator test](tests/hosted/monterey/mach-header-validator/README.md). The next increment adds a [standalone replay evidence verifier](tests/hosted/monterey/replay-verifier/README.md) and the research update through checkpoint 337. The third increment publishes the task and ledger report through checkpoint 357. The fourth documents task/thread and IPC resource qualification through checkpoint 377. The fifth reports provenance and reference reproduction through checkpoint 397. Parallel development continues with a single integration history. Passing research tests are not automatically production-ready; unresolved source, license or build dependencies are held for review.

## Documentation and research archive

The [engineering history through CP612](research/2026-11/history/engineering-history-through-612.md) connects the original port investigation with the shared PC-platform effort, retained evidence and development-tool incidents.

- [Project navigation and responsibilities](docs/project-navigation.md)
- [Developer documentation](docs/README.md)
- [Research journal and chronological monograph](research/README.md)
- [Architecture decisions](docs/adr/README.md)
- [Contributing](CONTRIBUTING.md) and [security reporting](SECURITY.md)
- [Changelog](CHANGELOG.md) and [AI-assisted development](AI-METHODOLOGY.md)

The historical reports are edited accounts of recorded experiments; they are not a full public reproduction bundle or a certification of every underlying test.
