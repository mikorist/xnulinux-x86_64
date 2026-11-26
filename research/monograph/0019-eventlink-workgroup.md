# 19. IOEventLink and IOWorkGroup port families

**Date:** 2026-11-25  
**Source checkpoint:** 40 (R0019)  
**Scope:** Two generated implementations and host fixtures.

Each family has Create, SetPort-family and InvalidateKernel methods. Original compiler-measured layout was preserved.

| Method | Request size/offset | Reply size/offset |
| --- | --- | --- |
| Create | 132/84 | 84/52 |
| Set port | 100/68 | 60/36 |
| InvalidateKernel | 108/68 | 60/36 |

All wire alignment was four bytes. Eighteen assertions per implementation checked layout. Aligned content locals, typed result objects and initialized output descriptors avoided the previous pointer-punning approach. Actual nonvirtual handler signatures and OSDynamicCast checks were retained.

Both full TUs compiled with no new diagnostic demotions:

| Object | Bytes | SHA-256 |
| --- | ---: | --- |
| IOEventLink.iig.cpo | 245296 | `8b1b893533e801c40610ba65f5e44cda3fbd66e063c09e8bdc1819b499e4c2ca` |
| IOWorkGroup.iig.cpo | 241408 | `0107099fb9f432a5e95d7c0e88d2fdfe3bb73fe912d710e317e1a35dc730b7bb` |

The actual extracted SetEventlinkPort and SetWorkGroupPort invokers passed 30 host checks each after Darwin IR compilation and Linux retargeting. Both alignment positions, buffer overlap, typed arguments and invalid request/reply cases were covered. Create and InvalidateKernel layouts were checked, but their full invokers were not executed because live object metadata was absent.

OOL placeholders were not treated as transferred addresses. The original transport supplies actual serialized object addresses separately.

The manifest reached 69 independent probes (44 IOKit, 24 libkern, one libsa), 938 configured artifacts including the unchanged 869-input link. Three generated implementations passed compile; 46 targets remained. No actual Mach right transfer, serialization or live class ABI was established.
