# Changelog

## Unreleased

There is no x86_64 product release represented by this document. The entries below distinguish recorded research milestones from integrated, supported functionality.

### Target planning (2026-11-27)

- Tahoe designated active development (preparation; implementation gate unchanged). Golden Gate 27 added as research only. No new technical checkpoint, qualification or release.

### Research milestones (2026-11-25)

- First strict diagnostic x86_64 Mach-O executable: 993 inputs and zero undefined symbols.
- Actual standalone kernel entry, early startup, virtual memory and Mach IPC initialization observed.
- Standalone uniprocessor scheduler round trip and natural kernel timer interrupt/return observed.
- IOKit initialization and BSD pre-root progression recorded.
- Restricted diagnostic PRNG and complete crypto-table registration exercised; production qualification remains open.
- First read-only HFS+ root mount reproduced with the actual root vnode installed.
- Integer-only HFS sizing regression and named file read verified in standalone QEMU.

- Standalone native PID 1, BSD syscalls and Mach traps reproduced with terminal-only debugger observation.
- Restricted read-only HFS fixture operations and rejection paths verified from userspace and the native handler.
- Independent FKI ordinary Linux-context module lifecycle, local bootstrap packet and concurrent ownership tests passed in isolated Linux guests.

- Freestanding CR3/IST/GS transition and protected-page fault tests; negative controls and cooperative Linux SMP/NMI regression.
- Selected original linked XNU PE instructions executed in Linux userspace, including on physical Intel hardware.
- Bounded Kbuild adapter and original XNU PE source components executed at CPL0 on the physical Intel development host; controlled normal unload verified.
- Five scoped test suites passed on representative Linux 6.0–6.19 kernels; additional current Liquorix guest tests recorded.
- Separate GPL FKI provider and APSL PE client passed the bounded memory service tests in 22 guest boots.

- Physical split FKI/APSL memory service and original XNU page initialization/zero/partial-copy source subsets qualified in bounded contexts.
- Multi-session SMP tests and real Linux mapping lifecycle races passed; checkpoint 205 clean-pass claim withdrawn and superseded by corrected 206 with stronger warning detection.
- Restricted original XNU VM object/reference/resident hash paths and empty-object final-reference release passed scoped physical CPL0 tests.
- Native Linux userspace reference tickets and actual process address-space isolation passed separate tests, not yet integrated into a hosted XNU address space.

### Research milestones (2026-11-26)

- Checkpoints 478-497: commpage ERMS and microcode provenance, APIC/LLC membership, generic Darwin subtype grading, guarded enabled XSAVE observation and synthetic post-activation metadata refresh. Corrected embedded source paths and premature SIMD code generation; independent 1,109-input strict links, all 35 section contents and 47,220 non-STAB tuples match, actual Milan TCG pre-admission and full same-candidate Intel PID 1 PASS. Complete binary identity, AMD admission and hosted runtime remain open. Documentation-only increment.

- Checkpoints 458-477: vendor-aware clock, optional performance services, read-only MCA/PAT/MTRR snapshots, physical-width bounds, XSAVE and TLB projection, invariant TSC correction and MONITOR geometry validation. Independent strict 1,102-input links and Milan TCG pre-admission checks pass; full Intel PID 1 regression through CP475. Native CP460 SRSO PASS remains scoped; guest TSA, Hyper-V SRSO, full AMD admission and hosted boot remain open. Documentation-only increment.

- Real FKI-backed process mappings and typed lifetime tickets, including inherited mappings and external page references.
- Inactive ownership hierarchy, cancellation negative control, stale generation and concurrent leaf retirement.
- Native source-backed indexed VM map ownership and integrated actual Mach-O boot metadata.
- Private calendar/entropy/PRNG negotiation, runtime retirement and two-kernel reload regression.
- Original startup, native-layout CPU/thread/processor records, priority queues, cooperative continuations, running timers and private IPC integrated through checkpoint 317.
- Current Linux regression reduced to two exact kernels; historical matrices preserved.
- Checkpoints 318-337: explicit-input private Git replay, shared worker service lifecycle and result rollback, expanded private startup callbacks, and final two-kernel replay of 191 inputs. Public standalone evidence verifier and scoped report added; full candidate remains held for review.
- Checkpoints 338-357: private task ownership and rollback, retained ledger templates and 60 source-backed keys, two-kernel qualification of 227 inputs, and byte-identical regeneration of 90 outputs using retained reference objects. Full candidate remains held for source and build review.
- Checkpoints 358-377: private task and thread typed resources, admission and rollback, IPC size geometry, selected-field layout and retirement guards; 255-input two-kernel Git replay and 111-output extraction replay. Full source remains held for provenance and licensing review.
- Checkpoints 378-397: source notice restoration and provenance verification, 117-output regeneration, 15 byte-identical native reference objects, 1,089-input relink comparison, dual-kernel canonical and minimal runtime replays, and initial CPU vendor probe. Full source remains on HOLD.
- Checkpoints 398-417: Ryzen build environment and dual-kernel component replay, independent config/MIG/cctools reproduction, 496 exact reference inputs, cross-compiler object and IPC comparisons. Strict AMD runtime, custom Clang 24 and full hosted boot remain open.
- Checkpoints 418-437: independently source-built custom Clang 24, 297 selected OSFMK C objects and byte-identical relocatable link across Intel/Ryzen; actual Ryzen nested KVM 94/94 functional groups on both kernels, strict SRSO HOLD. No full hosted boot or public source release.
- Checkpoints 438-457: byte-identical full 1,089-input executable across Intel/Ryzen; standalone Broadwell PID 1 replay on both hosts; AMD-aware early XNU discovery under Milan TCG, 35 matching final sections of the separate candidate, and full Intel regression. AMD admission and strict SRSO qualification remain HOLD; source export remains held.
- Checkpoint 460 (early documentation update): native Ryzen Linux KVM CP426 component replay strict 94/94 on both selected kernels, SRSO Safe RET. Guest TSA and CPU feature dependency remain open; original aggregate HOLD retained. No full AMD XNU boot or source release.
- Public repository renamed and ARM-only deployment retired; original reference branch preserved.

