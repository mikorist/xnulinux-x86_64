# Welcome to XNULINUX

**Adapt XNU to the PC, not the PC to the Mac.**

GNU's Not Unix. XNU's Not Unix. XNU is not Linux. Hence XNULINUX. The last distinction matters here: Linux is the host, XNU is a different kernel, and XNULINUX is the project that aims to make them cooperate.

This is an independent open-source research project. You can follow the research, read the code already published and run small public tests. You cannot install a supported macOS application environment from this repository today.

## Coming from macOS

Think of XNU as the kernel underneath Darwin and macOS, rather than the entire operating system. Finder, WindowServer, application frameworks and your .app bundles are separate layers. The project aims to bring compatible Darwin software and, eventually, graphical macOS applications to Linux.

The three planned modes are headless (command-line software and services), desktop (a compatible graphical environment), and seamless (individual macOS windows alongside Linux applications). None is a supported product today. Monterey is the active kernel target; Tahoe is the next planned version target. Neither the Apple frameworks nor a proprietary macOS installation is included.

Start with the [FAQ](faq.md), [three-mode architecture](architecture.md) and [current status](../README.md#current-status).

## Coming from Hackintosh

You already know that booting a kernel and having a usable desktop are different achievements. Here the idea is different: leave Linux responsible for PC hardware and adapt XNU to work through a defined host interface. The intended product is not a replacement OpenCore EFI, a new SMBIOS configuration, or a conventional macOS installation.

Intel and AMD are development targets. A Ryzen build host and a Milan TCG guest are not evidence that a full AMD XNU boot works. Likewise, the presence of a GPU driver directory is not a compatibility guarantee.

If your EFI folder has its own family tree, you have probably come to the right research project. Leave it where it is. There is nothing to install over it today.

Read [hardware compatibility](hardware-compatibility.md), [version targets](version-targets.md) and [project philosophy](project-philosophy.md).

## Coming from Linux

Keep your distribution, package manager, shell and GNU userland (if that is what you use). Linux remains in charge of the physical machine. Nobody is proposing to replace your init system with Finder.

The proposed Foreign Kernel Interface (FKI) connects hosted XNU to Linux services. The intended product does not require a conventional macOS virtual machine. QEMU and KVM are used for isolated development and regression, and a QEMU standalone result must never be called native Linux-hosted execution.

Current focused Linux component regression uses two exact kernel versions; this is not a minimum supported version or a promise for every distribution. No unqualified kernel module should be loaded on a machine you rely on.

Start with [platform scope](platform-scope.md), [host interface](subsystems/host-interface.md), [testing](testing.md) and [hardware evidence](hardware-compatibility.md).

## For developers and testers

You do not need to be a kernel maintainer to contribute. A broken link, an incorrect assumption, a small reproducible test, or a useful failure report is a legitimate contribution. Tell us what happened, not what ought to have happened.

Read the [source map](source-map.md), [build reference](build.md), [contribution guide](../CONTRIBUTING.md) and [current qualification matrix](qualification-matrix.md). The [research journal](../research/README.md) is the detailed history; the [state manifest](../PROJECT-STATE.json) is the short current snapshot. The [glossary](glossary.md) translates the local alphabet soup.

## What you can run today

The following are documented public userspace component tests, not kernel builds or macOS installers. Run them on a suitable Linux development system from a checkout of this repository. No root, kernel module insertion or proprietary Apple image is needed.

Start with a local checkout, as an ordinary user:

```sh
git clone https://github.com/mikorist/xnulinux-x86_64.git
cd xnulinux-x86_64
```

These commands obtain the public research tree; they do not install XNU. The synthetic Mach-O metadata test requires GCC with C11 and UBSan support:

```sh
CC=gcc sh tests/hosted/monterey/mach-header-validator/run.sh
```

See its [README](../tests/hosted/monterey/mach-header-validator/README.md) for the expected scope and original result.

The replay verifier's synthetic unit tests require Python 3. From the repository root:

```sh
cd tests/hosted/monterey/replay-verifier
python3 -B -m unittest -v test_replay_verify.py
```

See the [verifier README](../tests/hosted/monterey/replay-verifier/README.md). A successful run validates evidence handling, not a running XNU kernel. Native macOS execution of these test commands has not been qualified here.

## Before asking whether it works on your PC

Check the [current status](../README.md#current-status) and [hardware evidence](hardware-compatibility.md). Report the exact CPU, version target, host Linux kernel and execution environment if you have a genuine test result. If a result is missing, it means unknown, not supported and not necessarily impossible.

There is no public installable x86_64 release or complete clean-source build recipe yet. When those exist, this is where the verified instructions belong. Until then, leave the production machine alone. A research repository is not an installation procedure.

[Back to the project](../README.md) | [FAQ](faq.md) | [Developer documentation](README.md) | [Evidence](evidence/README.md)

For the planned sequence of downloadable research tools and later runtime distributions, see [distribution plan](maintainers/distribution-plan.md). The plan is not a download or installer.
