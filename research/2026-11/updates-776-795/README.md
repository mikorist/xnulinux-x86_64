# CP776-795 research update

November 27, 2026. Monterey XNU 8020.140.41 remains the baseline. All 20 primary evidence hashes were verified. Each reported successful object group has identical ordered dependency closure and complete 1,114-input retained-link identity on both hosts against CP602. This does not qualify a complete clean-source build, runtime, licensing, or release.

## CP776

Four missing NFS kernel-profile declarations were independently regenerated from pinned sources with exact historical bytes. No new object accepted.

Primary evidence SHA256: `e23e3969240165dfb1e2d9d342bf62fad39af5626e83b49c0f6de6fd44feafe6`

## CP777

Seven deferred NFS units independently compile with 523 exact staged dependencies and identical ordered closure. The historical source selection was corrected without changing compiler flags. 128 regenerated and 986 retained inputs.

Primary evidence SHA256: `6375373ce703de3e5441027065892b0a561cfdc370f05d845014eb9d1217da78`

## CP778

Three BSD memory-status units regenerate with 481 exact staged dependencies. 131 regenerated and 983 retained.

Primary evidence SHA256: `6244d4937ad780398eb14cc6dd0494d5709c4780ac7aac2cf24b670bba3698e2`

## CP779

Four BSD VM and unified buffer-cache units regenerate with 562 exact staged dependencies. An initial dependency HOLD is retained; two original generated declarations resolve it. 135 regenerated and 979 retained.

Primary evidence SHA256: `5ee753aea5dcb53df7d6cb50f37c8af4eba8bd7ba74a51149c722a755e1a638a`

## CP780

Four BSD event and system-control units regenerate with 553 exact staged dependencies. 139 regenerated and 975 retained.

Primary evidence SHA256: `1d469237f5bb64103503117c9f0ac73425f355faf46a3a7be7aa67ffe0f4292f`

## CP781

Four BSD accounting and timer units regenerate with 458 exact staged dependencies. A separate VFS/logging attempt remains HOLD because of missing historical output and derived-source provenance. 143 regenerated and 971 retained.

Primary evidence SHA256: `e286b3debfd604737e4eab2d9cec5316f18fae3b9d574b203d6ea32841dd4c4d`

## CP782

Six BSD network data structure and utility units regenerate with 492 exact staged dependencies. 149 regenerated and 965 retained.

Primary evidence SHA256: `86635167de42757684db6132ed975a99dde7c55f38fbad78d949f1ac30345c1c`

## CP783

Six BSD network interface units regenerate with 445 exact staged dependencies. 155 regenerated and 959 retained.

Primary evidence SHA256: `375edd7246bbd5dce01d9633a3228a2947bb630ffd0c20de7b1d92fcc0135f5c`

## CP784

Five BSD IPv4 multicast and interface units regenerate with 455 exact staged dependencies. 160 regenerated and 954 retained.

Primary evidence SHA256: `46890ca27cea305de406a5f23432d4a774ae89b18fb111c42c54770e6a6c9c5a`

## CP785

Six BSD IPv6 multicast and interface units regenerate with 464 exact staged dependencies. 166 regenerated and 948 retained.

Primary evidence SHA256: `5de46a2402244d4a9fc91417bb4453c4b850ee0bed8cf8b21b7d154e47582686`

## CP786

Eight BSD TCP units regenerate with 524 exact staged dependencies. 174 regenerated and 940 retained.

Primary evidence SHA256: `4e5ce298453fd2a487ff7614fd6afa8c34192d65f3bb5ac46d44684881f306f2`

## CP787

Three BSD UDP units regenerate with 478 exact staged dependencies. 177 regenerated and 937 retained.

Primary evidence SHA256: `3511ca7080d5e7d2cc2975eccdad87024ce83a38a6dfa0bc63074819ad844747`

## CP788

Three BSD routing units regenerate with 449 exact staged dependencies. 180 regenerated and 934 retained.

Primary evidence SHA256: `80753f861a3f08afa6047600fc5863c7bec960289784980da4d23b002933cec5`

## CP789

Seven BSD multipath TCP units regenerate with 471 exact staged dependencies. 187 regenerated and 927 retained.

Primary evidence SHA256: `8a2b8371fc354de78d90e0c2356d2ec6dad6d526265f6200ef820a2d8d43dbc7`

## CP790

Five BSD Skywalk memory units regenerate with 489 exact staged dependencies. 192 regenerated and 922 retained.

Primary evidence SHA256: `fff2616338b2cc24e5f872e4faafac041751dd9d2226e0686a03a72330423b5f`

## CP791

The first local batch covered 303 candidate units; 263 independently matched on both hosts, 39 were held on both and one on Intel only. 619 retained units were outside the batch. The central review accepted 263 units, yielding 455 regenerated and 659 retained.

Primary evidence SHA256: `2be826b5423cd5c70a942e952b15f3601396ffc1c27b952b10843c98ac972ad3`

## CP792

Two independently generated PEXPERT configuration headers match historical bytes; ten formerly held platform units regenerate with 238 exact staged dependencies. 465 regenerated and 649 retained.

Primary evidence SHA256: `3b3b7ddb76bc127f0dc2e0f1fd17a877a59a87dd8c98e5e3ff954792c1396ac0`

## CP793

Inventory identifies 211 common original OSFMK recipe candidates. The initial two-unit probe is held on 46 dependencies; 42 regenerated configuration headers and four pinned libsa mappings resolve the gap. Two timekeeping units regenerate with 350 exact dependencies. 467 regenerated and 647 retained.

Primary evidence SHA256: `5dc8bbd512ce0df5de5cb8c9e210e51e4cc51dea3dbe14c2d9b524c2102d3b3f`

## CP794

The second batch covered 209 OSFMK candidates. Both hosts independently match 119 and hold 90; central comparison verifies matching object and ordered-dependency evidence. 438 retained units were outside the batch. 586 regenerated and 528 retained.

Primary evidence SHA256: `fd72f76dbc8fab45976e74b09cce5fa03d7a103284c21a2d1f75549644bd6000`

## CP795

An original shared generated resource notification header matches historical bytes independently on both hosts. Thirteen formerly held OSFMK units regenerate with 434 exact staged dependencies. 599 regenerated and 515 retained, including 77 remaining Batch 02 holds and 438 outside that batch.

Primary evidence SHA256: `1a4f5a0fdca7959103be935f272ac549c6893ce6974765b839148247dbc21a90`

## Next work

Resolve shared generated dependency gaps and expand verified source recipes. The last closed regular technical review remains CP497. The [dual-host batch build workflow](../../../docs/maintainers/dual-host-batch-build.md) is documented separately; portable tool source remains under review.