See the [kernel image history](docs/kernel-history.md), [research journal](research/README.md) and [qualification matrix](docs/qualification-matrix.md).

### Research milestones (2026-11-26 to 2026-11-27, selected documentation through CP612)

- CP498-555: AMD-model MCA, bootstrap, pmap/VM, zone, credential and MAC startup progress; native Ryzen Linux SMCA inventory recorded separately at CP525.
- CP556-598: byte-identical 1,114-input image and canonical loader, strict Intel gate rejecting 19 negative controls; Milan UP/FPU, memory-type and machine lifecycle advances to the RTC observation boundary.
- CP599-612: scoped commpage initialization correction, six strict CP602 Broadwell TCG UP passes, dependency and patch provenance audit, all 44 generated dependencies matched, isolated timeout and fixed-point arithmetic tests pass on both hosts.
- Historical integrity audit and maintainer-reported AI tooling interruption documented. Selected documentation-only updates; regular review remains CP497, full source and AMD admission remain held.

### Research and documentation (2026-11-27, CP613-621)

- CP613-620: retained clock calibration, source/header lineage and independent three-object regeneration; exact 1,114-input relink with retained inputs, compiler identity and final metadata reproduction.
- CP621: four observer-free smoke launches reach loader metadata but no independent completion marker within eight seconds; ordinary boot completion remains HOLD. Six earlier observed Intel passes retain their scope.
- Consolidated current project status and technical review queue, separately from historical monograph coverage. No new source qualification or release.

### Research milestones (CP622-629)

- CP622-625: corrected console capture, documented silent fixture and separate console-reporting owned PID 1 diagnostic; ordinary root mount and devfs error retained.
- CP626-627: ordinary Intel-model owned PID 1 completion without debugger on both development hosts, identical retained artifacts.
- CP628: Monterey/Tahoe source comparison and approved extensible multi-version direction.
- CP629: first Monterey target descriptor validated offline on both hosts, nine negative controls rejected each. No generic build orchestration or Tahoe runtime qualification.

### Research milestones (CP630-641)

- CP630/639: exact retained Monterey link reproduced with 28 regenerated and 1,086 retained inputs by CP639.
- CP631/632/640: Tahoe research descriptor, provisional dependency references and utility source/dependency comparison; no Tahoe build qualification.
- CP633-638: public component test replays, scoped Clang runtime repair, reproducible source staging and same-environment binary reproduction. Attribution, common pinned binary reproduction and release approval remain open.
- CP641: retained ARM platform inventory and approved post-kernel development direction; no source import, runtime or graphics qualification.

### Not established by these milestones

Complete physical Linux-hosted XNU boot and world switch, a complete Darwin application runtime, desktop or seamless integration, general hardware compatibility and an end-user installer.

### Documentation

An English developer reference, research index, architecture decisions and reproducibility methodology are being prepared for review. Historical research records are not release tags or claims of upstream integration.

Future entries should describe actual integrated changes by release or Unreleased section; avoid listing every diagnostic build as a released feature.

- CP642: independent synthetic framebuffer conversion replay on both x86 development environments; no display or GPU qualification.

### Research documentation (CP643-755)

- Published chronological research summaries of all 113 recorded outcomes, including failures and HOLDs, with primary evidence digests.
- CP700 reproduces the exact CP602 executable with 95 regenerated and 1,019 retained inputs. CP745-747 establish scoped dual-host compiler and Blocks compile/link regressions; CP754 reaches 249 staged SDK headers. CP755 reproduces an instrumented object from one shared preprocessed input and passes 229 native checks per host; independent preprocessing and final binaries still differ.
- Complete AMD boot, physical hosted XNU, clean-source build, full SDK/runtime, graphics and release remain HOLD. This increment changes documentation and the public status snapshot only; no source integration, release or regular technical review closure.

