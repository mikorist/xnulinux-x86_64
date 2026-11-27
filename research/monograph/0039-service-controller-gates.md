# 39. IOService and controller conditional integration gates

**Date:** 2026-11-25
**Source checkpoint:** 60 (R0039)
**Scope:** Conditional compile probes; unresolved legacy callback ABI.

The original registry traversal and synchronous gate contracts were inspected. An initial preparation assertion exposed an ambiguous overload; it was corrected before compilation. IOService then compiled with concrete registry, client and termination adapters. Existing termination policy and startup registrations were retained. The stack-context approach depended on synchronous traversal; external overrides and lifetime behavior remained unverified.

The controller candidate preserved its public virtual handler method. The shared handler adapter called the intended original virtual method and preserved the public void result contract. However, the original raw controller invocation still involved incompatible callback types. The local compatibility treatment was explicitly conditional and did not establish C++ correctness or an end-to-end hardware interrupt path. Pointer representation alone was not accepted as an ABI proof.

The mock fixture recorded two appliers, seven termination calls and one shared callback with zero errors; it did not execute the unresolved raw call. Both full objects compiled (923,528 and 252,136 bytes), but were marked conditional.

The 111 probes brought coverage to 980/984. Four targets remained. Neither the accepted link nor the 261 undefined count changed.

Historical source-record SHA256: `1390082f9d2d82eafa131f970eb52fb374717f78b042e801bf521bdeadc068e6`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
