# 17. Annotated Mach port direction and measured wire layout

**Date:** 2026-11-25  
**Source checkpoint:** 38 (R0017)  
**Scope:** Generator correction, layout probes and two additional C++ objects.

The parser environment represented mach_port_t as an ipc_port pointer. The generator classified parameters by canonical pointer depth, so three by-value input ports were incorrectly treated as output. The pinned interfaces and implementations explicitly used by-value ports with make-send or copy-send annotations.

An isolated generator correction applied only to the exact type and the two annotations. Regeneration produced all 17 headers unchanged, 14 identical implementations and three modified implementations: IODispatchQueue, IOEventLink and IOWorkGroup. Static comparisons confirmed request-side descriptors and no invented reply fields. All three still failed compile on alignment diagnostics; the previous hard field errors were gone.

## Layout observation

| Type | Size | Alignment | Content offset |
| --- | ---: | ---: | ---: |
| Mach message prefix | 36 | 4 | |
| Port/OOL descriptor | 16 | 4 | |
| IORPCMessage | 24 | 8 | |
| SetPort request | 100 | 4 | 68 |
| SetPort reply | 60 | 4 | 36 |
| Create request | 364 | 4 | 52 |
| Create reply | 84 | 4 | 52 |

Data-only compiler IR established that the content offset is 36 + 16 times the descriptor count, not necessarily naturally aligned for the payload. Changing wire offsets or ignoring warnings because the CPU supports unaligned loads was rejected.

## Independent fixes

The original kextd export was stale. A verified generated header, independently matching earlier copies, restored the required export; the original symlink was preserved. OSKext compiled on the first retry without additional warning demotions, 1,067,336 bytes, SHA-256 `215a0af94ab68661ee88589d83846b00490ba8ca2d38d38596e699f67a6aadc9`.

An isolated IOBufferMemoryDescriptor source copy replaced a single NULL return in a bool function with false, retaining the other pointer-return cases. The 301,824-byte object SHA-256 was `a4092d77191a83ba8317f989f35d6ce3bfe4cb90fd827c588327989de23e0b60`.

The manifest reached 66 independent objects (24 libkern, 41 IOKit, one libsa), 935/984 configured artifacts including the accepted 869. Forty-nine remained missing; no generated implementation yet compiled. No relink or runtime ABI claim was made. Original generation, layout IR and command evidence remain local.
