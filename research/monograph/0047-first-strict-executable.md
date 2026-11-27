# 47. First strict Intel XNU executable link

**Date:** 2026-11-25
**Source checkpoint:** 68 (R0047)
**Scope:** Strict MH_EXECUTE closure; no boot or final runtime acceptance.

The original pinned root export, alias and symbolset generators were used to prepare final link metadata: 6,025 KPI lines, 101 alias lines and nine combined symbolsets in a 289,155-byte binary plist. The binary conversion was checked for semantic round-trip equality.

All 993 input hashes and architectures were revalidated. The actual ld64-711 executable link rejected undefined symbols rather than tolerating them. It exited zero and produced an x86_64 MH_EXECUTE with MH_NOUNDEFS, PIE and an empty undefined list. Size: 21,307,160 bytes; SHA256 75487040094e5c5a4733ec594cf49146b0644883c856abcd0bf0916c1d7b50fc. All eleven remaining layout/image names were resolved.

Two warnings were retained: the missing default Frameworks directory and a BSS alignment reduction. The static audit checked the actual entry, image identity, section protections, embedded symbolsets, KLD lifecycle records and final symbol placement. The observed BSS and relevant anchor met the larger alignment, but section metadata still required further audit. No full per-atom, loader/slide, ABI, actual boot, FKI or userspace qualification was established.

This was the first strict executable milestone, not a finished kernel. Prior relocatable baselines and the pinned source remained unchanged. The next volume begins with preboot layout and handoff qualification.

Historical source-record SHA256: `88b9ed99a98ec9079857b27b11873c7d210a2d6a6c0fdf83c9b65a39bcae708d`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
