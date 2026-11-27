<!-- SPDX-License-Identifier: GPL-2.0-only -->
# Documentation

Start with [Getting started](getting-started.md) if you are new here. For current engineering status use the [root README](../README.md#current-status); for exact evidence use the [qualification matrix](qualification-matrix.md). The rest of this page also records the original repository separation and retained reference components.

The original ARM64 implementation is preserved in the [arm64-reference branch](https://github.com/mikorist/xnulinux-x86_64/tree/arm64-reference), pinned at `7ed7153bd34b4d906a0f02320efc774850d5a5b0`. Its [original README](https://github.com/mikorist/xnulinux-x86_64/blob/arm64-reference/README.md), documentation, graphics screenshots, build scripts, CI and source remain available there. The historical license notice about the screenshots refers to those archived files.

This cleanup retires the ARM-specific deployment path, DGX tools, ARM world-switch/entry code, in-tree ARM FKI driver, ARM CI, ARM test programs and the old macOS 27 patch series from the active x86_64 tree. They are not replacements for the x86_64 implementation. No supported x86_64 build or installation procedure is supplied by this cleanup.

## Platform scope

The project has evolved beyond an architecture port into development of a shared Intel/AMD PC-oriented XNU/Darwin compatibility platform. See [platform scope and evidence](platform-scope.md) for the intended layers, qualification boundaries and current reviewed results.

## Retained reference components

| Directory | Reason for retention |
| --- | --- |
| `fki-ko/`, `linux/include/linux/` | Existing interface and host-service sources for individual compatibility and license review; not the qualified Intel FKI. |
| `xnu-ko/` | Mach-O parsing, flattened device-tree and freestanding helpers; candidate reuse only. |
| `xnu-patches/` | Existing shared interface and crypto-provider reference sources; version-specific review required before reuse. |
| `kexts/` | Device and open provider code for later ABI review. |
| `gpu/` | Original Metal, Vulkan, Mesa, Venus and DRM code retained in full; no Intel, AMD or NVIDIA GPU support claim. |
| `scripts/`, `tools/`, `tests/` | Selected generic or potentially reusable tooling; inherited references to retired ARM scripts are historical and do not constitute supported instructions. |
| `LICENSE`, `LICENSES/` | Original licenses and attribution preserved. |

GPU acceleration is deferred until the shared x86_64 runtime reaches the required graphics interfaces. Retained graphics scripts may assume ARM64 or Apple Silicon; do not assume they apply to x86_64. The x86_64 source and tested build entry points will be integrated separately after review. See the [project README](../README.md) for the current research status.

## Current research: Intel reference and parallel AMD development

The current research snapshot is CP795; the last closed regular review is CP497. See the [project state manifest](../PROJECT-STATE.json) and [CP776-795 chronological research](../research/2026-11/updates-776-795/README.md). See [project navigation](project-navigation.md) and [chronological outcomes CP613-620](../research/2026-11/checkpoint-613-620.md). See the [qualification matrix](qualification-matrix.md), [CP599-612 report](../research/2026-11/hosted/commpage-reproduction-599-612.md) and [research journal](../research/README.md). The [Mach-O validator regression](../tests/hosted/monterey/mach-header-validator/README.md) is independently runnable in userspace.

## Developer documentation

### Start using the documentation

| Document | Purpose |
| --- | --- |
| [Getting started](getting-started.md) | macOS, Hackintosh, Linux and developer starting points |
| [FAQ](faq.md) | Project scope and common questions |
| [Hardware compatibility](hardware-compatibility.md) | Observed and target CPU environments |
| [Glossary](glossary.md) | Technical terminology |
| [Roadmap](roadmap.md) | Development stages and acceptance criteria |

### Understand the design

| Document | Purpose |
| --- | --- |
| [Platform scope](platform-scope.md) | Complete PC platform goal and reviewed evidence |
| [Architecture](architecture.md) | Target hosted execution model |
| [Version targets](version-targets.md) | Monterey, Tahoe and extensible target layout |
| [Subsystem reference](subsystems/README.md) | Boot, Mach, scheduler, IOKit, BSD and FKI |
| [Source map](source-map.md) | Pinned XNU source layout |
| [Architecture decisions](adr/README.md) | Accepted project decisions |

### Build, test and reproduce

| Document | Purpose |
| --- | --- |
| [Build reference](build.md) | Recorded toolchain and source revisions |
| [Dependencies](dependencies.md) | Provenance and publication gates |
| [Public tests](../tests/README.md) | Runnable userspace tests and scope |
| [Testing](testing.md) | Evidence classes and verification requirements |
| [Reproduction](reproduction.md) | Evidence and replay requirements |
| [Qualification matrix](qualification-matrix.md) | Confirmed results and remaining tests |

### Research and contribution

| Document | Purpose |
| --- | --- |
| [Research journal](../research/README.md) | Experimental results and limitations |
| [Kernel history](kernel-history.md) | Experimental images 1–25 |
| [Contributing](../CONTRIBUTING.md) | Contribution and review rules |
| [Maintainer handbook](maintainers/README.md) | Review, triage, publication and releases |
| [AI methodology](../AI-METHODOLOGY.md) | Parallel research and evidence policy |
| [Wiki plan](wiki-plan.md) | Proposed documentation navigation |

### Evidence and downloads

| Document | Purpose |
| --- | --- |
| [Evidence index](evidence/README.md) | Measured results and future real visual evidence |
| [Distribution plan](maintainers/distribution-plan.md) | Release stages, prerequisites and packaging rules |

These documents describe an experimental project. Supported installation instructions will be added only after the corresponding workflows have been verified.

[Project philosophy: XNU for the PC](project-philosophy.md)

For a first visit, use [Getting started](getting-started.md); for a quick explanation of unfamiliar terminology, use the [glossary](glossary.md). Historical research is kept at its original level of technical detail.

[Post-kernel platform reuse](post-kernel-platform.md): approved development direction, ARM reference inventory, GPU/device portability, open runtime, desktop/seamless backlog, licensing and qualification sequence.

---

<p align="center">
  <sub>Support the maintainer via the existing <a href="https://diyaudio.rs/">diyAudio.rs</a> donation button. Thank you!</sub>
</p>
<p align="center">
  <a href="https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&amp;hosted_button_id=AEXH39XRNHZQ2&amp;currency_code=EUR"><img src="https://img.shields.io/badge/PayPal-donate-0070BA?logo=paypal&amp;logoColor=white" alt="Donate via PayPal"></a>
</p>
