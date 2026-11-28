# CP836-855 research update

November 28, 2026. All 20 primary evidence hashes were verified. The retained-link reference remains CP602. Accepted regenerated inputs increased from 764 to 839 of 1,114 (75.31%); 275 remain retained. These are build and provenance results, not a new boot or full source qualification.

## CP836

Four BSD generated C sources and two headers match historical bytes on both hosts. Initial provenance-comment assumption corrected in a separate candidate. No new object admission; 764 regenerated, 350 retained.

Primary evidence SHA256: `830d12880ff2315ad3b1e8f28a12239cbe24997192529ea0bf81f4590a209c8d`

## CP837

Four generated BSD objects match with 386 qualified dependency paths. Full retained-input relink matches CP602. 768 regenerated, 346 retained. CP818-837 evidence window complete; technical review remains open.

Primary evidence SHA256: `4521d1d437a4e33deefa73814f1394c5c13cb9e9b5610cb9d6405b17cc69d7f8`

## CP838

Two archived Debian libclang dependency packages independently verified and extracted in the build workspace on both hosts. Thirteen headers and the library match historical content. No host package installation or new object admission.

Primary evidence SHA256: `ff42c4ba258288e4b8fe6036ddf2cb18d320b1d8d6b868305bf0f7d055f02daf`

## CP839

Historical portable IIG host generator independently rebuilt from the pinned source and preserved host adaptation. 241 compiler resource headers match. Version and help checks pass; native binaries differ with host toolchains.

Primary evidence SHA256: `7e684a84166c8482b5fc6c4a86c3b54d50f701ec563824dba5ac8293b70448c6`

## CP840

Seventeen generated DriverKit headers independently match historical bytes. Sixteen derived dependency paths (202 occurrences) resolved; one path remains across 64 original C++ candidates. No object admission.

Primary evidence SHA256: `1abd1604cf0d06aba1c7c9e4a9fb564b1c203f9eef0b460a88f0ab58897f6d1e`

## CP841

Local historical compatibility header reconstruction and positive/negative compile fixtures pass. Ryzen connector unavailable during this checkpoint; cross-host evidence remains HOLD. No object admission.

Primary evidence SHA256: `3f2c8ca32e308b27784effbc611511a413555a9e9ed4affee8b8b4a4eb20674d`

## CP842

Ryzen connectivity recovered. Independent reconstruction and compile-only checks on both hosts use 161 qualified dependencies. Compatible cases compile and the incompatible assertion is rejected. Remaining derived path qualified within this scope; no object admission.

Primary evidence SHA256: `cb9406355f7861d3dfb6a4850a40b6b6dd795b05f4039b41c597052e5380f060`

## CP843

Eleven original libkern collection and scalar objects match with 352 distinct dependencies. 779 regenerated, 335 retained.

Primary evidence SHA256: `ec5a8bdd044f216db9967e33249c21daf9f37d5b5b9e4045a9aa52bd9cbae310`

## CP844

Six original libkern data and serialization objects match with 368 distinct dependencies. 785 regenerated, 329 retained.

Primary evidence SHA256: `751ce6a1d034ccfad918909f55e84ab367e37e9d8f8c9adf6ac641c7a93dc9b1`

## CP845

Eight original IOKit power and performance objects match with 334 distinct dependencies. 793 regenerated, 321 retained.

Primary evidence SHA256: `8de9ff522f7684df35cd3990509fb328454e7818c5648e9675641d32db2903c0`

## CP846

Six original IOKit reporting and accounting objects match with 327 distinct dependencies. 799 regenerated, 315 retained.

Primary evidence SHA256: `3897dd1c9d0ff6101e7d34796d376dc303d9812442f4011f5b594c3b64ecf49e`

## CP847

Seven original IOKit queue and synchronization objects match with 331 distinct dependencies. 806 regenerated, 308 retained.

Primary evidence SHA256: `35ced2a276adcdc5d6dd47805dbee96d767891bc77fe804e96d7207983ea9ba2`

## CP848

Five original libkern object infrastructure and diagnostics objects match with 397 distinct dependencies. 811 regenerated, 303 retained. Compile/link evidence only.

Primary evidence SHA256: `617d4c6b88e3a8f38bf7d3e62b334a139e6cbd364791ce4fd9b9def117a75dca`

## CP849

Six original IOKit platform initialization and service objects match with 415 distinct dependencies. 817 regenerated, 297 retained.

Primary evidence SHA256: `98a86edbeb8da9fc77ecbcdf61bd6be60d3a71b5a3a82a7cd864e4bd0d61e9b1`

## CP850

Eight original IOKit memory descriptor and DMA interface objects match with 359 distinct dependencies. 825 regenerated, 289 retained. CP841-850 series complete; oldest technical review remains HOLD.

Primary evidence SHA256: `528c22ab6c266a746141d6b1009760c7f2a54d3db021e9ea63cba9c2e8da1620`

## CP851

Seven remaining original C++ objects match with 508 distinct dependencies. All 64 CP811 original C++ candidates now have scoped dual-host compile/link evidence. 832 regenerated, 282 retained.

Primary evidence SHA256: `5a1252b559b2f84e45c402c9a5834209aa111d63b81dc293aa5f94605e9bd9aa`

## CP852

Two build metadata and non-LTO marker objects match with 14 distinct dependencies. Historical build-date fields reproduced reversibly; raw generator output retained. 834 regenerated, 280 retained.

Primary evidence SHA256: `9515909fe3f60e14840afce83837e09a0af3a8c78e854118f2fc0951e5383cba`

## CP853

Two final layout marker objects match with 95 distinct dependencies. Historical upstream segment naming reproduced; raw object retained. 836 regenerated, 278 retained.

Primary evidence SHA256: `ca42d3144b7ac553f175f444ff2932b6adb7d4dfc4d1c49d0c0ed8344001fd22`

## CP854

Fresh BSD configuration generation and historical ioconf object compile match with 91 distinct dependencies. 837 regenerated, 277 retained.

Primary evidence SHA256: `ca73284b274e4f8b5cdc981a544654bd424f6195dbef782bed7e03eaa6fac6fe`

## CP855

Two original BSD VFS and performance accounting objects match with 405 distinct dependencies and fresh configuration. 839 regenerated, 275 retained. Full 1,114-input retained relink matches CP602 on both hosts.

Primary evidence SHA256: `5ffd4bb9a8d9a73de4573016146676a4e9e043fc1274d7a141549378e4631d7a`

## Remaining work

The 64 CP811 original C++ candidates are complete within the stated compile/link scope. Other retained inputs, generated implementation recipes and full parser provenance remain to be qualified. Batch 03 is not qualified. Full clean-source build, AMD admission, hosted runtime, source licensing, SDK/runtime completion, portable tool packaging and release remain HOLD. Chronological reporting does not close the oldest technical review (CP498-517).
