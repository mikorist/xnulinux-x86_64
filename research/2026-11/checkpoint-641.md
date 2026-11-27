# CP641: ARM post-kernel reuse and x86 desktop/GPU gap audit

**Outcome: PASS (read-only source inventory); platform implementation and license closure HOLD.** November 27, 2026.

Compared three clean public snapshots: upstream e0835348aedf89b95dbf3cc1f48a98f91ade89db, ARM reference 7ed7153bd34b4d906a0f02320efc774850d5a5b0 and x86 snapshot d8e448531e5a5ca4d44df5536767061db673fbf9. Counts are tracked entries; exact matches compare Git object identity and mode.

| Scope | ARM | Upstream | x86 | ARM/x86 exact |
| --- | ---: | ---: | ---: | ---: |
| GPU | 68 | 70 | 68 | 68 |
| Kexts | 45 | 45 | 45 | 45 |
| Tools | 18 | 18 | 8 | 8 |
| Scripts | 35 | 35 | 8 | 8 |
| FKI | 5 | 7 | 5 | 5 |
| Linux | 4 | 4 | 1 | 1 |
| XNU adapters | 9 | 9 | 5 | 5 |
| XNU patches | 34 | 41 | 26 | 26 |
| Tests | 3 | 3 | 10 | 1 |

The retained GPU/kext sources are reference material, not qualified x86 drivers. Current upstream changes include the Metal plugin, two new GPU patch/test files, and display and DRM changes. The optional virgl backend exists; upstream README and production documentation give different GPU status descriptions. No GPU result independently reproduced here.

A source-prefix SPDX inventory covers 49 GPU and 33 kext program-source files. All selected files carry markers, but transitive and combined-license closure is not established. No source imported, hardware accessed or program compiled. The CP602 kernel and ARM reference are unchanged.

The [post-kernel platform reuse plan](../../docs/post-kernel-platform.md) separates common host infrastructure, architecture/version-specific adapters and missing desktop/seamless/audio functionality. PureDarwin is a runtime candidate, not a qualified x86 runtime. Preserve existing hosted, Tahoe, security and distribution gates.

Primary evidence SHA-256: `0951ac3051d2925acd64e30275825cb292b77c79b4b4c3eb82ea09e2e24c2cf9`.
