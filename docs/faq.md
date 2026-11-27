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

CP700 reproduces the exact CP602 executable with 95 regenerated and 1,019 retained inputs. CP745-747 establish scoped dual-host compiler and Blocks compile/link regressions; CP754 reaches 249 staged SDK headers. CP755 reproduces an instrumented object from one shared preprocessed input and passes 229 native checks per host; independent preprocessing and final binaries still differ. CP627 remains the ordinary Intel-model owned PID 1 boot result. Complete AMD boot, physical hosted XNU, clean-source build, full SDK/runtime, graphics and release remain HOLD. See [CP643-755 research update](../research/2026-11/updates-643-755/README.md) and [qualification matrix](qualification-matrix.md).

## Is Tahoe replacing Monterey?

No. Monterey remains the active baseline. Tahoe is an active development target in preparation; implementation requires stable physical Linux-hosted Monterey Intel execution. Both targets are intended to share qualified platform infrastructure and retain version-matched runtimes. Golden Gate is a separate [research-only feasibility target](golden-gate-research.md). See [version targets](version-targets.md).

## Does a PASS mean my machine is supported?

Only if the documented test actually covers your configuration and the feature you are asking about. A build on Ryzen, a Broadwell TCG guest on Ryzen, and native Ryzen execution are three different things. See [hardware evidence](hardware-compatibility.md). A green checkmark cannot do the work of a driver.

## Is this GNU/Linux with a different kernel?

No. GNU/Linux refers to a system using Linux and GNU components. XNU is a separate kernel. The project aims to host XNU on Linux, without replacing the Linux host or requiring a particular GNU userland. The recursive-acronym joke is a joke; the architecture is serious.

## What does PID 1 actually mean here?

The current standalone test executes a small project-owned Darwin program as the first userspace process. It is not Apple launchd, Finder or an application compatibility demonstration. [CP627](../research/2026-11/checkpoint-627.md) describes the ordinary boot evidence.

## Do I need a particular GPU?

No GPU support list is qualified yet. The design uses Linux-owned graphics services and targets a software-display path before hardware acceleration. A GPU vendor is independent of the CPU vendor. See the [post-kernel plan](post-kernel-platform.md); source presence is not a working driver.

## Can I download the research tools yet?

The two [public userspace tests](../tests/README.md) are available as source. CP742 and CP744 reproduce separate private source-only packages; CP755 matches shared-input objects but not final binaries. No package or release has been published. See the [distribution plan](maintainers/distribution-plan.md).

CP642 independently checks the retained framebuffer-to-PNG helper using owned synthetic buffers. It is not a working x86 display driver or GPU demonstration.

Latest evidence: CP776-795: independent source regeneration and two local batch runs increased accepted regenerated inputs from 121 to 599 of 1,114; 515 remain retained. Both complete retained-input links match CP602. Shared generated-header blockers were resolved for selected groups; unresolved recipes and dependencies remain HOLD. No new boot, full clean-source build, runtime, licensing or release qualification. [CP776-795](../research/2026-11/updates-776-795/README.md).
