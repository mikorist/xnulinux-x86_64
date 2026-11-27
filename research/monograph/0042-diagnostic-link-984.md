# 42. First complete 984-input diagnostic relocatable link

**Date:** 2026-11-25
**Source checkpoint:** 63 (R0042)
**Scope:** Strict input inventory and diagnostic MH_OBJECT link; not a boot.

All 984 distinct input paths were verified against recorded sizes, hashes and Mach-O headers. The static audit counted 25,150 externally defined names, 13,386 referenced names and four repeated weak definitions, with no multiple strong names. Nineteen distinct configured empty objects shared a hash and were retained rather than deduplicated.

The isolated ld64-711 relocatable link exited zero with the existing missing Frameworks directory warning. It produced a 19,273,568-byte MH_OBJECT, SHA256 4b815d80268fe5b203a88967fe1f8304ded5a58d0d1f541c237b4fe9dd0f77fd. The actual undefined set matched the static prediction: 221 resolved, 40 retained and three introduced, leaving 43. No target was removed or replaced with a stub.

Four critical aggregate startup, typed-allocation and constructor sections retained their byte and relocation totals. The 43 unresolved names were classified as 15 MIG, eight version, eleven layout, five Firehose and four runtime/toolchain. The accepted 869-input baseline was preserved. This diagnostic link included conditional probes and established neither behavioral ABI equivalence nor executable boot.

Historical source-record SHA256: `15fa27ba1fe5ab3adfb6715f13b6fcd5a671b8ecd8cb14c55d2acfb79ccc8dcb`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
