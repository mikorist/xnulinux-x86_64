# Hosted calendar, entropy and owned PRNG service lifecycle

**Date:** 2026-11-26  
**Checkpoints:** 268–287

268 checked original Monterey calendar arithmetic in userspace with UBSan: 6,006 checks of offset, rounding and bounds. 269 fed actual FKI UTC/raw elapsed pairs into the source arithmetic. 270 retained a historical epoch-bound 64-byte anchor in private layout v2 (312 bytes), reconstructing the midpoint within 1 microsecond and rejecting invalid epoch/horizon. This is not a calibrated live Mach clock.

271 passed the real PE-consumed 64-byte seed through original bootseed_init_bootloader and BearSSL streaming SHA-256, compared with the independent Linux digest. Input and context cleanup were checked. 272 introduced purpose-separated fresh nonce/reseed records, actual 16-byte host nonce, v3 layout 328 bytes. 273 instantiated pinned NetBSD Hash_DRBG with actual derived seed and nonce; public KAT, canaries, duplicate initialization and state retirement passed. 274 checked a four-request diagnostic freshness budget, actual trusted reseed, inability of external mix to renew budget, atomic injected failure and stale session rejection. This is not a production entropy policy or native XNU registration.

275 qualified explicit BearSSL temporary/processed-block cleanup; does not establish absence of compiler spills or register residue. 276 executed the original refresh/chunk loop through private dispatch (8 chunks/1,500 bytes); injected partial staging failures committed neither state nor output. No native cckprng ABI claim. 277 transferred the runtime to exclusive owned serialized state, wiping source and rejecting resurrection. 278 tested two guest workers with 16 reads/1,024 bytes and four live refreshes. 279 exercised eight original UUID version-4 generation paths through the runtime; not running IOKit.

280–281 negotiated three private capabilities across version/limits and explicit session epoch; v4 boot layout 360 bytes, actual elapsed clock with 1:1 nanosecond units. 282 compared a live calendar observation with the retained anchor and independently classified synthetic discontinuity, expiration and backwards samples. No clock adjustment. 283 original fixed-point scaling passed 4,109 vectors, error at most 2 ns versus integer oracle on logical nanoseconds. No hardware tick calibration.

284 tested read/retirement ordering under a deliberately held runtime lock, actual reseed/read, worker join and final erasure; 28 committed calls. 285 confirmed independent epochs and rediscovery after slot reuse. 286 ran two complete client load/unload lifecycles on one live provider. 287 independently completed the same final source on both selected Liquorix kernels in QEMU TCG. Per target: eight allocations/frees, sixteen closes, zero active, two matching lifecycle marker groups, verified vermagic and ordinary import audits.

**Selected recorded SHA-256 evidence:**

| Manifest/result | Digest |
| --- | --- |
| Calendar arithmetic (268) | 362206617f370efd122878e80fe89990c3b13b0ed556f645523b04d90dbdcda1 |
| Digest integration (271) | e4b67be4bab0de8bdbd161eecdc822f0d7d0f6753f00546b832b7034ba6a7dcd |
| DRBG reseed (274) | 982b8bbcf0bb639eb0fe034a311c8aaee1d6dc6f95a5bcf21601399ec743e22a |
| Clock scaling (283) | de9cd7cef3be59077b687355275d2214652bd0877b23eeb51ebc866136e1d8fa |
| Two-kernel lifecycle (287) | f0ad7a1a1d5cdaacb4623e82a7715f4ca77ada398e893dae68e43db39d9cbea5 |

No secret outputs logged, native PRNG registration, production crypto certification, complete Mach hardware timebase or hosted XNU boot claimed. The next dependency is actual startup and owned CPU/thread context.
