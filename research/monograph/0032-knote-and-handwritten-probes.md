# 32. Darwin knote layout and five handwritten providers

**Date:** 2026-11-25
**Source checkpoint:** 53 (R0032)
**Scope:** Compiler layout, emitted IR and isolated object coverage.

The original kern_event C recipe produced a 128-byte knote record aligned to eight bytes. The initial C++ IR replay failed because incompatible output flags were combined; correcting them exposed three HeaderDoc diagnostics. A local header overlay isolated the mixed-storage bitfield diagnostic and corrected the misplaced access label without changing access or declarations. The pinned original remained unchanged.

The full C and C++ units and explicit seven-field fixtures agreed in member offsets and emitted read/write IR after normalizing debug information. This established the current compiler's Darwin layout, not a live kqueue test or equivalence to Apple's compiler.

Five exact-recipe objects compiled: RootDomainUserClient (292,024 bytes), TestIOMemoryDescriptor (680), IOPlatformExpert (500,312), IOUserClient (654,728) and IOKitBSDInit (308,408). The empty RELEASE test object was a configured target, not evidence of executed development tests. Logging corrections were type/format changes, not behavior changes.

The recorded PROBE-OBJECTS manifest verified 94 separate probes, bringing coverage to 963/984. The accepted 869-input link remained unchanged at 261 undefined. The next work concerned polled I/O, callback signatures and actual transport/lifetime contracts.

Historical source-record SHA256: `f52138f459b9f06bcca6de87bd39f270d905e2aa2d0a223be550e46daa2861c8`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
