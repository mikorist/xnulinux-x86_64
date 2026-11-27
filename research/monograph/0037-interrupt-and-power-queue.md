# 37. Interrupt event-source and power queue callback contracts

**Date:** 2026-11-25
**Source checkpoint:** 58 (R0037)
**Scope:** Typed adapter compile evidence; conditional end-to-end interrupt path.

IOInterruptEventSource's concrete action and registration callback contracts were reviewed against the actual emitted IR. Two typed forwarding adapters retained the original virtual methods, while pointer storage was separated from invocation. The change still required object-identity and teardown review. The existing IOService/controller registration contract remained unresolved, so this was not end-to-end interrupt qualification.

The power queue consumer was compiled with its actual typed argument contract. An initial compile failed because a helper was unused; the retained second attempt removed it. A matching root-domain producer candidate was prepared but still failed on 172 diagnostics, down from 175, and was not counted as a compiled object.

The isolated fixtures recorded interrupt_dispatch_score=11, storage_tests=6 and zero errors. They used synthetic objects and checked widths, identity and null behavior, not actual interrupts or power policy. The two full object sizes were 283,264 and 116,792 bytes.

Coverage reached 976/984 with 107 probes and eight missing targets. The accepted baseline remained unchanged. The raw controller ABI and virtual registration contract were explicitly carried forward rather than treated as repaired.

Historical source-record SHA256: `6fe9c62da001dc5106f9b35d6d51acbbe1d90b1e7461ea70f10abc9879dbec78`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
