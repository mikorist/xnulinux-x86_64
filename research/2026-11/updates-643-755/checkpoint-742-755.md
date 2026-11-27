# CP742-755: Compiler replay, SDK declarations and source package reproduction

November 27, 2026. Edited research chronology following CP643-741. Results apply only to the recorded evidence; no new replay, source admission or release is implied.

## CP742: Reproduce a separately scoped public validator source package on both hosts

**PASS (source package).** Both hosts reproduced the same 4,052-byte source-only validator archive from already public source and ran the unchanged UBSan test, 229/229 each. The Python verifier was excluded; common binary identity and release remain open.

Recorded primary evidence SHA256: `3a0939256feb18266d1588062582ded1e30f0be2f527dc734c67d0ee1b4fdfcc`.

## CP743: Rigorously qualify unchanged public Python replay verifier contract on both hosts

**PASS (synthetic contract).** The original three Python test methods and 1,083 independent deterministic cases passed on each host with identical result hashes. All 48 executable lines were traced, not exhaustive branch coverage. Component attribution remained open at this checkpoint.

Recorded primary evidence SHA256: `0ef9bfb6184011e6bf21c7842ee9c84dd7b77d08626dd41ba6f8a79a91f2c27a`.

## CP744: Complete component-local MIT notice and reproduce Python verifier source package

**PASS (notice and source package).** The project maintainer approved the component-local MIT contributor notice. Both hosts reproduced a 3,346-byte source archive and passed the original three methods and 1,083 extended cases each. No public source update or release was performed.

Recorded primary evidence SHA256: `2de6dd2f6e980bea6e12086aaae4637a44f2ffe34d8e2e4a198d3d4be028eb9e`.

## CP745: Qualify independently rebuilt Intel Clang 24 BridgeOS frontend and strict SDK header regressions

**PASS (compiler regression).** The independent Intel Clang rebuild completed all 3,323 steps. Seven frontend cases and fifteen additional header cases matched expected results, including retained strict-header diagnostics. The compiler executable hashes differ between hosts; full compiler, SDK and runtime qualification remains open.

Recorded primary evidence SHA256: `c3d6d36eb284441b015d0723b914897101b834b422018dc190176e9860204cd1`.

## CP746: Confirm Intel Clang ordinary C C++ and Objective-C code generation matches Ryzen

**PASS (code generation).** Ten ordinary C, C++ and Objective-C fixtures produced matching objects with baseline and patched compilers on both hosts. Metadata, imports and dependency counts also agreed. No runtime or full compiler suite claim.

Recorded primary evidence SHA256: `64101f996d6386eebb38b48170d8615426b7a431279c6609623a81b4bdbbdfe7`.

## CP747: Confirm Intel Clang original Blocks source and relocatable link replay matches Ryzen

**PASS (compile/link).** The original Monterey Blocks source replay reproduced the same object and relocatable link results on both hosts. Eight external imports remain; no dynamic library or runtime execution.

Recorded primary evidence SHA256: `4cbec004a25ae3b90a16ab69c43ea89e943a210dda2361bb99ade8c7194435f4`.

## CP748: Qualify seven Monterey UUID diagnostic dependency source objects

**Mixed (compile).** Six original UUID source units compiled strictly on both hosts. The original formatting unit failed a signedness diagnostic; a separate reviewed candidate passed. The optional native formatting test could not build due to missing native headers. No runtime qualification.

Recorded primary evidence SHA256: `b92f515ecdfe3d0a226f5fd51f9487d0eec892734a03e571e2dfb09a9e255c69`.

## CP749: Link seven UUID diagnostic dependency objects and verify remaining imports

**PASS (relocatable link).** Seven UUID objects linked to an identical 4,336-byte relocatable object on both hosts. Three external imports remain; no dynamic library or runtime execution.

Recorded primary evidence SHA256: `c7e4bb94011c6486648b3865cfc8bc279fa28f3bdc2e69ab90389a39b445658d`.

## CP750: Resolve UUID memcmp import using original libplatform source and Libc aliases

**PASS (relocatable link).** The original generic comparison provider and its original aliases resolved the comparison import. Both hosts produced identical 4,552-byte objects; checked-memory dependencies remain. No optimized selection or runtime qualification.

Recorded primary evidence SHA256: `cefbd3434f3fe0e4339947a52b5adbc23e6ebb20ef4d9117c2bff6f9b7ce9367`.

## CP751: Export Monterey character classification and rune headers with separate strict stdio audit

**Mixed (declarations).** Five original exported character-classification headers raised the candidate to 245 headers. Strict character-only and ordinary consumer tests passed; explicit system-header audits retained thirteen nullability diagnostics per language. No locale runtime qualification.

Recorded primary evidence SHA256: `6128f6ca016b1e9e5faf84991534f68d3945db457f3cbc7dd8856e3965dbcec5`.

## CP752: Compile and link original Monterey UUID parser with exact source configuration

**PASS (compile/link).** The unmodified UUID parser compiled with original configuration and 126 verified staged header dependencies on both hosts. The identical 5,328-byte relocatable group retains five external imports. No parser execution.

Recorded primary evidence SHA256: `69e91811c9c79ccd58a5e83cd74a7ec83ad02828590a65ef9bf9649c38b3f8ec`.

## CP753: Resolve UUID parser strlen import with original libplatform source and alias

**PASS (relocatable link).** The original generic string-length provider reproduced its earlier object bytes. Both hosts produced identical 5,856-byte relocatable groups with four external imports remaining. No runtime qualification.

Recorded primary evidence SHA256: `2f2efa140cecd182694ce893c1878bf059f5599188d903ca01d181f7570e142b`.

## CP754: Qualify version-matched Monterey locale and numeric conversion declarations

**PASS (declarations).** Four original locale headers were exported independently, bringing the staged SDK to 249 headers. Strict C11, GNU11 and C++17 declaration tests passed with identical results. No locale runtime or full SDK qualification.

Recorded primary evidence SHA256: `9b4ccdad3f3f02c1f493bea07a54389acbb16a5573d10a6da695680cb05bf0cd`.

## CP755: Isolate Stage A common preprocessed input and reproduce the instrumented object

**Mixed (object reproduction).** Both hosts independently compiled one exact shared preprocessed synthetic validator input to identical ELF objects and passed 229/229 native UBSan checks each. Native preprocessing and final executable hashes differ; common sysroot, full binary reproducibility and release remain open.

Recorded primary evidence SHA256: `eff4702cefc5b7b10b180ee2028f5e740e03947cf19f9026bc63e925f2face96`.
