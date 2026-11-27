# 46. External Firehose and historical profiling providers

**Date:** 2026-11-25
**Source checkpoint:** 67 (R0046)
**Scope:** Source provenance, reference fixtures and diagnostic link closure.

The official Apple libdispatch-1324.41.2 source was retrieved at commit 55c3a68e9ec47f1c1d5bb9909404ce5f0351edef. The independently retrieved Firehose source matched the archive and the original build target identified it as the actual kernel provider. Its object supplied the five missing names with dependencies already present. The 989-input diagnostic link reduced 18 unresolved names to 13; actual log transport and concurrency were not tested.

Historical Swift LLVM profiling sources were then examined against the pinned XNU call ABI. The historical raw format was version 5, not the current local Clang24 version 11. The exact Apple compiler runtime archive was unavailable. A scoped real-source candidate preserved the relevant historical algorithms and was compared with an unmodified native reference. Five cases matched, including sizes, header/data copying, padding and a trailing canary. This was not real kext profiling or complete official archive reconstruction.

Four profiling objects brought the diagnostic link to 993 inputs and eleven unresolved linker-owned names. The 19,302,803-byte result had SHA256 6efe317e7fc6d8c63ba333350cec8c5e74ec00190cdf1fb56abaaaf9e18ee112. No runtime or production qualification was claimed.

Historical source-record SHA256: `bae9b2fcd72379d082ccd0b35e2652e566845733ccbf891c6225c4e6a5c0fbe5`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
