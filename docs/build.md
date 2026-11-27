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

## Current retained build result (CP612)

Independent Intel/Ryzen builds reproduce the CP602 1,114-input unstripped executable byte-for-byte with zero undefined symbols. The retained canonical loader and fixture match across hosts. This uses retained inputs and is not an independently regenerated clean full-source build. CP605-610 trace patch lineage, all 44 generated dependencies and 27 inherited local headers. See [the build provenance report](../research/2026-11/hosted/commpage-reproduction-599-612.md).
