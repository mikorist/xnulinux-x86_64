# 27. OSObject base dispatch and qualified vtable calls

**Date:** 2026-11-25  
**Source checkpoint:** 48 (R0027)  
**Scope:** Generated base wire adapter and compiler-layout evidence.

OSObject derives from OSMetaClassBase. The two generated queue methods are abstract at the base kernel level; real implementations were found in IOService. The adapter retained qualified base dispatch and the original supermethod path rather than fabricating providers or retain/release behavior.

Four wire structures were measured, with 12 assertions. SetDispatchQueue request/reply sizes were 372/60; CopyDispatchQueue 348/84. Bounds, typed output and string handling were checked. The original provider dereferences the queue argument, so the prototype explicitly rejects null queue input.

OSObject.iig.cpo compiled on the first actual attempt: 46,016 bytes; SHA-256 `47d61e9941091eff6deb43c29753abc744a535f6db46a915f3cb5e9af02dca38`.

The full Copy invoker and Set structural prefix passed 32 host checks. Full Set handler execution, live metadata and retain/release behavior were not exercised.

## Correcting the evidence interpretation

The first IR evidence check expected a direct OSMetaClassBase::Dispatch symbol call. The actual Apple-kext compiler mode emitted a qualified call through a fixed base vtable. Three IR loads referenced the base vtable at byte offset 112. The compiler dump recorded 20 entries, address point index 2 and Dispatch at index 14, virtual slot 12.

The evidence script was corrected to match the emitted code and the original failed assumption retained. This demonstrates layout for the audited TU, not live linked vtable contents.

The manifest reached 82 independent objects, 16 generated implementations and 951/984 artifacts. Thirty-three remained missing; accepted link 869 inputs, 261 undefined unchanged.
