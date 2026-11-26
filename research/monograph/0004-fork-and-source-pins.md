# 4. The public fork and source-version decision

**Date:** 2026-11-25  
**Source checkpoint:** 21 (R0004, recorded out of numerical order)  
**Scope:** Historical project organization, not a runtime experiment.

The [fork](https://github.com/mikorist/xnulinux) and [x86_64-port branch](https://github.com/mikorist/xnulinux/tree/x86_64-port) were established with initial commit `7ed7153bd34b4d906a0f02320efc774850d5a5b0`. The local fork and research archive were separate; origin pointed to the fork and upstream to AFK-surf/xnulinux. No executable source changes were recorded at this initial point.

The public [Issue #10 comment](https://github.com/AFK-surf/xnulinux/issues/10#issuecomment-7160958748) acknowledged parallel AI-assisted work, separate Intel integration, architecture-specific CPU state and the world switch. It explicitly did not claim a working kernel.

## Historical source-policy change

The original comment proposed moving subsequent builds to the upstream XNU 12377.121.6 pin. The later approved decision in checkpoint 52 superseded that requirement for Intel. The original comment remains a historical record; it is not silently rewritten in this monograph.

The independent Intel baseline is 8020.140.41; the upstream ARM64 path retains 12377.121.6. Intel source in the newer release does not establish hardware or userspace compatibility. Objects and generated headers from different pins are not interchangeable.

## Integration boundary

The main reference branch and original ARM64 implementation remain separate from x86_64-port. Reviewed changes should be transferred selectively, not by copying the entire research workspace. At this historical checkpoint no upstream PR had been opened.

See [ADR 0001](../../docs/adr/0001-independent-xnu-versions.md) and [contribution rules](../../CONTRIBUTING.md). The original comment is available at the linked public source instead of being duplicated in full.

**Subsequent repository decision (2026-11-26):** the fork was renamed to [xnulinux-x86_64](https://github.com/mikorist/xnulinux-x86_64); `arm64-reference` now preserves the original tree, while `main` and `x86_64-port` are Intel development branches. The statements above describe the original historical arrangement. See [repository history](../2026-11/history/intel-repository-separation.md).
