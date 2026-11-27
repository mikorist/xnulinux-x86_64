# 34. Typed startup and member callback adapters

**Date:** 2026-11-25
**Source checkpoint:** 55 (R0034)
**Scope:** Compile/IR evidence and synthetic callback fixtures, not kernel execution.

Three provider candidates were examined against the original startup dispatcher, lock registration, command-pool owner and CPU interrupt callback contracts. IORangeAllocator retained its existing lock declarations and startup ordering with correctly typed internal adapters. The actual startup records occupied 48 bytes with four relocations.

IOCommandPool and IOCPU were adapted to the concrete callback types already required by their consumers. Actual emitted IR and compiler layout evidence agreed with the intended virtual methods. The investigation explicitly retained the difference between resolving a virtual method at callback invocation and caching a legacy member pointer earlier. Object lifetime, dynamic type, teardown and concurrency were not established by compilation.

The independent native fixture used extracted emitted adapter bodies with synthetic objects and mock providers. Seven adapter calls passed with zero errors; no actual lock initialization, scheduler or interrupt delivery was performed. All three full units compiled without new global diagnostic demotions.

The three object sizes were 67,488, 258,848 and 405,040 bytes. There were now 99 separate verified probes and 968/984 configured artifacts. The accepted relocatable and its 261 undefined symbols remained unchanged.

Historical source-record SHA256: `2e3f4f03067b5a53378468b2756f74887aef1707f8be77678b0ff50a374958e1`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
