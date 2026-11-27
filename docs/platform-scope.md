# XNU for the PC: platform scope and evidence

XNULINUX x86_64 began as an architecture port of [AFK-surf/xnulinux](https://github.com/AFK-surf/xnulinux). Its engineering scope now extends to a complete PC-oriented XNU/Darwin compatibility platform on Linux. The objective is one shared x86_64 implementation across qualified Intel and AMD systems, rather than a collection of CPU-specific patches or separate products.

## Intended platform

| Layer | Goal |
| --- | --- |
| Machine layer | Actual vendor and capability discovery, cache geometry, topology, clocks, optional processor facilities and vendor-specific resource contracts |
| Linux hosting | Versioned FKI, execution context, memory, interrupt and lifecycle ownership, preserving Linux control of physical resources |
| XNU and Darwin | Shared XNU kernel, Mach/BSD semantics, root filesystem, process execution and runtime services |
| Applications | Headless CLI and services, compatible desktop, and seamless application-window integration |
| Deployment | Reproducible builds, documented hardware qualification, installation and recovery |

These are intended capabilities, not a shipping platform. QEMU/KVM are development and qualification tools, not a required production architecture. See [architecture](architecture.md) and [roadmap](roadmap.md).

## Historical reviewed evidence through CP460 (November 26, 2026)

- Independent Intel and Ryzen development hosts reproduced the complete 1,089-input standalone reference executable byte-for-byte with zero undefined symbols.
- The AMD-aware diagnostic candidate uses 1,092 inputs. All 35 final section contents and addresses agree across hosts; whole-file identity is not asserted for that candidate. Actual early AMD discovery under Milan TCG passed on both hosts. The new candidate also passed the full Intel standalone regression, including owned signed Darwin PID 1 at ring 3, read-only HFS+ operations, BSD syscalls and Mach traps.
- The CPU investigation spans Intel Broadwell and AMD Rome, Milan and Genoa model/fixture work, alongside physical Kaby Lake and Ryzen 7 5700X development hardware. Model and fixture coverage must not be confused with native execution or qualification of an entire CPU family.
- CP460 used a dedicated bootable Linux USB to repeat the retained CP426 component regression on physical Ryzen with native KVM and microcode 0x0a201213. Linux 6.19.14 and 7.3.5 guests each passed 94/94 marker groups with the original strict verifier and exit code zero. Host and guests report SRSO Safe RET. Guest TSA and CPU feature dependency warnings, the broad control HOLD, and Hyper-V SRSO exposure remain separate open items.

Sources: [full executable reproduction and machine-layer research](../research/2026-11/hosted/amd-machine-layer.md), [native AMD KVM qualification](../research/2026-11/hosted/native-amd-kvm.md), [qualification matrix](qualification-matrix.md).

## Current research snapshot through CP755 (November 27, 2026)

- CP602 independently reproduces the same 1,114-input unstripped executable on Intel and Ryzen; six strict Broadwell TCG UP runs pass the owned Darwin PID 1 fixture and Mach/BSD returns.
- AMD Milan TCG UP startup now passes MCA, VM/bootstrap, UP CPU/FPU initialization, memory-type initialization and machine_init. Earlier observations reached the RTC/lock-timeout boundary; CP622 records an explicit unqualified AMD admission rejection. Full clock return and AMD userspace are not established.
- CP525 records a native Linux Ryzen SMCA inventory, not physical XNU SMCA handling.
- CP607-610 classify 402 unique dependencies, verify all 44 generated dependencies and trace 27 candidate-local headers to the direct predecessor. Full provenance and clean public source regeneration remain open.

See [AMD startup](../research/2026-11/hosted/amd-startup-498-555.md), [machine lifecycle](../research/2026-11/hosted/amd-machine-lifecycle-556-598.md) and [CP599-612 commpage research](../research/2026-11/hosted/commpage-reproduction-599-612.md). The last closed regular review remains CP497. CP616-617 reproduced the kernel with three newly compiled and 1,111 retained objects; CP621-625 describe the historical completion-evidence gap. CP626/627 establish ordinary Intel-model owned PID 1 console completion on both hosts without debugger. CP628 compares Monterey/Tahoe public source; CP629 validates the Monterey descriptor offline. CP639 reproduces the exact retained link with 28 regenerated and 1,086 retained objects. CP640 compares Tahoe utility dependencies, not build compatibility. CP641 inventories retained GPU/device components and establishes the approved post-kernel direction without runtime qualification. Current documentation reaches CP755, not full integration or source clearance. CP700 reproduces the exact CP602 executable with 95 regenerated and 1,019 retained inputs. CP745-747 establish scoped dual-host compiler and Blocks compile/link regressions; CP754 reaches 249 staged SDK headers. CP755 reproduces an instrumented object from one shared preprocessed input and passes 229 native checks per host; independent preprocessing and final binaries still differ. [CP643-755 research update](../research/2026-11/updates-643-755/README.md). See [current state](../PROJECT-STATE.json).

## Engineering discipline

Independent builds and binary comparisons, scoped runtime assertions, negative tests, preservation of failures and SHA-256 evidence accompany each reviewed milestone. A successful AMD change must preserve the Intel reference where relevant. Actual CPU capabilities and host ownership are preserved; unsupported features are not advertised merely to make a test pass.

Full AMD standalone admission, complete hosted XNU/Darwin boot, application compatibility, broader physical hardware coverage and clean public build reproduction remain open. The repository publishes reviewed increments; the active private research journal can be ahead of this public snapshot.

Getting a kernel to boot is a milestone. Making it reproducible, portable across CPU families and safe to integrate with Linux is the larger engineering task.

## Version targets

One platform retains Monterey as its active baseline and prepares Tahoe as the next version. Shared layers are reused only where qualified; each target has its own source, runtime, build inputs and Intel/AMD qualification. See [version targets](version-targets.md) and [ADR 0005](adr/0005-extensible-version-targets.md).

The [post-kernel plan](post-kernel-platform.md) separates version-matched open runtime, device services, software display, CPU rendering, Linux-owned GPU backends and the independent desktop/seamless acceptance paths. Hardware acceleration is not a prerequisite for headless or basic software graphics. The Monterey hosted gate for Tahoe implementation remains unchanged.

[CP642](../research/2026-11/checkpoint-642.md) verifies a retained offline image conversion helper only; graphics and hosted execution remain separate gates.
