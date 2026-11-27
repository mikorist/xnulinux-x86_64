# 31. Independent architecture version targets

**Date:** 2026-11-25
**Source checkpoint:** 52 (R0031)
**Scope:** Historical architecture decision; no new technical experiment.

The maintainer approved a separate version strategy on November 25. The x86_64 research would retain Monterey XNU 8020.140.41, pinned to 27b03b360a988dfd3dfdf34262bb0042026747cc, while the inherited ARM64 implementation would retain XNU 12377.121.6. Monterey 12.5 / Darwin 21.6.0 was the intended x86_64 userspace; the actual image and ABI were still unverified.

The decision required separate source pins, patches, configuration, generated headers, tools, build outputs and manifests. A common FKI contract was desirable only where semantics actually agreed. Versioned adapters would be required where the APIs diverged. The historical branch plan preserved main and ARM64 unchanged while x86_64-port remained the development lane. Later repository reorganization superseded that branch arrangement; the original decision is retained here.

No build was performed. The accepted relocatable still contained 869 inputs and 261 undefined names. The 89 separate C++ probes brought artifact coverage to 958/984, with 26 missing. All 17 generated IIG units compiled independently but had not been admitted to the accepted link. The next task was the knote layout and handwritten provider audit, not migration to Tahoe.

Related decision: [independent XNU versions](../../docs/adr/0001-independent-xnu-versions.md).

Historical source-record SHA256: `0f1f0008868332b0f08320394990012d2ec0782c73b6f12635d558295bdf3620`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
