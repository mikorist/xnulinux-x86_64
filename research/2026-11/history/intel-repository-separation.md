# Establishing the independent Intel repository identity

**Date:** 2026-11-26  
**Scope:** Public repository history, not technical qualification.

The existing fork was renamed to [mikorist/xnulinux-x86_64](https://github.com/mikorist/xnulinux-x86_64), retaining its GitHub identity and parent [AFK-surf/xnulinux](https://github.com/AFK-surf/xnulinux). Local origin was updated, upstream remained unchanged. The original ARM implementation is preserved at [arm64-reference](https://github.com/mikorist/xnulinux-x86_64/tree/arm64-reference), commit `7ed7153bd34b4d906a0f02320efc774850d5a5b0`.

The [original progress comment](https://github.com/AFK-surf/xnulinux/issues/10#issuecomment-7174745326) was amended at the top to announce the new name and link, retaining its original technical snapshot. The archived comment preserves the original November 25 technical snapshot.

- [d0f4603](https://github.com/mikorist/xnulinux-x86_64/commit/d0f46038c1ec27e447e76b6ef9c53a22085da92d): replaced main README with Intel-specific status through checkpoint 311.
- [51334cd](https://github.com/mikorist/xnulinux-x86_64/commit/51334cd5afb1225044aae57d19ac04d1a1a64171): retired ARM-specific deployment, CI, screenshots, entry paths, patches and tests. Both main and x86_64-port were verified at this commit; local fork fast-forwarded cleanly. Original history retained, no force push.

69 inherited files were removed, one inventory document added and README updated (243 to 175 tracked files). The 68 graphics files, kexts and original license files were retained unchanged. GPU support is not yet designed or qualified for Intel, NVIDIA or AMD hardware. The retained mixed loader, FKI, crypto, device and graphics sources need individual ABI/provenance review; this is not a buildable Intel release. Local research is separate from the public tree.

## Related community research

[Upstream PR #37](https://github.com/AFK-surf/xnulinux/pull/37), opened by jeiel85 on November 26, describes a read-only CPU probe and AMD Ryzen 7 250 measurements on Windows 11 under the Microsoft Hyper-V view. It is an external research reference, not an Intel project contribution or evidence of AMD XNU boot. Linux execution was not tested. No decision to add AMD support follows from this report.

The public repository and its README were updated separately from this local research publication. No later Intel source release or publication export is implied.
