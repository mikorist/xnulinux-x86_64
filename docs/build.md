# Developer build reference

> [!WARNING]
> This documents the research build chain, not an available end-user installer. A complete public kernel source/build and reproduction bundle has not yet been assembled. The [independent metadata regression](../tests/hosted/monterey/mach-header-validator/README.md) is runnable separately.

## Recorded inputs

| Component | Revision |
| --- | --- |
| [Apple XNU](https://github.com/apple-oss-distributions/xnu) | 8020.140.41 / `27b03b360a988dfd3dfdf34262bb0042026747cc` |
| LLVM | `58c46bae21181fb4240cf964461bea738d96d50e` |
| UniXNU builtin patch reference (repository URL not verified) | `8542980d02b4d2cc5c32ee3542de1760b2562aac` |
| [cctools-port](https://github.com/tpoechtrager/cctools-port) | `e101a6940dcb5988808a16626bc43851f00dc05f` |
| [bootstrap_cmds](https://github.com/markmentovai/bootstrap_cmds) | `3cc6b1cf291f8fccfbf6444d6630a02a54c16831` |

The development host recorded Debian 13 and system Clang 19.1.7. These are observations, not minimum supported requirements.

## Build sequence

1. Validate source revisions and the applied XNU builtin patch.
2. Build Clang with the X86 backend and resource headers.
3. Verify XNU builtins with the existing C++ compile probe.
4. Generate RELEASE_X86_64 configuration and kernel-mode MIG sources.
5. Compile actual C, C++ and assembly inputs using recorded recipes.
6. Audit object architecture, hashes, symbol providers and section layout.
7. Perform strict executable linking and independent static validation.

The existing local toolchain scripts are named `build-xnu-clang-x86_64.sh` and `verify-xnu-clang-builtins.sh`. The latter checks builtin availability and produces an x86_64 Mach-O probe object. They are not yet shipped in the public repository.

The strict-link result and remaining gates are covered in the [build research](../research/2026-11/toolchain/build-and-link.md). Do not substitute a generic ELF linker or mix generated artifacts across XNU versions.

## Retained build result through CP629

Independent Intel/Ryzen builds reproduce the CP602 1,114-input unstripped executable byte-for-byte with zero undefined symbols. The retained canonical loader and fixture match across hosts. This uses retained inputs and is not an independently regenerated clean full-source build. CP605-610 trace patch lineage, all 44 generated dependencies and 27 inherited local headers. See [the build provenance report](../research/2026-11/hosted/commpage-reproduction-599-612.md).

CP616-617 independently recompiled three retained source units and relinked the exact CP602 image with 1,111 retained objects. CP618-620 verified compiler inputs, regenerated both link metadata inputs and compared the complete input lineage against CP444: 1,069 byte matches and 45 unmatched current objects. A clean source-only build and full licensing review remain HOLD. See [CP613-620](../research/2026-11/checkpoint-613-620.md).

## Versioned build identity

The [Monterey descriptor](../targets/monterey/target.json) records the retained source pin, toolchain identity and four CP626/627 artifacts. CP629 validates identity offline on both hosts and rejects nine negative controls each. It is not a generic build recipe. Tahoe is in active preparation, with build and implementation gates unchanged; use separate version-specific inputs and qualify build orchestration before advertising it. See [version targets](version-targets.md).

## Retained-input boundary through CP855

CP639 independently regenerates 28 of the 1,114 link inputs across both hosts, with the remaining 1,086 retained; the exact CP602 executable is reproduced. CP640 compares 25 utility units and 186 directly pinned source dependencies against Tahoe; only three units have all directly pinned dependencies identical, and all 25 also depend on generated/exported/toolchain inputs. Neither result establishes a full clean-source build or Tahoe compilation. See [CP639](../research/2026-11/checkpoint-639.md) and [CP640](../research/2026-11/checkpoint-640.md).

CP700 reproduces the exact CP602 executable with 95 regenerated and 1,019 retained inputs. CP745-747 establish scoped dual-host compiler and Blocks compile/link regressions; CP754 reaches 249 staged SDK headers. CP755 reproduces an instrumented object from one shared preprocessed input and passes 229 native checks per host; independent preprocessing and final binaries still differ. These are distinct build and declaration results. The complete clean-source build and source clearance remain HOLD; see [CP643-755 research update](../research/2026-11/updates-643-755/README.md) and the [versioned SDK direction](../research/2026-11/updates-643-755/sdk-direction.md).

Latest evidence: CP836-855: accepted regenerated inputs increased from 764 to 839 of 1,114; 275 remain retained. Historical IIG declarations and compatibility-header prerequisites are qualified within their tested scope, and all 64 CP811 original C++ candidates now match. Final build metadata and additional BSD objects also match. Complete retained-input links match CP602 on both hosts. No new boot, full clean-source build, runtime, licensing or release qualification. [Research update](../research/2026-11/updates-836-855/README.md).
