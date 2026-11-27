# 40. Hibernate diagnostics and power-management adapters

**Date:** 2026-11-25
**Source checkpoint:** 61 (R0040)
**Scope:** Full compile, startup relocation and isolated forwarding tests.

Repeated diagnostics in IOHibernateIO were mapped to verified source positions: 81 unique format corrections from 211 repeated reports. IOServicePM received 14 mapped corrections and one separately checked signed elapsed-time format. Preparation failures caused by duplicate log text and whitespace assumptions were retained and corrected before the full builds.

Hibernate retained ten original sysctl entries and their 20 relocations. Entitlement checks, image and storage logic were not altered by these format/startup changes. No sleep, resume or disk I/O was tested.

Power management retained its tunable/sysctl records, request-target semantics and original queue/power policy. Concrete forwarding adapters were inspected in emitted IR. Fifteen mock calls passed with zero errors. One inlined completion path was inspected but not included in the native fixture; actual request scheduling, driver lifecycle and power transitions remained unqualified.

The two objects were 444,664 and 761,912 bytes. The separate probe count rose to 113, with 982/984 configured artifacts. Only IOPMrootDomain and IOUserServer remained. The earlier raw interrupt and IIG integration gates were still open, and the accepted 869-input link remained unchanged.

Historical source-record SHA256: `51dfa77dd5fbd6c2070d15557fb7cdfd97873ac3d7d475934280ee3535623cc9`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
