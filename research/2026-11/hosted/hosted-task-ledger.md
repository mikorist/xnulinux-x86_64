# Hosted task ownership and ledger research

November 26, 2026. Research checkpoints 338 through 357. Monterey XNU 8020.140.41, source commit `27b03b360a988dfd3dfdf34262bb0042026747cc`.

## What was tested

The private hosted component candidate now retains a task record across two cooperative Linux workers. Thread membership carries task references, a private map survives caller release, and exclusive dead-name metadata binding blocks premature retirement. The task constructor unwinds four injected failures and a genuinely occupied IPC owner. The private task registry uses source-backed identity and queue operations, and rejects active removal and stale identities. No native task or IPC space is published.

Original ledger append, instance initialization, credit/debit and key-lookup fragments run on bounded private storage. The release object identifies 50 direct task ledger registrations; the linked SFI metadata contributes ten distinct keys and six aliases across sixteen classes. The resulting 60-entry source-backed schema occupies 1,952 bytes, followed by two diagnostic entries. Template lifetime is reference-owned. The diagnostic elapsed samples are not CPU time; native ledger callbacks and resource policy are not executed.

Other tested fragments include release task reference initialization, root machine-task scalar fields, and 72 private task boot policy inputs with a simulated device-tree fallback. The xstate enum is diagnostic only; no FPU activation or hardware context switch is implied.

## Integrated regression

Same 227 input files; 78 required marker groups and 152 required marker occurrences per target. Two client cycles per isolated QEMU TCG Linux guest. Both providers retire eight allocations, eight frees and sixteen closes with zero active sessions. The APSL client import audit and per-target module build remain separate from the GPL provider.

| Linux kernel | Result | Serial log SHA-256 |
|---|---|---|
| `7.3.5-2-liquorix-amd64` | PASS | `0cf3beebda513ae3e2e5cc951edce09aadbc8f6fff852c43e938319be899b327` |
| `6.19.14-2-liquorix-amd64` | PASS | `d747fb2468a8f6f7a0d3240eaa824b8ee45076b89102646288ed202edb884015` |

Input manifest SHA-256: `ebafb95b9096456a20315bd02595d90c66fa38984b53ec59faed5e4090949c1b`.

A separate regeneration audit ran 33 extraction scripts and the startup coverage generator in a fresh directory. All 90 generated outputs matched the final retained candidate. This requires the pinned source and retained compiled reference objects; it is not a clean source-only toolchain rebuild.

## Corrections and limitations

An early extraction script omitted a previously applied static qualifier. It was corrected without changing the qualified compiled input. An IPC negative test initially used two equal addresses; the distinct-owner test was corrected and the failed guest log retained. An initial manifest preparation error occurred before compilation. The unused ledger callback constant was corrected to the pinned header value. The private ledger uses a retained immutable template and explicitly diagnostic accounting.

This update qualifies bounded components only. Native task construction, zone allocation, active pmap, real Mach ports and messages, native scheduler dispatch, the Intel execution-context transition and the remaining startup dependencies are still open. No physical module load was performed in this window. Full source publication remains held for file-level provenance, licensing and independently reproducible build review. The selected report does not constitute full individual-checkpoint publication.

Previous report: [Hosted bootstrap and replay](hosted-bootstrap-replay.md).
