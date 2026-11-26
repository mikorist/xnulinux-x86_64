# Diagnostic crypto registration checkpoint

**Date:** 2026-11-25  
**Scope:** Standalone Legacy UP diagnostic image, checkpoints 141–143.

The final functional-candidate image tested all 40 table fields without registering them. A later image registered the complete table only after the diagnostic self-test succeeded.

| Observation | Result |
| --- | --- |
| Strict link | 1,049 inputs, zero undefined |
| Positive POST | 1,558 checks |
| Registered table slots | 40, verified live |
| Wrapper checks | 6 |
| Negative POST | Rejected before registration |
| Read-only lockdown | 136 pages verified |
| BSD domain initialization | Natural return |

The negative test modified a public expected test value in an isolated diagnostic run. It demonstrated rejection, not a cryptographic attack or entropy-strength test.

Kernel SHA-256: `3b99bd41637f53fc3af8d0edc036e973e7b8e0282f933449f5e7f980cc9bf3e2`.

No production cryptographic certification is claimed. RSA ABI coverage, serialized ChaCha context semantics, entropy/reseed behavior, caller error handling and timing/concurrency qualification remain open.
