# From Intel assembly to a strict XNU executable

**Date:** 2026-11-25  
**Scope:** Linux-hosted compilation and offline Mach-O linking, not kernel execution.

## Toolchain

| Component | Recorded baseline |
| --- | --- |
| XNU | 8020.140.41 |
| LLVM | 24.0.0git, XNU builtin adaptations |
| Mach-O linker | cctools-port ld64-711 |
| MIG | bootstrap_cmds-122 |
| Configuration | RELEASE_X86_64 |

The initial stock Debian Clang/LLD attempt failed before a usable kernel build. Missing SDK and generation inputs and incompatible linker options were separate problems.

The research recovered the pinned cctools toolchain, verified XNU-specific Clang builtins, generated the Intel configuration and compiled actual Apple assembly sources. Fresh genassym output from Clang 19 and 24 matched byte-for-byte; older bootstrap offsets were not assumed interchangeable.

## Integration milestones

| Inputs | Undefined symbols | Scope |
| ---: | ---: | --- |
| 802 | 949 | Early relocatable provider integration |
| 984 | 43 | Diagnostic relocatable link |
| 988 | 34 | Original final-build providers |
| 988 | 19 | Corrected kernel-mode MIG generation |
| 988 | 18 | Bootstrap finalizer correction |
| 989 | 13 | Firehose provider integration |
| 993 | 0 | Strict executable link |

MIG generation had omitted a kernel preprocessing definition. Regeneration resolved 15 names without blind aliases; normalized generated source comparison and scalar ABI checks supported the correction, but did not establish live IPC ownership semantics.

The original version generation and final-link marker objects were retained. The bootstrap finalizer required explicit lifecycle and section-routing work. Firehose was built from pinned public Apple libdispatch source; historical LLVM profiling support was investigated separately.

## Limits

A strict executable is not a bootable production kernel. Conditional IOKit, generated RPC, runtime lifecycle and ABI gates remained. The full command manifests and source patches require publication review before a public reproduction recipe can be supplied.

**Source records:** checkpoints 23–28, 30–68; selected build milestones, not a complete translation of all intervening records.
