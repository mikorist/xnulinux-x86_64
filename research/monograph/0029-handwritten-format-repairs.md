# 29. First handwritten IOKit provider repairs

**Date:** 2026-11-25  
**Source checkpoint:** 50 (R0029)  
**Scope:** Six handwritten provider compile probes.

The 32 remaining diagnostics were reviewed without repeating generated-interface work. Seven targets had only format-signedness diagnostics; six smaller cases were chosen. IOPolledInterface, with 52 occurrences, was deferred.

Nine isolated changes adjusted logging and panic argument types to match format specifiers, not the underlying device, DMA or VM logic. The original quoted-include search was preserved. All six compiled without new warning demotions.

| Object | Bytes | SHA-256 |
| --- | ---: | --- |
| DINetBootHook.cpo | 164688 | `e38f0de5dce50831e567918a9c665a6bf15b410a0d9ac7bc5f153afd825f87d8` |
| IOCatalogue.cpo | 329888 | `10a096c3f09ef65c39183a2299dad0ccfa36b7e2a3a315deab7f468e9be589ca` |
| IODMACommand.cpo | 303808 | `5ba0ba1b651f4407d5fcef4b93fd6d0806565904690fea7f5a6bea29fac0665b` |
| IODeviceTreeSupport.cpo | 247696 | `0dd8e63e354fd1db0f9f608bfaf39a7339a59ecee4e8c7d9028156f13d6d459e` |
| IOMemoryCursor.cpo | 168128 | `34100f8eacfe9aef10c053bc7f6f52c7815781eab3bc05ea94f37fa0e8930ad0` |
| IOMemoryDescriptor.cpo | 585408 | `1c5c48f96713d7a43cabb8b2d80bdf02fb1edb8733545742dfe3e183a6b349cf` |

Symbol inspection found seven exact external definitions among the baseline unresolved names, involving disk-image boot, device tree and device operations. Vtable symbols existed in real providers but did not establish slot or live ABI compatibility.

The independent count reached 89 probes (64 IOKit, 24 libkern, one libsa), 958/984 artifacts and 26 missing. No accepted inputs were added. IOUserServer handwritten transport, callback ABI and bitfield layout remained open. Original patches, build.py, logs and symbol-evidence.json remain local.
