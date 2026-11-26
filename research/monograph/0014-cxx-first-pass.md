# 14. First complete C++ target audit

**Date:** 2026-11-25  
**Source checkpoint:** 35 (R0014)  
**Scope:** Compile probes and 869-input compatibility link.

All 117 remaining C++ targets were attempted using original component dry-run recipes. The libkern OSObject recipe matched the prior root command token-for-token. The corrected IOKit include path and strict warning policy were retained. No portable IIG output or new source/macro changes were included.

| Outcome | Targets |
| --- | ---: |
| Passed | 2 |
| Missing generated .iig.cpp prerequisites | 17 |
| Missing DriverKit/OSObject.h | 95 |
| Other distinct failures | 3 |
| Total | 117 |

IOCommandQueue.cpo passed as a 680-byte object with no external symbols because its source was excluded by the LP64 guard. KernelConfigTables.cpo passed at 2,160 bytes and exported gIOKernelConfigTables.

The other failures were IOLocks (new diagnostic groups and four hard void-pointer indirection errors), OSDebug (four hard void-pointer indirection errors), and OSKext (missing kextd_mach.h plus a compiler frontend signal failure). Missing generated prerequisites were not compiler failures.

## Link

Both successful objects entered a separate 869-input compatibility link. Exit 0, 16,165,141 bytes, SHA-256 `69d22a30b35b7d71e5cab12b7c60b9251dec9b1debf6314bf4f210f2e63ce34a`. The undefined set remained at 261 with no additions or resolutions.

Coverage: 846 C, 19 assembly and four C++ objects. The remaining 115 C++ targets comprised 90 IOKit, 24 libkern and one libsa.

## Next investigations

The typed-allocation C++ macro needed a source-backed wildcard-compatible type-trait adaptation without changing the C path. The kextd export was stale; independently generated headers matched SHA-256 `eff4cb1f437d43d853f31ec9ae587c1f5a1347f41f1c216030b50c70abfd17d1`. The portable DriverKit-440 IIG output needed a verified Monterey parser environment and ABI comparison before acceptance.

The original build.py, command logs, object manifests and diagnostics remain in the local archive. The link was a compatibility checkpoint, not a final executable or boot. Subsequent chapters cover the generator and handwritten IOKit research.
