# 43. Original final-build providers and the 988-input link

**Date:** 2026-11-25
**Source checkpoint:** 64 (R0043)
**Scope:** Four original final-build objects and diagnostic relocatable link.

Four real final-build objects were reconstructed from the pinned rules: version, lastkerneldataconst, lastkernelconstructor and nonlto. The original version generator produced Darwin 21.6.0 metadata rather than fabricated globals; the adapted compile recipe was documented as such. The constructor and final data placement followed the retained build-rule evidence. The missing host section-routing utility was represented by a narrow equivalent transformation, not a general replacement.

All four objects compiled and the validated 988-input relocatable link exited zero. Its size was 19,291,788 bytes and SHA256 5ee51b2790a9b517c77b8d6b2f0c896446b12e69bf346bdfb76b4a10397e298e. Eight version symbols and the final kernel symbol resolved: 43 undefined became 34, with none introduced.

Section inspection confirmed the original final 4,096-byte padding and the expected last-data constructor section. Final executable mapping, constructor execution, protection and final address semantics were still unverified.

The remaining groups were 15 MIG names, ten linker layout names, five Firehose and four runtime/toolchain symbols. The previous diagnostic and accepted baselines remained untouched.

Historical source-record SHA256: `ad0eee425a9345cb4531c7ff9227288136172ff9e8d21bd516914439cc089505`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
