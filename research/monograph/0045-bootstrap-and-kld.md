# 45. Bootstrap lifecycle and original KLD routing

**Date:** 2026-11-25
**Source checkpoint:** 66 (R0045)
**Scope:** Isolated lifecycle fixture and section-aware diagnostic relink.

The original libsa bootstrap constructor publishes two startup function pointers and the destructor clears them. The original unload lifecycle and section-routing rules were inspected. Two compiler flag experiments still emitted destructor-registration dependencies and were rejected rather than linked.

An isolated explicit finalizer candidate retained the original destructor semantics. The emitted constructor/finalizer records and original libsa routing were verified; three mock lifecycle cases confirmed initial null state, publication of both pointers and clearing. No actual segment reclamation, concurrent access, runtime iteration or exactly-once unload behavior was established. Those remained conditional integration gates.

Replacing only the bootstrap object in the 988-input diagnostic link reduced 19 undefined names to 18, resolving the destructor registration dependency without adding a dummy implementation. The 19,280,227-byte result had SHA256 cd65955b5f6496834abb4828097b5079937165c622bdc97ef0d00101714d2478. The earlier baselines were unchanged.

Review of ld64 source identified the image-identity symbol as linker-owned for executable output. Eleven layout/image symbols, five Firehose and two profiling symbols remained. The required historical external sources had not yet been located in the local research tree.

Historical source-record SHA256: `bb2db2ca3a14f5238cbc2ebe8fe29dc360f34df7ed581d05588dfb0a5a2acdf7`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
