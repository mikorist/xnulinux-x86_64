# 23. Memory map and buffer descriptor wire families

**Date:** 2026-11-25  
**Source checkpoint:** 44 (R0023)  
**Scope:** Generated wire compile and host fixture tests; no allocation or mapping test.

IOMemoryMap's private state contains four uint64_t words (length, offset, options, address). The pinned _CopyState implementation supplies actual values. IOBufferMemoryDescriptor Create and SetLength are synchronous, with existing allocation and length policies in the actual provider. Local-only getters are not RPC methods.

The prototype preserved the original providers and inheritance, specialized only the three RPCs and verified six measured wire types with 18 assertions. Additional assertions checked state size 32, alignment eight and field offsets.

| Method | Request bytes | Reply bytes |
| --- | ---: | ---: |
| _CopyState | 84 | 92 |
| Create | 108 | 84 |
| SetLength | 92 | 60 |

Both complete units compiled without additional warning demotions:

| Object | Bytes | SHA-256 |
| --- | ---: | --- |
| IOMemoryMap.iig.cpo | 83232 | `0f5de784b2b99dd33761f309e2bbd7ea390a52540907817c38442c59996b0b7f` |
| IOBufferMemoryDescriptor.iig.cpo | 102064 | `0a0d6b1177c6a339f0fa143a5e35510ea8fe3022103d1b4f7a8585453f62a659` |

The extracted invokers passed 26, 28 and 22 host checks, respectively. These demonstrated preservation of full 64-bit fields, aligned typed output, overlap handling and negative bounds/flag checks. Arbitrary numeric patterns were not real addresses or valid allocation requests; no real memory was allocated or mapped.

Whole-TU IR verified typed handler calls and the OSObject/IOMemoryDescriptor fallback paths. The manifest reached 77 independent probes, 11 generated units, 946/984 artifacts, 38 missing. The 869 accepted link and 261 undefined remained unchanged.

The next families require distinct count, array and range semantics rather than mechanical reuse of scalar adapters. Original source remained untouched; live transport and provider ABI remain separate gates.
