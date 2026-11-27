# 35. Typed startup, timer storage and filter block lifecycle

**Date:** 2026-11-25
**Source checkpoint:** 56 (R0035)
**Scope:** Full compile and IR inspection; isolated storage and allocation-failure tests.

Four configured units were compiled. Tests and IOKitDebug preserved existing sysctl and tunable registrations, with typed startup adapters. Five registrations retained their original subsystem/rank and two pointer relocations each. No live sysctl or boot-argument execution was claimed.

IOTimerEventSource preserved the original separate block and ordinary action paths. The emitted ordinary call retained its concrete type, and a native storage fixture passed three checks. No timer delivery or actual block runtime was exercised.

The filter event-source review revealed an existing allocation-failure defect in the factory. The initial successful compile and its artifacts were preserved; a revised isolated candidate added a null-allocation guard. Four fixture cases covered allocation failure, copy failure, initialization failure and successful tagging/release using mocked dependencies. No real interrupt delivery or ownership/concurrency qualification followed. In particular, a pre-existing registration-before-filter-publication window remained a separate integration concern.

All four units and their IR compiled. The final filter object was 278,616 bytes with SHA256 51acd0d8663379df648e5989f9083b98b5610142fdea5c5a4d151d946933e298. Coverage reached 972/984 with 103 probes. The accepted baseline remained at 869 inputs and 261 undefined.

Historical source-record SHA256: `3af5daca75eab6cae19b357aa3e57903f1abb6d0b148c54410db2fbfd1412dbd`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
