# 28. Completing the generated IOUserServer unit

**Date:** 2026-11-25  
**Source checkpoint:** 49 (R0028)  
**Scope:** Last generated IIG compile; handwritten transport is a distinct task.

IOUserServer has three own synchronous generated methods: Create, Exit and LoadModule, plus inherited RegisterService. Create uses the original provider and existing thread-local server; Exit and LoadModule return Unsupported in the pinned kernel. No module-loading or credentials behavior was changed.

Six compiler-measured layouts and 18 assertions covered mixed PORT/OOL Create input, typed server output and bounded strings. Create wire sizes were 196/84 bytes, Exit/LoadModule 1116/60. The original static Create and inherited RegisterService dispatch were retained.

IOUserServer.iig.cpo compiled without new warning demotions: 236,080 bytes; SHA-256 `d48e029ee5196feb94ae4269678b4351f9aa9db7a3ee1926afb28a0ea370ca23`.

The first fixture lacked the actual IOUserServer class header; including the same real header as the original TU resolved it. The extracted Exit/LoadModule invokers and Create structural prefix passed 48 host checks. Test handlers were fixtures, not the actual Unsupported providers. No module loading, process exit, live TLS creation or reference ownership was tested.

## Original hierarchy distinction

The IIG declaration describes IOUserServer as an IOService subclass, while the actual kernel class derives from IOUserClient. The generated IOService fallback was retained as emitted; this source-level distinction requires cross-TU metadata review.

All 17 generated IIG implementation objects now independently compiled. The manifest reached 83 probes, 952/984 artifacts and 32 remaining handwritten IOKit targets. No relink occurred; 869 accepted inputs and 261 undefined remained. Compilation does not establish authentic Monterey IIG equivalence or live transport correctness.
