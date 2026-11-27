# 36. Statistics startup and NVRAM serializer evidence

**Date:** 2026-11-25
**Source checkpoint:** 57 (R0036)
**Scope:** Compile and IR evidence; mock serializer fixture.

IOStatistics retained four original sysctl registrations and the provider's mutation of OID state. Logging diagnostics were corrected locally, including the signed source-line format in three queue diagnostic macros. No queue integrity check or panic behavior was removed. Dependency and IR evidence confirmed the intended overlay and retained panic diagnostics. The object size was 383,264 bytes.

IONVRAM's existing tunable and serializer contract were audited against the original serializer implementation. A concrete adapter preserved the target and serializer arguments and returned the original boolean result. Two included firmware-handler sources received limited format corrections. An unused optimized argument was explicitly excluded from the fixture's claims. The actual extracted adapter passed true and false cases with two calls and zero errors. No firmware access, real locks or registry execution was performed. The object was 573,912 bytes.

Five startup entries retained their original ordering and two relocations each. The retained manifest verified 105 separate probes (974/984 configured artifacts). The 869-input accepted link and 261 undefined remained unchanged; ten handwritten targets were still missing.

Historical source-record SHA256: `0208eff2ed650a5329ca834696a2a3f23426cd4e67f71eec527d5805c929f8c0`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
