# 22. Service and state notification families

**Date:** 2026-11-25  
**Source checkpoint:** 43 (R0022)  
**Scope:** Generated notification dispatch compilation and host fixtures.

Both notification classes derive from IODispatchSource. Ready callbacks are TARGET LOCAL callbacks, not ordinary instance switch cases. Service notification overrides CheckForWork (the pinned implementation returns NotReady); state notification does not.

The adapter preserved redirected IDs, action-class checks, inherited dispatch and one-way semantics. Sixteen measured layouts and 48 assertions covered both families, with aligned scalar and typed object results and initialized port descriptors.

| Object | Bytes | SHA-256 |
| --- | ---: | --- |
| IOServiceNotificationDispatchSource.iig.cpo | 213152 | `3067baa2d51c5bf04e439fbb9f56f191e5dd808d4dd1000f34d163f0c302e749` |
| IOServiceStateNotificationDispatchSource.iig.cpo | 212312 | `cd2de372df42e248f50605c202ee9b42a302525899d4f10d92587ca403c03f6f` |

Both compiled on the existing recipes with no new warning demotions.

The extracted CopyNextNotification and StateNotificationBegin invokers passed 22 and 16 checks respectively. Request/reply sizes were 84/100 and 84/60 bytes. Fixtures checked full-width scalar values, opaque output identity, both alignment positions, overlap, NotReady leaving output unchanged and rejection of invalid synchronous calls.

Full-TU IR showed three inherited invoker/derived-handler pairs for the service class, two for the state class and correct default base dispatch for both. Ready callbacks were compiled but not executed with live metadata.

The manifest reached 75 probes, nine of 17 generated implementations, 944/984 total artifacts and 40 missing. The 869 accepted inputs and 261 undefined remained unchanged. No live notification delivery, metadata, remote transport or boot proof.
