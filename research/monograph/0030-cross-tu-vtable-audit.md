# 30. Cross-translation-unit vtable consistency

**Date:** 2026-11-25  
**Source checkpoint:** 51 (R0030)  
**Scope:** Compiler IR, layout and relocation audit; no new provider object or link.

Eight actual full translation units were compiled to isolated LLVM IR with compiler vtable dumps, using the same generated headers and recorded recipes. All exited zero, with no new diagnostic demotions. The existing object files were separately inspected for Mach-O relocations.

| Class | Entries | Audited TUs emitting layout |
| --- | ---: | ---: |
| OSMetaClassBase | 20 | 8 |
| OSObject | 38 | 8 |
| IOMemoryDescriptor | 75 | 5 |
| IOMemoryMap | 55 | 5 |
| IODMACommand | 63 | 3 |

Full named slot descriptions and address points matched byte-for-byte for every audited class across the relevant units, not merely entry counts. Four nested MetaClass layouts also matched with 29 entries each.

The actual provider IR contained constant arrays of these lengths, with Dispatch at array index 14, address point index 2, virtual slot 12. All four audited generated objects carried GOT_LD references to the real base vtable symbol. The evidence corroborated the earlier qualified-dispatch interpretation.

The remaining actual function definitions may be provided by other translation units, including the still-missing handwritten IOUserServer implementation. Compiler and relocation consistency is not a final linked vtable audit, authentic Apple generator equivalence, live object execution or ownership proof.

The original audit.py, IR, layout-comparison.json, provider-dispatch-slots.json and relocations remain in the local evidence archive. Coverage stayed 958/984, 26 missing, accepted 869 inputs and 261 undefined. Next: review Darwin knote bitfields and the remaining handwritten providers.
