# CP756-775 research update

November 27, 2026. Monterey XNU 8020.140.41 remains the baseline. All 20 primary evidence SHA256 values were checked against retained results. These are reviewed chronological summaries, not downloadable full reproduction bundles or technical review closure.

## CP756

Original Monterey strtoul syntax advances past OSAtomic.h with genuine release-private includes, but pthread.h is missing. All 249 staged headers and source pins match. No object or runtime result.

Primary evidence SHA256: `3c730eea4a8f82495d8a68ef805b0772f0d11fdea07b57a0813fd353c29a8a6e`

## CP757

The original libpthread export alias is reproduced on both hosts; public declaration probe passes. The next missing header is System/machine/cpu_capabilities.h.

Primary evidence SHA256: `fcf4d42afcbe55c6291544760246de56abbdd68cadc05bd9f726cb7e58c5dbe6`

## CP758

Native Stage A inventory: 24 of 49 dependencies match and 25 differ; one of ten selected link inputs matches. Package database queries failed on both isolated environments. Common native provenance remains open.

Primary evidence SHA256: `8cb6977467b7fe0ae6fbfcecb8e3c4f92f3d87d3089bb27af515556f71e402d6`

## CP759

Independent preprocessing and instrumented object compilation match using 47 identical retained headers plus two unchanged fixture files. This is not a full source-derived sysroot.

Primary evidence SHA256: `c5dd7de54e6c1adc8f6be431ff51297b2f02c2fb1b3e530371d94d4b0b841f5c`

## CP760

Both native GCC links pass 229/229 synthetic checks; executable identities differ. Three required sanitizer imports remain present.

Primary evidence SHA256: `8137810b1c0774b5041ba8c1549dbfb180471b7fb16e5522707e9c828302010f`

## CP761

Three source-derived System.framework header exports match; original strtoul advances to missing os/tsd.h. No full SDK or private ABI qualification.

Primary evidence SHA256: `facc9a2c3853ca7d10fe621604fc7a2b89cc3889ac88af99af783ad5275b84f6`

## CP762

Original isctype.c compiles to identical 208-byte objects without symbols; the required symbol-provider assertion fails. Public export strips seven internal blocks, including the externalization selection. No isxdigit provider.

Primary evidence SHA256: `845aa9bd0d0fe04536035bd63ddc6cf4b5c54fab8d07c1a14b0278d22fcfe770`

## CP763

Exact tsd.h and ten Mach source headers are staged, including one already-identical file. An initial collision assertion is preserved. Eighteen generated userspace headers remain missing; syntax reaches mach/clock_priv.h. No stubs or runtime qualification.

Primary evidence SHA256: `070106e85ef013fbdc3cdcb04912d16f049817645bea463160ba942d3b8a5231`

## CP764

Native link maps reproduce the earlier binaries and 229/229 checks per host. Each trace has 21 actual input records; native executables still differ.

Primary evidence SHA256: `8a9c15645f99abd776a729cecc16d02e0162b73e938508e9e1c5f446358550b9`

## CP765

Identical pinned LLD/CMake sources (4,215 files) are extracted. Initial Intel configuration fails on old path metadata; separate workspace-native configurations pass on both hosts. No linker build yet.

Primary evidence SHA256: `f49306490f87cd9d6ea56a4b4ffef65acbe8cac68b6902a7b4cc87824b24be1c`

## CP766

Both LLD builds stop before linking: three of 69 external archive inputs are absent (LLVMDTLTO, LLVMLibDriver, LLVMWindowsManifest). Existing compiler trees remain unchanged.

Primary evidence SHA256: `68efd7555527fe3c51c6bc438ae5374fd635e8134ca20701879019edca65393d`

## CP767

Identical pinned compiler-rt/CMake sources (4,908 files) are extracted. An initial duplicate UBSan target configuration fails; a separate original unconditional configuration passes on both hosts.

Primary evidence SHA256: `8ab671ea99b6bf28a7fb60b5f07c01629337386f158469ff88fcfb14f7a74b7b`

## CP768

Both hosts finish 103/103 build steps for standalone static and shared UBSan. Required symbol sets match; binaries differ. Full compiler-rt qualification is not established.

Primary evidence SHA256: `6b8b4c15601ede94a1761db9c34c2000ec3bdc264af0580c939f292cbbcc3fd5`

## CP769

Unchanged Stage A fixture passes four runs of 229 checks (916 total), using explicitly selected source-built static/shared UBSan runtimes, without system libubsan fallback. Native executables still differ.

Primary evidence SHA256: `ec7d7acac2fd54a8745a08163bd63cb3c8429809398b3c37ae1b500802f3a53a`

## CP770

All 24 signed-arithmetic diagnostic checks pass across both hosts; six valid and six overflow cases per host. No memory-corruption fixture or complete sanitizer-suite claim.

Primary evidence SHA256: `2121596cedebe6a093107d932afd42cc10e0fbc3383f67c8797c7895f5e227df`

## CP771

Six ordinary BSD metadata, profiling and priority objects independently regenerate with 505 staged dependencies and identical dependency order. Initial two missing mach_host.h cases are resolved using original kernel-profile generation. Exact complete relink: 101 regenerated, 1,013 retained.

Primary evidence SHA256: `957155b608fa31cb89a1e203fa1aad25734da484d2498cb1d1777e4063dfb2f3`

## CP772

Eight ordinary congestion-control and queue objects independently regenerate from 498 dependencies. Exact complete relink: 109 regenerated, 1,005 retained. No network runtime claim.

Primary evidence SHA256: `99371dee64e4d75065d1c90c53be2a421519218d1c3056a5b0c4144b5f43dc99`

## CP773

Eight IPC/work-interval objects independently regenerate from 487 dependencies. Initial ten-unit attempt has missing kernel-profile mach_port.h on Intel and missing historical pthread recipe on Ryzen; only eight qualified. Exact complete relink: 117 regenerated, 997 retained.

Primary evidence SHA256: `249127e4af4ed85a38b905e265d40795888e0e8b574cfadddf6f12518836fc0d`

## CP774

Both previously deferred pthread units independently regenerate from 494 dependencies after original kernel-profile mach_port.h generation and recovery of the matching Ryzen historical recipe. Exact complete relink: 119 regenerated, 995 retained.

Primary evidence SHA256: `d2914730926be8ac8db8595ecbbbac6ac705814e29a56e472275eef2dac6ec58`

## CP775

Two NFS units independently regenerate from 433 dependencies. Initial nine-unit attempt remains incomplete: four generated declarations missing and a historical recipe argument-position assumption in the staging script fails on Ryzen. Seven units retained. Exact complete relink: 121 regenerated, 993 retained.

Primary evidence SHA256: `5944b1bff5d5ce70d792398706fcbcd3dc2c9e1305c1e8e26760b24f200bd914`

## Current boundary

CP771-775 add 26 independently regenerated kernel inputs, with 121/1,114 regenerated and 993 retained. The CP602 image remains byte-identical across both hosts (SHA256 `49d24b6512f178a5d9b19dfd7f10946f936f78c7725e1a7e6e2f8089055720b2`). Kernel-profile generated declarations are distinct from the pending userspace SDK declarations. No new boot, physical hosted execution, full clean-source build, complete SDK/runtime, license clearance or release qualification is claimed. Last closed technical review: CP497. Thirteen complete windows remain open, plus 18 subsequent records. The five new source-regeneration checkpoints advance existing HOLD prerequisites; no broad gate is promoted.

[Research journal](../../README.md) | [Project status](../../../README.md#current-status)
