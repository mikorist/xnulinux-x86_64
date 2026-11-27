# Project philosophy

**Adapt XNU to the PC, not the PC to the Mac.**

The long-term goal of XNULINUX is to eliminate the need for traditional Hackintosh setups by leveraging the existing Linux hardware infrastructure and bringing XNU to standard x86_64 PC hardware.

Rather than making a PC pretend to be a Mac, we aim to make XNU work with the PC as it is.

PC is the project identity and x86_64 is the target architecture. Intel and AMD Ryzen development now proceeds in parallel, with Intel as the established reference lane. The goal is broad compatibility with standard Linux PCs, not a restriction to one CPU vendor. Scoped native AMD KVM component replay is qualified at CP460; complete AMD XNU boot and hosted application execution remain unqualified. Native vendor-aware XNU adaptation is one option; a narrowly scoped XNU-facing CPU compatibility layer is another. The implementation will be selected by measured compatibility, correctness and maintainability, while preserving actual host capabilities and Linux ownership. No unsupported CPU instructions or features may be advertised. Linux remains responsible for physical hardware and host resources; the project aims to reuse that infrastructure rather than require Mac hardware emulation. This is an independent, experimental open-source project and is not affiliated with Apple Inc.

See the [target architecture](architecture.md), [hardware qualification](hardware-compatibility.md) and [roadmap](roadmap.md). The goal is not a claim of current PC-wide compatibility, a completed hosted boot, or permission to distribute proprietary macOS components.

The intended platform includes both Intel and AMD x86_64 Linux PCs through a shared implementation and hardware-aware selection, not two independent products. The scope extends from processor discovery and machine-layer semantics through Linux resource ownership and Darwin runtime integration to three application modes. Kernel boot is one milestone within this platform. See [platform scope and evidence](platform-scope.md). See the [cross-vendor test strategy](testing.md#planned-cross-vendor-x86_64-test-strategy).

The same principle applies to XNU versions: adding Tahoe or a later target should extend the platform without discarding Monterey. Share validated infrastructure, not assumed ABI compatibility. See [version targets](version-targets.md).

## A note about the name

GNU's Not Unix. XNU's Not Unix. XNU is not Linux. XNULINUX is what we call the attempt to make two very different kernels cooperate. Linux remains Linux, XNU remains XNU, and nobody has to win an operating-system argument for the project to work.
