# Chronological development log: CP613-620

This log records successful, unsuccessful and incomplete work in checkpoint order. Results are scoped to the actual evidence; a failed or incomplete experiment is not a qualified implementation. Private evidence remains in the project archive.

The CP602 standalone baseline remains unchanged. No new guest execution or physical AMD boot was performed in this interval.

## CP613: Audit retained dual-host AMD clock calibration evidence

**Status:** PASS (offline audit); clock lifecycle HOLD.

2026-11-27T10:06:16+01:00 Independent offline recomputation matches CP603 measured clock packet medians, bus conversion and RTC maximum on both hosts. TSC sample spreads 76/70 ppm, APIC 149/143 ppm. Original source review separates incomplete clock_init return from successful earlier calibration; remaining timer configuration, resynchronization and delivery unqualified. No new guest execution, kernel changes or policy changes.

Archived evidence SHA-256: `f798176eb1d16068ee9dc34383ce0d93b75b756cda014709c9916ff4a0324b40`.

## CP614: Verify inherited header historical provenance and license markers

**Status:** PASS (retained header provenance); license clearance open.

2026-11-27T10:08:15+01:00 Both hosts independently locate the same earliest numbered retained candidate containing exact bytes of all 27 local dependency headers, CP450-589. Every header carries BSD-2-Clause SPDX; common manifest byte-identical; all 27 associated historical checkpoint evidence hashes verified centrally. Local candidate copy counts differ by one and are retained separately. This is not original authorship or full license clearance, new runtime qualification or source modification.

Archived evidence SHA-256: `179239a487da8ee5274cf0969ea636eb953d4b9a2b977f7263195f207b6c5cc9`.

## CP615: Classify abandoned historical lock clock candidate against current baseline

**Status:** HOLD (historical candidate); inventory PASS.

2026-11-27T10:12:37+01:00 Read-only inventory confirms lock-vmm-594 retained link/static checks and exact recorded source/object/image hashes; 1114 ordered input paths match CP593 and CP602. Historical candidate differs from CP593 by two objects, while CP602 differs by one separate commpage object. No runtime evidence found or corresponding Ryzen candidate; interruption cause unconfirmed. Historical candidate remains HOLD and is not promoted or reused. Current CP602 baseline preserved. No kernel execution or protection changes.

Archived evidence SHA-256: `78b387dfe0edc0594a40a8ecaceec79d65bbb66500333e7e413fe7c3a413d948`.

## CP616: Independently regenerate three current candidate objects from retained source

**Status:** PASS (object compilation).

2026-11-27T10:15:46+01:00 Both hosts independently compile unchanged CP602 commpage.c and CP593 cpuid.c and rtclock_native.c using exact retained compiler commands with only output and dependency paths redirected. All six compiler runs exit0; each object byte-identical to retained baseline and cross-host peer; aggregate result SHA256 identical. No source edits, relink, runtime or policy change. Retained original candidate untouched.

Archived evidence SHA-256: `7d12d63410a02526cbf3cd0305cb143893e9a9c4e194ba1ab41a9aeac1c1c925`.

## CP617: Reproduce complete CP602 kernel with freshly regenerated candidate objects

**Status:** PASS (executable relink).

2026-11-27T10:16:30+01:00 Both hosts independently stage all 1114 ordered inputs into separate output trees, substituting three fresh CP616 objects and retaining 1111 exact prior inputs. Original strict link commands exit0 and reproduce entire unstripped kernel SHA256 49d24b6512f178a5d9b19dfd7f10946f936f78c7725e1a7e6e2f8089055720b2. Input manifests and result hashes match across hosts. Not clean full-source build, new runtime qualification or policy change. Baseline untouched.

Archived evidence SHA-256: `c2d55609f10d36a024bd8392806bde072114533c30224f988551205593e7613a`.

## CP618: Qualify actual installed compiler source and resource header identity

**Status:** PASS (toolchain identity).

2026-11-27T10:23:14+01:00 Both hosts independently verify LLVM pin, exact UniXNU patch by reverse-check, identical hashes of nine modified source files and all 290 installed resource headers; common manifest byte-identical. Actual installed Clang and ld64-711 binaries fingerprinted separately, distinct build binaries not equated. No fresh toolchain build, runtime or policy qualification.

Archived evidence SHA-256: `631128d26a45cf8e729394b66fd0c9704888fe4ebf74ad14725e26fb8a923594`.

## CP619: Regenerate both final linker metadata inputs from pinned XNU source

**Status:** PASS (metadata regeneration).

2026-11-27T10:24:26+01:00 Both hosts independently replay the original metadata generation procedure from the pinned XNU exports and plist templates. All 21 subprocesses exit0; 6025 export lines, 101 aliases, nine symbolsets, 289155-byte binary plist. Both final auxiliary inputs byte-identical to retained CP444 inputs used by CP602; common result and source manifests match. Original sources and candidates untouched; no runtime claim.

Archived evidence SHA-256: `efa4fe6db2ad31dc2be65c417aec4786e7762209a3973a5b0a054af5168243e8`.

## CP620: Quantify complete retained CP602 input lineage against canonical CP444

**Status:** PASS (binary lineage inventory); AMD boot HOLD.

2026-11-27T10:24:55+01:00 Both hosts independently hash all 1089 canonical CP444 and 1114 current CP602 ordered objects. One-to-one hash-multiset comparison finds 1069 exact byte matches, 45 unmatched current and 20 unmatched old inputs; complete manifests and results identical. Scope is retained binary inventory only, not semantic equivalence or clean-source regeneration. CP611-620 series completed; AMD clock lifecycle and full boot remain HOLD, no kernel or host changes.

Archived evidence SHA-256: `e0da8c638b63ec430a7ccc297a9f15d2c26697ccd1b37bb1ddf95f2db740c0db`.

## Outstanding work

AMD clock lifecycle and full boot remain unqualified. A full clean-source build and remaining source/license review are open. Historical or failed candidates are not merged merely because their results are published.
