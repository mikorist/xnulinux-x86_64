# CP631: Tahoe source and build-input inventory

**Outcome: PASS (source preparation only).** November 27, 2026.

The Ryzen workspace verifies six public Apple XNU 12377 tags (12377.1.9, 12377.41.6, 12377.61.12, 12377.81.4, 12377.101.15 and 12377.121.6). The highest numerical tag observed is retained as the proposed research reference: xnu-12377.121.6, commit ac9718fb1af618d5ce8678d0dc6e8a58f252216f. Both source checkouts are clean.

| Tracked scope | Monterey | Tahoe | Common paths | Identical |
| --- | ---: | ---: | ---: | ---: |
| EXTERNAL_HEADERS files | 94 | 148 | 93 | 38 |
| config files, recursive | 77 | 79 | 73 | 43 |
| makedefs, SETUP, README and Makefile | 37 | 35 | 35 | 20 |
| xcrun tool names in MakeInc.cmd | 22 | 26 | 22 | 22 |

New tool names are ctfdump, docc, objdump and python3; names alone do not establish required tools or compatibility. The upstream README documents X86_64 RELEASE, SDKROOT=macosx, no required KDK for Intel, AvailabilityVersions, libdispatch/libfirehose_kernel, matching XNU headers, optional DTrace CTF tooling and version-aligned Xcode/SDK. Exact open dependency versions and Linux build equivalents remain unresolved.

The [draft Tahoe target](../../targets/tahoe/target.json) is research-only. No compilation, patch application, toolchain qualification or runtime test was performed. The Monterey baseline is unchanged. Implementation still requires the approved stable physical Linux-hosted Monterey Intel baseline.

Next: resolve version-matched open build dependency pins and available tools.

Primary evidence SHA-256: `31f269ae8f48f16b23acfedf4d741e5ddb84d2b8d87d240558e573331275d875`.
