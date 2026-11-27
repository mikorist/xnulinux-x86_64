# 44. Correct kernel-mode MIG generation

**Date:** 2026-11-25
**Source checkpoint:** 65 (R0044)
**Scope:** Regenerated servers, provider ABI comparison and diagnostic relink.

The earlier generated server provenance was traced to the original pinned MIG definitions and build flags. The recorded generation had omitted the kernel-mode define. Five server source/header pairs were regenerated with the original MIG122 environment and the corrected mode. The report retained the complete diffs: after normalization of timestamps and intended name changes, all ten files matched. This supported preservation of generated wire declarations and routine identities, but was not live IPC or rights validation.

Five server units and six original provider IR units compiled. The first comparison parser misread nested compiler attribute syntax; its corrected output compared all 15 declaration/definition argument shapes and return types. Opaque pointer shape did not prove ownership or pointee semantics.

Exactly five objects were replaced in the same 988-input order. The relocatable output was 19,291,012 bytes, SHA256 e9e15f8bafc1c0c773e3f09c5bc52968601db983150e263037ecd6ce4e300b1a. All 15 target names resolved without aliases or new undefineds, leaving 19. Critical section totals and preceding baselines were unchanged. Remaining work was layout, external Firehose and compiler runtime contracts.

Historical source-record SHA256: `0d250c544a0c9ef68a2868841e358bdb2af89c07a57fd45c0de9fa7e1a801235`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
