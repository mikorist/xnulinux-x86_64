# 16. Ordinary Monterey RPC adaptation and typed-allocation probes

**Date:** 2026-11-25  
**Source checkpoint:** 37 (R0016)  
**Scope:** Experimental source overlays and compile probes.

The original IORPC structure has four fields. The prototype retained the combined Mach message and content layout rather than adding kernelContent. Two special units, IODispatchSource and IOInterruptDispatchSource, were deferred because CheckForWork and InterruptOccurred reuse reply storage as a request.

The local adapt.py verified original hashes, retained all 17 headers and adapted 15 ordinary implementations. The experimental content helper checked message capacity, version, descriptors and object references before calling the pinned content locator. It also checked synchronous reply presence. The resulting typed packed access still emitted cast-align and unaligned-access diagnostics: this remained a blocker, not a production solution.

## Typed allocation

An isolated kalloc.h overlay introduced C++ pointer-pointee traits to retain the original void-wildcard semantics without dereferencing void in type expressions. The C macro remained unchanged. Twelve static assertions using the actual header passed. OSDebug compiled with the overlay; IOLocks required narrowly recorded newer-warning demotions, including a separately retained retry for cross-TU lifetime suggestions.

## Batch progression

| Stage | Passed | Failed |
| --- | ---: | ---: |
| Ordinary adapted batch (110 targets) | 23 | 87 |
| Advisory-only retry of 87 IOKit failures | 39 | 48 |

The final manifest contained 64 distinct successful probes: 40 IOKit, 23 libkern and one libsa, including the two independent typed-allocation objects. Eleven earlier probes were rebuilt within this count, not additional. None of the 17 generated implementations passed yet.

The 51 unresolved compile targets consisted of 48 current failures, two deferred special units and OSKext. Three generated units misclassified annotated by-value ports as output parameters; IOBufferMemoryDescriptor had a bool-return compatibility error. ABI warnings were not globally disabled.

The original adapt.py, kalloc-probe.py, compile.py, advisory retry, patch and PROBE-OBJECTS.tsv remain private pending review. The 869-input accepted link retained 261 undefined symbols and its previous hash. No boot or live RPC test occurred.
