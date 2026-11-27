# Frequently asked questions

New to XNU? Start with the [guide for macOS, Hackintosh and Linux users](getting-started.md). No kernel-development vocabulary test is required.

## Is this a Hackintosh?

No. The goal is to adapt XNU to standard PC hardware through Linux, rather than make a PC pretend to be a Mac. The intended design hosts XNU within Linux rather than replacing Linux with a conventional macOS installation. See [project philosophy](project-philosophy.md).

## Is this still just an x86_64 port?

The initial port is now part of a larger engineering goal: one PC-oriented XNU/Darwin compatibility platform for Intel and AMD Linux systems, including the machine layer, hosted execution, a common runtime and headless, desktop and seamless modes. The platform is still experimental; kernel boot alone does not establish application compatibility. See [platform scope and evidence](platform-scope.md).

## Why PC rather than Intel?

PC describes the intended platform, x86_64 the architecture, and Intel the established reference and qualification lane. AMD development now runs in parallel on a Ryzen 7 5700X WSL2 environment and the established Intel Linux lane. AMD-model standalone startup now reaches the RTC/lock-timeout observation boundary after machine_init returns; native AMD KVM component replay is qualified at CP460. CP525 separately records native Linux SMCA inventory. Complete AMD boot and hosted execution remain open. Other configurations likewise require separate evidence.

## Can I download an installer or an EFI folder?

Not yet. There is no supported x86_64 release, no verified installation procedure and no new Hackintosh EFI here. The current public material includes research reports, reviewed source components and a few small userspace tests. See [what you can run today](getting-started.md#what-you-can-run-today).

## Is XNU Linux?

No. XNU is Apple's kernel; Linux is the intended host. Darwin is not all of macOS, either. XNULINUX is the project name, not a declaration that the two kernels have suddenly become the same thing.

## Does it need QEMU?

QEMU is used for standalone development and regression tests. The intended hosted product does not require a conventional macOS virtual machine. That final execution model must still be demonstrated independently.

## Can I run macOS applications today?

Standalone research has demonstrated root mount, native file reading and execution of an owned Darwin Mach-O PID 1 program. It has not demonstrated a supported macOS application runtime or hosted XNU boot. Follow the [qualification matrix](qualification-matrix.md).

## Why Monterey?

The shared Monterey development baseline uses XNU 8020.140.41 as an independent baseline. Newer XNU versions are not mandatory for the first port. See [ADR 0001](adr/0001-independent-xnu-versions.md).

## Will I need the whole macOS desktop?

The intended modes are headless, desktop and seamless. For each version target they share its runtime; the minimal open headless path should not require a complete proprietary macOS installation.

## Can you distribute macOS or its frameworks?

The project intends to publish its own code and redistributable dependencies according to their licenses. Compatibility does not grant redistribution rights. Proprietary components are separate.

## Why keep failed experiments?

They record actual constraints and prevent repeated work. See [lessons learned](../research/2026-11/lessons-learned.md).

## How is AMD development organized?

A Ryzen 7 5700X WSL2 development environment is now operational alongside the Intel Linux host. Both use the shared source and kernel targets. TCG establishes scoped emulated behavior; nested KVM component runs on actual Ryzen now match 94/94 functional marker groups on both selected kernels, with strict SRSO HOLD in Hyper-V. Native Ryzen Linux KVM subsequently passed strict 94/94 on both selected kernels (CP460); SRSO Safe RET is confirmed for that configuration. Guest TSA, CPU feature dependency and complete AMD XNU boot remain open. See [testing](testing.md#planned-cross-vendor-x86_64-test-strategy).

## What is the latest documented result?

CP641 inventories retained ARM device and GPU sources and records the approved post-kernel development direction. CP639 reproduces the 1,114-input Monterey link with 28 freshly regenerated and 1,086 retained objects. CP627 remains the ordinary Intel-model owned PID 1 boot result. AMD admission, physical hosted execution, Apple launchd, graphics and full clean-source build remain unqualified. See [project state](../PROJECT-STATE.json) and [qualification matrix](qualification-matrix.md).

## Is Tahoe replacing Monterey?

No. Monterey remains the active baseline. Tahoe source preparation can proceed separately; implementation requires stable physical Linux-hosted Monterey Intel execution. Both targets are intended to share qualified platform infrastructure and retain version-matched runtimes. See [version targets](version-targets.md).

## Does a PASS mean my machine is supported?

Only if the documented test actually covers your configuration and the feature you are asking about. A build on Ryzen, a Broadwell TCG guest on Ryzen, and native Ryzen execution are three different things. See [hardware evidence](hardware-compatibility.md). A green checkmark cannot do the work of a driver.

## Is this GNU/Linux with a different kernel?

No. GNU/Linux refers to a system using Linux and GNU components. XNU is a separate kernel. The project aims to host XNU on Linux, without replacing the Linux host or requiring a particular GNU userland. The recursive-acronym joke is a joke; the architecture is serious.

## What does PID 1 actually mean here?

The current standalone test executes a small project-owned Darwin program as the first userspace process. It is not Apple launchd, Finder or an application compatibility demonstration. [CP627](../research/2026-11/checkpoint-627.md) describes the ordinary boot evidence.

## Do I need a particular GPU?

No GPU support list is qualified yet. The design uses Linux-owned graphics services and targets a software-display path before hardware acceleration. A GPU vendor is independent of the CPU vendor. See the [post-kernel plan](post-kernel-platform.md); source presence is not a working driver.

## Can I download the research tools yet?

The two [public userspace tests](../tests/README.md) are available as source. CP638 confirms self-contained private source staging, but attribution, common pinned binary build and release approval remain open. See the [distribution plan](maintainers/distribution-plan.md).
