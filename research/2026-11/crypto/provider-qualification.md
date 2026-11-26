# Open-source PRNG and cryptographic provider research

**Date:** 2026-11-25  
**Scope:** Host tests and standalone diagnostic kernels.

The missing initialized PRNG blocked IOKit platform startup. The research rejected relying on a proprietary corecrypto snapshot for public distribution and investigated redistributable primitives.

| Candidate | Recorded role |
| --- | --- |
| BearSSL v0.6 | HMAC-DRBG tests; scalar AES and GHASH candidates |
| NetBSD netbsd-10 | Hash_DRBG primitive and restricted UP lifecycle integration |
| Mbed TLS v3.6.7 | Broad primitive and digest/HMAC candidate coverage |

BearSSL guest known-answer tests returned six successful checks. NetBSD guest tests returned 32 upstream scenario checks, with additional lifecycle tests. These primitive tests preceded registration and did not themselves demonstrate entropy quality.

A later restricted PRNG integration registered through the native XNU path. Full crypto ABI research continued separately: digest/HMAC checks, AES modes, GCM, legacy compatibility algorithms and remaining function adapters.

The diagnostic image eventually registered all 40 crypto table slots after a positive self-test. A separate deliberately corrupted public test fixture caused rejection before registration. Subsequent BSD domain initialization returned, advancing root discovery.

## Qualification limits

The registered diagnostic table is not production security qualification. Entropy and positive reseed behavior, concurrency, NMI/SMP, context ABI, error propagation, side-channel review and external KPI semantics remain relevant. No FIPS certification is claimed. Legacy algorithms are compatibility research, not modern security recommendations.

**Source records:** checkpoints 122–127 and 132–143; selected overview. Detailed per-provider reports and source/license review remain pending.
