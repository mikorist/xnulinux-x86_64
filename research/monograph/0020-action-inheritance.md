# 20. One-way action dispatch and inheritance

**Date:** 2026-11-25  
**Source checkpoint:** 41 (R0020)  
**Scope:** OSAction and IODataQueueDispatchSource prototype compilation and fixtures.

The pinned OSAction Aborted and IODataQueueDispatchSource DataAvailable/DataServiced paths are one-way methods. The transport allocates no reply for one-way calls; the prototype preserved that behavior, checked the one-way flag and left unused reply storage untouched. Synchronous methods retained bounded replies.

The adapter measured 22 wire layouts, added 66 assertions and replaced nine generated member-function union casts with typed thunks. Derived dispatch retained inherited invokers, forwarding and metadata-dependent checks.

## Correction to the method-ID policy

The pinned IOUserServer target path rewrites the method ID and target object for action routing. A fixed original callback ID in shared DataAvailable/DataServiced invokers would reject legitimate redirected actions. Only those shared invokers were exempted from the fixed-ID check; structural and action-class checks remained, and concrete dispatch still selects the method.

The initial stricter prototype was retained. The corrected IODataQueueDispatchSource object superseded it.

| Final object | Bytes | SHA-256 |
| --- | ---: | --- |
| OSAction.iig.cpo | 64984 | `672177fdcaff011e30a0ebee44fac27cd6a887a7f256e403231a25d621bcffc0` |
| IODataQueueDispatchSource.iig.cpo | 158312 | `7b30af1e75d112f3975d44b404a6cdd818ca39f0d3941da8f9a6ac734bd241c1` |

Actual extracted Aborted and CopyMemory invokers passed 20 and 24 host checks respectively. These covered no-reply semantics, aligned output identities, overlap and negative structural cases. The redirected ready callbacks were not executed against live objects.

Whole-TU LLVM IR confirmed inherited SetEnableWithCompletion, Cancel and CheckForWork invoker calls and default base dispatch. The real CheckForWork implementation returns NotReady; no interrupt result was fabricated.

The probe count was 71, with five generated implementations compiled. Total artifact coverage 940/984; 44 missing. The unchanged 869-input accepted link retained 261 undefined. No live vtable or remote transport proof; the special base reply-reuse boundary remained open.
