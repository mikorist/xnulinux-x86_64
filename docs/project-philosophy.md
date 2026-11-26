# Project philosophy

**Adapt XNU to the PC, not the PC to the Mac.**

The long-term goal of XNULINUX is to eliminate the need for traditional Hackintosh setups by leveraging the existing Linux hardware infrastructure and bringing XNU to standard x86_64 PC hardware.

Rather than making a PC pretend to be a Mac, we aim to make XNU work with the PC as it is.

PC is the project identity, x86_64 is the target architecture, and Intel is the current implementation and qualification target. AMD support is not currently claimed. Linux remains responsible for physical hardware and host resources; the project aims to reuse that infrastructure rather than require Mac hardware emulation. This is an independent, experimental open-source project and is not affiliated with Apple Inc.

See the [target architecture](architecture.md), [hardware qualification](hardware-compatibility.md) and [roadmap](roadmap.md). The goal is not a claim of current PC-wide compatibility, a completed hosted boot, or permission to distribute proprietary macOS components.
