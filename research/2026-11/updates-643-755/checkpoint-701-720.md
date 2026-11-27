# CP701-720: Open runtime dependency and declaration closure

November 27, 2026. Edited research chronology, based on the recorded experiments and verified primary evidence identities. PASS applies only to the stated scope. No new experiment, independent replay, source admission or release is implied. Primary evidence digests identify retained records; the records themselves are not included here.

## CP701: Inventory Monterey libSystem direct dependency source associations

**PASS (inventory).** Direct source declarations are located for 24 of 25 libSystem recipe targets, with fifteen candidate release associations across thirteen packages. Ten associations are unresolved or non-Apple; transitive closure remains open.

Recorded primary evidence SHA256: `4856ae0fe55f03dc20554f031ca35cfad892cada057bbc57f36c1e677a14a2ec`.

## CP702: Acquire six exact Monterey runtime source references on both hosts

**PASS (source identity).** Six official Monterey runtime source references are independently acquired on both hosts. All 2,185 tracked entries agree in the source manifests; no library build.

Recorded primary evidence SHA256: `a041007a47b6e05c31a5aac04bf1c59a7f8c3ab6bf54d4e6c62e4c8d57da9c5c`.

## CP703: Compare official Monterey libSystem umbrella with PureDarwin direct recipe

**PASS (comparison).** The Monterey libSystem umbrella lists 28 required and eight optional libraries; eighteen required entries have candidate direct correspondences. No direct correspondence does not prove an implementation is missing.

Recorded primary evidence SHA256: `3188854913870fe7c338873d86059c930352b0db916ee9aec1106abf9accdbfa`.

## CP704: Compare five runtime header roots against exact Monterey sources

**PASS (comparison).** Of 675 tracked runtime header members, 320 match the same path, 129 differ and 226 are absent at that path. Generated or relocated headers remain possible.

Recorded primary evidence SHA256: `cc4c5d9243f66d31f72ea5e74e69654df1cba739b16fbc2b1bc81f390ae82d56`.

## CP705: Generate Monterey POSIX availability and symbol-alias declarations from pinned sources

**PASS (generation).** Two original Monterey availability and symbol-alias declaration headers are generated independently and match across hosts. No runtime or installed SDK qualification.

Recorded primary evidence SHA256: `9d12eb3e2d73ca3fc5f5c6fe0653b18aa1145e060f89d47f824ce0e812fd5961`.

## CP706: Compile standard C and C++ type layout against scoped Monterey source SDK

**PASS (compile).** A 42-header partial source profile supports scoped C11 and C++17 type-layout checks, sixteen per language per host, with matching dependency and deployment evidence.

Recorded primary evidence SHA256: `abfa519f4d4f5c0236ecc98a30b4ebc35af154f71bc1da11941c5cf973082c2d`.

## CP707: Expose Monterey external availability annotation version gap

**HOLD (declarations).** A legacy availability declaration compiles, while the Monterey 12.5 declaration fails. Twenty-four later version macros are absent from the retained legacy declaration surface.

Recorded primary evidence SHA256: `da7b0ff7f3b8b08e5410a897afc817e1b78ea6ef4bbdc0c46c101367dba7d14f`.

## CP708: Qualify scoped PureDarwin target-conditionals candidate for Monterey compile profile

**PASS (candidate).** The separately staged PureDarwin target-conditional candidate passes the intended Monterey compile profile and rejects three wrong-target controls per host. Release provenance remains open.

Recorded primary evidence SHA256: `61aedee8f0c657865e74fb9ebe5df3913ca63ed2fbc7b3d5711d8f1bed63fded`.

## CP709: Compile exact Monterey Blocks declarations in separate experimental SDK profile

**PASS (compile).** An explicitly mixed 46-header profile compiles an owned Blocks fixture in C, C++ and Objective-C. Actual runtime imports remain unresolved.

Recorded primary evidence SHA256: `3b17e77124a203e14871da066a07b4b8184458d7f80090c6b496ed4473fffb04`.

## CP710: Validate separated partial Monterey SDK profile admission

**PASS (partial profiles).** Two distinct partial SDK profiles are admitted with exact identity checks; all 23 negative cases per host reject mismatches or unsupported promotion to full SDK/runtime.

