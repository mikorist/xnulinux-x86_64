# CP624: Independent console-reporting PID 1 fixture

**Outcome: PASS (fixture build and offline validation); runtime HOLD.** November 27, 2026.

Both development hosts independently assembled, linked and ad hoc signed an owned standalone Darwin diagnostic with distinct console success and failure reports following ordinary PID, UID and Mach task checks. The executable and offline validation manifests are byte-identical. Both signature code pages match, no dynamic library imports are present, and no segment has writable-executable initial permissions. This is not a runtime trust verdict.

A separate HFS Plus image on diya passes read-only filesystem verification; the extracted executable matches the built executable exactly. Ryzen lacks fsck.hfsplus on PATH. The default framework-directory linker warning remains recorded. The original CP602 kernel and root image remain unchanged.

Next: prepare the separate matching boot fixture and validate ordinary Intel completion. No new loader or guest run has been performed. AMD admission requirements remain unchanged.

Archived evidence SHA-256: `e873daa42067fb3a3841a29e836c107f9668bba810d2803dfaa280e435a2ba00`.
