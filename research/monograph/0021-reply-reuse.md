# 21. Local CheckForWork and InterruptOccurred reply reuse

**Date:** 2026-11-25  
**Source checkpoint:** 42 (R0021)  
**Scope:** Local callback wire adaptation; remote INVOKEREPLY remains unresolved.

The pinned CheckForWork implementation produces a callback in reply storage only when both event and action exist; otherwise it returns NotReady. The modern generator's separate kernelContent assumption and reply-to-request transition did not match the Monterey four-field contract.

The local prototype validates returned callback structure, actual extent, one-way flag and object-reference presence, then constructs an independent four-field IORPC for the callback. It does not silently convert protocol versions or transfer ownership. The remote path expects ordinary reply version and original method ID, so this local fixture is not a remote protocol fix.

Sixteen original layouts were measured and 48 assertions retained. CheckForWork request/reply nominal size/offsets were 92/52 and 124/36; InterruptOccurred 124/68 and 60/36, alignment four. The adapter kept typed thunks, action routing and validated bool representation.

| Object | Bytes | SHA-256 |
| --- | ---: | --- |
| IOInterruptDispatchSource.iig.cpo | 212672 | `1bf4b378385fee278f895018c9610a290d2b240bf21aa0dda0bcc9a4b809e847` |
| IODispatchSource.iig.cpo | 73408 | `0b07ac41a781ac60bea2c13891250d083ef7df88e405c4df13aad4faa58065c4` |

The first IODispatchSource compile failed on an unused local after adaptation. Removing that local, without suppressing ABI diagnostics, produced the recorded successful object.

The actual extracted CheckForWork invoker and producer body passed 54 host checks. The fixture tested both alignment positions, overlapping storage, actual 124-byte callback length versus larger capacity, NotReady propagation and malformed returned work. The producer body was extracted without fabricating a live XNU object; live action metadata and dispatch were not exercised.

The 73-probe manifest now included seven generated implementations, both formerly deferred units. Total artifact coverage 942/984, 42 missing. The accepted 869-input link remained unchanged; 261 undefined. Local fixtures did not establish actual IRQ delivery, remote Mach transport or boot.
