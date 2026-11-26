<!-- SPDX-License-Identifier: GPL-2.0-only -->
# Intel development tree

The original ARM64 implementation is preserved in the [arm64-reference branch](https://github.com/mikorist/xnulinux-x86_64/tree/arm64-reference), pinned at `7ed7153bd34b4d906a0f02320efc774850d5a5b0`. Its [original README](https://github.com/mikorist/xnulinux-x86_64/blob/arm64-reference/README.md), documentation, graphics screenshots, build scripts, CI and source remain available there. The historical license notice about the screenshots refers to those archived files.

This cleanup retires the ARM-specific deployment path, DGX tools, ARM world-switch/entry code, in-tree ARM FKI driver, ARM CI, ARM test programs and the old macOS 27 patch series from the active Intel tree. They are not replacements for the Intel implementation. No Intel build or installation procedure is supplied by this cleanup.

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

GPU acceleration is deferred until the Intel runtime reaches the required graphics interfaces. Retained graphics scripts may assume ARM64 or Apple Silicon; do not run them as Intel instructions. The Intel source and tested build entry points will be integrated separately after review. See the [project README](../README.md) for the current research status.