[CP643-755 research update](research/2026-11/updates-643-755/README.md).

## Research through CP775

CP756-775: original Monterey declaration probes expose 18 missing generated userspace headers; retained-header Stage A preprocessing and object identities match, and source-built UBSan passes 916 unchanged fixture checks plus 24 arithmetic diagnostics. Native executable identity remains HOLD. CP771-775 independently regenerate 26 more kernel inputs (121 regenerated, 993 retained); the complete 1,114-input CP602 image remains byte-identical on both hosts. No new boot, full clean-source build, runtime, licensing or release qualification. [CP756-775 research update](research/2026-11/updates-756-775/README.md).

## Research through CP795

CP776-795: independent source regeneration and two local batch runs increased accepted regenerated inputs from 121 to 599 of 1,114; 515 remain retained. Both complete retained-input links match CP602. Shared generated-header blockers were resolved for selected groups; unresolved recipes and dependencies remain HOLD. No new boot, full clean-source build, runtime, licensing or release qualification. [CP776-795 research update](research/2026-11/updates-776-795/README.md). Added [dual-host batch build workflow](docs/maintainers/dual-host-batch-build.md); portable code not yet published.

## Research through CP815

CP796-815: accepted regenerated inputs increased from 599 to 692 of 1,114; 422 remain retained. Batch 02 completed all 209 candidates. Original C++ and assembly source staging advanced; derived-header provenance and historical assembler byte identity remain HOLD. Complete retained-input links match CP602 on both hosts. No new boot, full clean-source build, runtime, licensing or release qualification. [CP796-815 research update](research/2026-11/updates-796-815/README.md).

## Research through CP835

CP816-835: accepted regenerated inputs increased from 692 to 764 of 1,114; 350 remain retained. Historical assembler identities and residual Batch 01 recipes are resolved within their tested scope. Twelve historical UIO compatibility objects now match, while 17 distinct derived C++ dependency paths remain HOLD. Complete retained-input links match CP602 on both hosts. No new boot, full clean-source build, runtime, licensing or release qualification. [CP816-835 research update](research/2026-11/updates-816-835/README.md).

## Research through CP855

CP836-855: accepted regenerated inputs increased from 764 to 839 of 1,114; 275 remain retained. Historical IIG declarations and compatibility-header prerequisites are qualified within their tested scope, and all 64 CP811 original C++ candidates now match. Final build metadata and additional BSD objects also match. Complete retained-input links match CP602 on both hosts. No new boot, full clean-source build, runtime, licensing or release qualification. [CP836-855 research update](research/2026-11/updates-836-855/README.md).

## Research through CP875

CP856-875: accepted regenerated inputs increased from 839 to 920 of 1,114; 194 remain retained. Thirty-seven of forty HFS inputs match, and the first two bounded Batch 03 queues accept 23 original-source or existing project-authored objects. All complete retained-input links match CP602 on both hosts. Synthetic clock arithmetic passes; actual AMD clock return and timer delivery remain HOLD. No new boot, full clean-source build, runtime, licensing or release qualification. [CP856-875 research update](research/2026-11/updates-856-875/README.md).

## Research through CP895

CP876-895: accepted regenerated inputs increased from 920 to 1,012 of 1,114 (90.84%); 102 remain retained. All 38 historical MIG C source prerequisites match, with 35 corresponding objects admitted and three declaration compile failures held. Additional IOKit, CPU contract, libdispatch, compiler-rt, Mbed TLS and BearSSL objects match within their recorded scope. Complete retained-input links match CP602 on both hosts. Actual AMD clock return and timer delivery, full clean-source build, hosted runtime, source licensing and release remain HOLD. [CP876-895 research update](research/2026-11/updates-876-895/README.md).

## Research through CP915

CP896-915: accepted regenerated inputs increased from 1,012 to 1,050 of 1,114 (94.25%); 64 remain retained. Of the 1,050 regenerated inputs, 1,046 have independent source-stage evidence. Complete retained-input links match CP602 on both hosts. Scoped hosted userspace component and recovery regressions do not establish native XNU execution. AMD clock return and timer delivery, full clean-source build, hosted runtime, source licensing and release remain HOLD. [CP896-915 research update](research/2026-11/updates-896-915/README.md).

## Research through CP935

CP916-935: accepted regenerated inputs increased from 1,050 to 1,071 of 1,114 (96.14%); 43 remain retained. Of the 1,071 regenerated inputs, 1,067 have independent source-stage evidence. Complete retained-input links match CP602 on both hosts. All 20 checkpoints advance historical reproduction; no new boot or runtime qualification. AMD clock return and timer delivery, full clean-source build, native hosted execution, source licensing and release remain HOLD. [CP916-935 research update](research/2026-11/updates-916-935/README.md).
