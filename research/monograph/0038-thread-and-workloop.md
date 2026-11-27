# 38. Thread-start and workloop continuation contracts

**Date:** 2026-11-25
**Source checkpoint:** 59 (R0038)
**Scope:** Compile/IR plus mocked allocation, thread and callback tests.

IOLib retained four original memory-range startup registrations, with the same eight relocations. Its one-argument public thread callback and the kernel continuation contract required an explicit context lifetime. The candidate introduced an owned start context, with allocation/start failure handling and transfer to the successful thread. The new allocation was a behavioral/resource change, not a purely mechanical compile fix; allocator readiness, cancellation and the case where a successful thread never enters its continuation remained open.

IOWorkLoop retained its gate, continuation and callback identity behavior within the recorded scope. Actual emitted IR corroborated the intended concrete signatures and original identity comparisons. The investigation noted the virtual lookup timing caveat and did not qualify real scheduler execution, precious-stack reclamation or lock behavior.

The extracted IR was exercised against mock allocator/scheduler providers and synthetic virtual tables: four thread cases, three workloop adapter calls and five identity cases, all with zero errors. Both full units compiled, with sizes 298,040 and 265,984 bytes.

There were 109 separate probes and 978/984 configured artifacts. Six targets remained. The accepted baseline was still 869 inputs and 261 undefined.

Historical source-record SHA256: `143d8fdb8b9543a9ec8374c4e9dacb3af089dc2b8d4e2df839cfb6e1c3fd2c19`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