Recorded primary evidence SHA256: `40b6fdc1192cd3a4de06032b9ff5e9bbd683b3b014b5db9a40046360a8e2fde7`.

## CP711: Resolve scoped Monterey macOS availability declaration blocker

**PASS (candidate).** The scoped Monterey macOS availability candidate compiles all 45 version declarations and 804 added deprecation pairs. Eleven diagnostic controls per host agree. This resolves the selected CP707 declaration gap only.

Recorded primary evidence SHA256: `6b589af214f853cb4a25e9eeea0c6d0dc14d68158e06096e8ae8efcf68f41cc5`.

## CP712: Compile actual Monterey Libc string and time declarations with candidate

**PASS (compile).** A 60-header candidate supports ordinary Libc string and time declaration callers and layout checks in three language modes. No link or runtime.

Recorded primary evidence SHA256: `146562bf9d19ed08e0d6e47d42b884b8b73a1681b64daf86890b249cff868da9`.

## CP713: Close scoped Monterey stdio and stdlib declaration dependencies

**PASS (compile).** The stdio/stdlib declaration stage grows to 97 headers. Initial dependency mapping problems are corrected in retained successive candidates; all three ordinary compile profiles match.

Recorded primary evidence SHA256: `bf9943b27c3890b2faa617a10c2a710506479cb7cbabc8a456dddf1c6e02f593`.

## CP714: Compile original Monterey Blocks runtime object independently on both hosts

**PASS (object).** Original Monterey Blocks runtime source yields identical 8,600-byte objects on both hosts, with thirteen external definitions and seven unresolved imports. One warning is preserved.

Recorded primary evidence SHA256: `51c5c1a3a4542b2d1797b44c8053086a1b8798e63e8787d353fa4e62e94fb69f`.

## CP715: Build original Monterey libplatform provider for Blocks memmove dependency

**PASS (object).** An original generic libplatform memory-copy provider compiles identically, with one external definition and no unresolved imports. Symbol identity alone does not establish actual linked execution.

Recorded primary evidence SHA256: `dd6563b3f61084bd41de9e320f896c697ffd82d427470d8878aaf93d78267e05`.

## CP716: Compile original Monterey Objective-C Blocks class data

**PASS (object).** Original Objective-C Blocks class data compiles identically with a narrow test declaration adapter and 150 staged headers. Actual Foundation and Objective-C runtime dependencies remain.

Recorded primary evidence SHA256: `0ddaab3a8cd854a112b4140165abe4de3388b63600559ac8195688acef319735`.

## CP717: Relocatable link of Monterey Blocks runtime and original Objective-C class aliases

**PASS (relocatable link).** Three verified source objects combine into identical 21,912-byte relocatable objects with six original aliases. Eight external imports remain; no dynamic library or runtime execution.

Recorded primary evidence SHA256: `165bec88260aab985f18b445f95516f63e72b603311962de3b16846700755baf`.

## CP718: Acquire exact Monterey dyld prerequisite source on both hosts

**PASS (source identity).** The official Monterey dyld source reference is independently acquired; 1,551 tracked entries and selected public/private header identities match. Loader build remains open.

Recorded primary evidence SHA256: `8488b224bf883da9c333ef719ee02c228d0a2bd3c379ab453068967677333122`.

## CP719: Expose modern dyld declaration and compiler availability limitations

**HOLD (compiler/declarations).** The 175-header stage exposes original dyld declaration gaps and a compiler platform-attribute limitation on both hosts. No diagnostic suppression was applied.

Recorded primary evidence SHA256: `2b2219fa314e62f51b3cc312aa71cf4de3f557fc87e7d1a9bb38a0f99d96cac8`.

## CP720: Resolve supported multi-platform availability dispatch and isolate BridgeOS compiler blocker

**Mixed.** The supported-platform availability candidate passes eight owned diagnostic cases per host. Original dyld header compilation still reports 38 unknown BridgeOS platform errors.

Recorded primary evidence SHA256: `051fee5cb75ddee2053388d8ba4a978fae410197008edf1ee1f1f2e5c32201eb`.
