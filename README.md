# xnulinux-x86_64

**XNU for the PC. Native XNU hosting on x86_64 Linux.**

An independently maintained x86_64 development project derived from [AFK-surf/xnulinux](https://github.com/AFK-surf/xnulinux), the original ARM64 implementation.

The goal is to run compatible Darwin and macOS software directly on standard x86_64 PCs running Linux, initially targeting Intel processors, using Apple's open-source XNU kernel and a Linux Foreign Kernel Interface (FKI), without requiring a conventional macOS virtual machine or a Hackintosh installation.

> [!IMPORTANT]
> **Experimental research project, not an installable release.**
>
> The Intel research has reached native standalone Darwin userspace execution, physical ring-0 execution of selected XNU components, and integrated hosted memory, clock, CPU and scheduler-facing experiments. A complete hosted XNU boot and macOS application execution on Linux have not yet been demonstrated.
>
> Most Intel development is still local. The original ARM64 project is preserved in the [arm64-reference branch](https://github.com/mikorist/xnulinux-x86_64/tree/arm64-reference). The active tree has been cleared of the original ARM-only boot path, DGX tools, screenshots and CI, while retaining potentially reusable components for review. See [the retained-component inventory](docs/README.md). No inherited component should be treated as Intel-qualified merely because it is present.

## Project philosophy

**Adapt XNU to the PC, not the PC to the Mac.**

The long-term goal of XNULINUX is to eliminate the need for traditional Hackintosh setups by leveraging the existing Linux hardware infrastructure and bringing XNU to standard x86_64 PC hardware.

Rather than making a PC pretend to be a Mac, we aim to make XNU work with the PC as it is.

PC is the project identity, x86_64 is the target architecture, and Intel is the established reference lane, and development now proceeds in parallel on Intel and AMD Ryzen x86_64 systems. Full AMD compatibility has not yet been demonstrated. Linux remains responsible for physical hardware and host resources; the project aims to reuse that infrastructure rather than require Mac hardware emulation. This is an independent, experimental open-source project and is not affiliated with Apple Inc.

See [project philosophy](docs/project-philosophy.md) for the design principles.

## What we want to build

One hosted XNU kernel and a shared Darwin runtime, with three ways to use them:

| Mode | Goal |
| --- | --- |
| **Seamless** | Launch individual macOS applications (.app bundles) and use their windows alongside Linux applications on X11 or Wayland, without opening a full macOS desktop. |
| **Desktop** | Run a complete compatible macOS graphical environment, including its system services, Finder and Dock, in a Linux window or fullscreen. |
| **Headless** | Run Darwin command-line programs, development tools and services without a graphical environment or a mandatory proprietary macOS installation. |

Seamless application execution is a major practical goal of the Intel project. The complete desktop is a separate, optional mode. All three modes are intended to share the same hosted kernel and runtime rather than starting a separate kernel for every application.

## Intended architecture

```text
 Darwin CLI       macOS applications       macOS desktop
      |                   |                     |
      +-------------------+---------------------+
                          |
                  Shared Darwin runtime
                          |
                 Intel XNU (x86_64)
                          |
           xnu.ko / Intel machine-layer adapter
                          |
                Versioned FKI interface
                          |
                  fki.ko (Linux side)
                          |
            Linux kernel on physical Intel CPU
```

Linux remains responsible for host resources. The Intel implementation must establish its own CPU-context, memory, interrupt, scheduling and lifecycle contracts. ARM64-specific code is a reference, not a drop-in x86_64 implementation.

QEMU/KVM are development and regression environments, not intended requirements of the finished product.

## Current development status

**Research snapshot: November 26, 2026, checkpoint 397.**

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

## Hardware and Linux compatibility

The project targets standard x86_64 PCs. Current development and qualification focus on Intel processors, including older generations, rather than matching a particular Mac model.

- Physical development host: Intel Core i5-7500T (Kaby Lake), Debian Linux.
- Older Intel target under investigation: Core i7-4770 (Haswell).
- Earlier host-service and VM regression series covered representative distribution kernels from Linux 6.0 through 6.19.
- Current focused regression targets: Linux `7.3.5-2-liquorix-amd64` and `6.19.14-2-liquorix-amd64`.

The historical kernel matrix covers specific components and configurations, not a guarantee of full XNU compatibility with every Linux release. AMD development is active in parallel with Intel; full AMD compatibility remains unqualified. A minimum supported CPU or kernel version has not yet been established. The intended implementation shares its source tree, FKI ABI, build system and Darwin runtime across Intel and AMD. Development now uses both an Intel Linux host and an AMD Ryzen 7 5700X Linux environment under WSL2. Ryzen is a primary compute and AMD development host; Intel remains a separate reference and regression host. AMD-model TCG tests, nested hardware virtualization, and bare-metal qualification remain distinct. See the [cross-vendor testing plan](docs/testing.md#planned-cross-vendor-x86_64-test-strategy).

## XNU versions

| Target | XNU source family | Status |
| --- | --- | --- |
| macOS Monterey 12.5 | `8020.140.41` | Current Intel development baseline |
| macOS Tahoe 26 | `12377` | Next planned Intel port |

Monterey remains an independent target for older Intel hardware. After stable physical Linux-hosted Monterey execution is established, the next planned target is Tahoe, the final macOS generation supporting Intel. The upstream `12377.121.6` revision is a reference for that work; the exact Intel Tahoe source pin will be qualified separately.

The intention is to reuse validated Intel FKI infrastructure through version-specific adapters, without mixing incompatible source revisions or build artifacts.

## Roadmap

- [x] Standalone Intel XNU build and native test-program execution.
- [x] Bounded physical execution of selected XNU source components and FKI services.
- [x] Initial source-backed hosted VM, startup, clock and scheduler-facing integration tests.
- [ ] Complete Intel hosted machine layer, address-space and execution-context integration.
- [ ] Native hosted task, scheduler, Mach IPC, BSD and userspace startup.
- [ ] Open headless Darwin runtime and compatible application execution.
- [ ] Optional graphical desktop and seamless application-window integration.
- [ ] Reproducible source release, installation and hardware compatibility documentation.
- [ ] Subsequent XNU 12377 / Tahoe port.
- [ ] AMD x86_64 compatibility and qualification on Linux PCs.

## Source availability and research documentation

The Intel work is being developed with several parallel AI-assisted research agents and a human maintainer. Successful and failed experiments are recorded with their source revisions, test conditions, evidence and limitations.

The public source tree is being reorganized separately from active local research. Reviewed Intel implementation files, build procedures and research documentation will be integrated incrementally into the [x86_64-port branch](https://github.com/mikorist/xnulinux-x86_64/tree/x86_64-port). There is no supported Intel installation command or public binary release at this stage.

The original discussion and earlier public milestone report are available in [upstream Issue #10](https://github.com/AFK-surf/xnulinux/issues/10) and the [x86_64 progress update](https://github.com/AFK-surf/xnulinux/issues/10#issuecomment-7174745326).

## Open source, licensing and attribution

The Intel port is intended to be fully open source, including its required build tools and dependencies. The Linux FKI and XNU sides retain separate licensing and provenance: GPL-2.0-only and APSL-2.0 respectively, with file-specific licenses preserved. See [LICENSE](LICENSE) and [LICENSES](LICENSES/). License compatibility and source redistribution remain subject to review.

Proprietary macOS system components, libraries and applications are separate from the open-source port. No proprietary Apple system images or binaries are distributed by this project. Compatibility does not grant permission to use or redistribute proprietary software; applicable licenses and hardware restrictions must be respected.

This project preserves the Git history and attribution of [AFK-surf/xnulinux](https://github.com/AFK-surf/xnulinux). The original ARM64 project remains independently maintained by its authors. Its documentation and achievements are not presented as Intel results.

Thanks to Heyang Zhou and the original xnulinux contributors, Apple Open Source, [macOS-DroidVM](https://github.com/Droid-VM/macOS-DroidVM), [UniXNU](https://github.com/UniXNU), and the contributors to LLVM, cctools, metal2vulkan, Mesa, virglrenderer and krunkit for their respective upstream work. Original copyright and license notices remain in the source tree and Git history.

Copyright © 2026 Heyang Zhou and contributors (original xnulinux).

macOS, Metal and XNU are trademarks of Apple Inc. This project is not affiliated with or endorsed by Apple.

## Incremental public development

Reviewed development source, tests and research reports are integrated after each series of 20 significant research checkpoints. The first public increment includes the [research journal](research/README.md), [qualification matrix](docs/qualification-matrix.md) and [standalone Intel Mach-O metadata validator test](tests/hosted/monterey/mach-header-validator/README.md). The next increment adds a [standalone replay evidence verifier](tests/hosted/monterey/replay-verifier/README.md) and the research update through checkpoint 337. The third increment publishes the task and ledger report through checkpoint 357. The fourth documents task/thread and IPC resource qualification through checkpoint 377. Passing research tests are not automatically production-ready; unresolved source, license or build dependencies are held for review.

## Documentation and research archive

- [Developer documentation](docs/README.md)
- [Research journal and chronological monograph](research/README.md)
- [Architecture decisions](docs/adr/README.md)
- [Contributing](CONTRIBUTING.md) and [security reporting](SECURITY.md)
- [Changelog](CHANGELOG.md) and [AI-assisted development](AI-METHODOLOGY.md)

The historical reports are edited accounts of recorded experiments; they are not a full public reproduction bundle or a certification of every underlying test.
