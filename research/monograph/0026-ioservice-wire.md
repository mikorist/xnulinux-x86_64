# 26. IOService generated dispatch

**Date:** 2026-11-25  
**Source checkpoint:** 47 (R0026)  
**Scope:** Compile and host fixture evidence.

The generated IOService adapter covers 34 own methods and 36 typed thunks including two inherited queue methods. Original generated signatures, OSObject fallback, metadata checks and bounded strings were preserved. Sixty-eight wire types were measured, with 204 layout assertions.

Stop_async is the single void one-way method in this family; its pinned implementation is empty. Start and Stop are synchronous. The original report operations return Unsupported in their base provider. The prototype did not invent these implementations or change service lifecycle policy.

The full TU compiled without additional warning demotions. IOService.iig.cpo: 443,456 bytes, SHA-256 `41829624fa9b5866624c6c5452e3298677de217206ce34f5736633d2ba8caeb4`.

The host fixture extracted GetRegistryEntryID, SetName and CopyProperties invokers plus preflight prefixes of SetLegend and Stop_async. All compilation, IR retargeting and execution stages exited zero; 52 checks. The tests covered full-width IDs, string bounds, object identity, bool representation, overlap, one-way semantics and invalid structural cases.

IR verified the original OSObject dispatch fallback and inherited queue invokers. Actual service registration, metadata, OOL ownership and complete execution of the extracted preflight-only methods were not tested.

The independent probe count reached 81, 15/17 generated units, 950/984 artifacts and 34 missing. The 869-input accepted link remained unchanged at 261 undefined.
