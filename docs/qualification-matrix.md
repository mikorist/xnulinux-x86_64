# Qualification matrix

Snapshot: research documentation through CP915, 2026-11-28. Last closed regular integration review: CP497. Historical component results retain their original scope. Results apply to the stated scope only. Parallel Intel/Ryzen development is active.

| Area | Recorded status | Remaining qualification |
| --- | --- | --- |
| Strict executable link | Confirmed | Clean public reproduction |
| Legacy clock | Standalone confirmed | Hardware and hosted timers |
| UEFI | Firmware probe only | XNU handoff and execution |
| Mach VM | Standalone bootstrap confirmed | Hosted memory, SMP |
| Scheduler | UP round trip confirmed | SMP and hosted execution |
| Mach IPC | Startup confirmed | User message exchange |
| IOKit | Core initialization confirmed | Complete live transport/drivers |
| PRNG | Diagnostic registration | Entropy and reseed qualification |
| Crypto | Diagnostic 40-slot registration | Full production security/ABI review |
| pthread | Static initialization | User synchronization ABI |
| HFS+ | Restricted read-only fixture mount/read, tested negative paths | General media, writable HFS and journal support |
| PID 1 / ring 3 | CP602: six strict Broadwell TCG UP standalone passes, owned signed Darwin test program | General userspace including launchd, full boot stability, hosted replay |
| FKI ordinary Linux services | Guest runtime and physical bounded CPL0 adapter confirmed | Cross-context integration |
| Original linked XNU PE instructions | Selected Mach-O bytes executed in Linux userspace on physical Intel | Privileged original Mach-O entry |
| Original XNU PE source components | Recompiled ELF subset executed in physical CPL0 | Complete XNU machine layer, pmap and scheduler |
| Intel transition mechanisms | Freestanding protected mapping and cooperative Linux tests | Full Linux-to-XNU world switch and exceptional paths |
| Linux host versions | Historical representative 6.0–6.19 suites; two-kernel private Git replay through 337 and component regression through 357 | Full hosted runtime, additional configurations and physical coverage |
| Split FKI memory service | Isolated guest and physical pair; bounded allocation/copy/cleanup | Fault injection and complete VM integration |
| XNU page ownership and primitives | Restricted original source and hosted zero/copy adapters pass physical CPL0 | Full native pmap and vm_page_copy semantics |
| FKI multi-session and alias lifetime | Physical four-CPU race tests and corrected warning gate | Independent XNU mappings, hardware TLB and fault injection |
| VM objects and resident hash | Restricted original source subsets pass physical CPL0 | General pager, ledger, native locks and concurrent kernel lookup |
| Empty-object final reference | Physical metadata allocation/free and selected original transitions | General deallocation/reaper and concurrent kernel references |
| Native object tickets/process isolation | Native userspace fixture and real FKI-backed process mappings in Linux guests | Production authorization, arbitrary mapping lifetime and independent XNU root |
| Inactive root and map ownership | Opaque hierarchy, source-backed reference and indexed map gates | Active hardware translations and complete native pmap |
| Boot metadata and PE | Actual linked header, original accessors, boot layout/seed on two kernels | Real native firmware/CPU boot handoff |
| Hosted clock/entropy | Negotiated live services, private PRNG and reload lifecycle | Native registration and production qualification |
| Startup and CPU/thread | Exact-layout records, private scalar/counter callbacks, stack geometry, zone record count and BSD argument data; four phase-1 records unbound | Native phase completion, task creation |
| Scheduler and timers | Original queue operations, joined cooperative workers, private runtime and transactional result tests | Native context switching, dispatch, IRQ integration |
| Hosted private IPC (earlier baseline) | Private shared metadata owner, 63-name capacity, unchanged exhaustion output, stale name rejection and drain | Real Mach ports, task adapter and native messaging |
| Hosted private task and ledger | Two-kernel component qualification through 357: reference-owned tasks, exclusive IPC metadata binding, ledger template and schema, constructor rollback | Native task, real IPC ports, active pmap and native scheduler remain open |
| Hosted private task/thread/IPC resources | Checkpoint 377: typed Linux caches, private reference and rollback checks, IPC geometry and metadata lifetime; two-kernel private Git replay | Native zones, task/thread creation, active pmap, real Mach IPC and dispatch remain open |
| Reference build reproduction | Checkpoint 397: 496-input isolated closure, 15 byte-identical Mach-O objects; 258/174-input dual-kernel private replay | Full source/toolchain rebuild, redistribution review and native execution remain open |
| Ryzen development environment | Independent dual-kernel builds, 94 strict marker groups under Broadwell-v2 TCG; actual Ryzen nested KVM component tests | Native AMD qualification and full hosted boot |
| AMD nested KVM component replay | Actual Ryzen nested KVM: 94/94 functional marker groups on both kernels; strict HOLD on SRSO warning | Hyper-V-specific clean strict replay |
| Native AMD Linux KVM component replay | CP460 strict 94/94 on both guests; SRSO Safe RET on host and guests | Guest TSA and CPU feature dependency; complete native AMD XNU runtime |
| Ryzen source toolchain | Independently rebuilt custom Clang 24; byte-identical 1,114-input executable using retained inputs | Clean full-source build and public reproduction |
| Cross-host OSFMK C reproduction | 290 original, four historical compatibility, three new strict reference objects match; byte-identical 297-object relocatable after canonical paths and input timestamps | Integrated MIG ABI, other subsystems and complete kernel link/runtime |
| Cross-compiler IPC/reference objects | Historical stock compiler limits superseded for the 15-unit custom Clang 24 closure; selected IPC layouts remain static evidence | Executable ABI and native runtime |
| Cross-host full executable | 1,089 exact selected inputs, identical strict Mach-O and Broadwell standalone PID 1 on both hosts | Independent regeneration of retained text inputs and public source review |
| AMD-aware early machine layer | Actual Milan TCG pre-admission discovery on both hosts; 1,092-input links, 35 matching sections; Intel full PID 1 regression | AMD admission and downstream machine services |
| AMD downstream machine metadata | CP495-v2: 1,109-input strict links, actual Milan TCG pre-admission on both hosts; full same-candidate Intel PID 1 CP497 | Actual AMD admission, FPU activation, MCA handling, memory-type ownership, timer activation and hosted runtime |
| Cross-host section reproducibility | CP495-v2: matching sections and symbols; CP562 and CP602 later achieve complete executable byte identity on both hosts | Clean public retained-input regeneration |
| AMD APIC/LLC and Darwin ABI | Linux guest membership masks and actual UP XNU previews; generic ARCH1 grading helper passes | Numeric legacy cache ID HOLD, XNU SMP, actual AMD exec |
| AMD startup lifecycle | Milan TCG UP: normal MCA, VM/bootstrap, UP CPU and FPU initialization, memory-type initialization and machine_init return observed | Complete clock lifecycle, CPU admission, AMD PID 1, SMP and hosted ownership |
| Native AMD SMCA inventory | CP525 native Linux: 16 logical CPUs, 448 sysfs attributes, 114 readable and 334 ENODEV | Physical XNU SMCA handling; attribute count is not hardware bank count |
| AMD RTC and timeout boundary | CP593/602 Milan TCG RTC and downstream feature-query boundary; CP611/612 isolated arithmetic tests pass | Full clock return and timer delivery; observation boundary is not proof of failed timeout routine |
| Commpage lifecycle | CP602-604: six strict Broadwell TCG UP passes after scoped initialization correction; original mapping API reports data R/R and text RX/RX | General stability, effective hardware permissions, SMP and AMD full boot |
| CP602 dependency provenance | CP607-610: 402 unique paths, 328 upstream content matches, 44 generated outputs matched, 27 inherited headers matched to predecessor | Original local authorship/licensing and clean full-source regeneration |
| CP616-620 build closure | Three independently compiled objects; exact 1,114-input relink with 1,111 retained inputs; compiler inputs and linker metadata verified; 1,069 exact CP444 object matches | Full clean-source regeneration and source/license clearance |
| Ordinary standalone boot observation | CP627: Broadwell TCG UP owned PID 1 marker PASS on diya (92.08s) and Ryzen (91.35s), identical artifacts, no prior devfs error or panic | Independent CPL measurement, Apple launchd, AMD-model admission, native and hosted boot remain HOLD |
| Complete Linux-hosted XNU | Not demonstrated | Actual hosted boot and userspace |
| Headless / desktop / seamless | Goals | End-to-end implementation |

The latest research checkpoint must be consulted before using this snapshot for a public status announcement.

The [project state manifest](../PROJECT-STATE.json) records the distinct current research, regular review, monograph and ordinary-boot boundaries. Twenty recorded 20-checkpoint windows through CP897 and 18 later records remain open; 418 primary hashes verified; verified evidence hashes are not equivalent to technical closure.

## Version target boundary

| Target | Current evidence | Open qualification |
| --- | --- | --- |
| Monterey 8020.140.41 | CP627 scoped Intel-model ordinary PID 1 PASS | AMD admission, native/hosted execution, clean-source build |
| Tahoe 12377 (active preparation; implementation gated) | CP631 descriptor; CP652 release mapping for 13 dependencies | Qualified target build, ABI, Intel/AMD runtime, native/hosted execution |
| Golden Gate 27 (research only) | No verified source pin or x86_64 build | Source availability, architecture and userspace feasibility; all qualification HOLD |

CP629: Monterey descriptor identity validation PASS on both hosts; no new build or runtime qualification.

CP630: 19 newly regenerated objects per host, 22 regenerated inputs in each exact 1,114-input relink; retained headers/toolchain and 1,092 other objects. Clean-source build and runtime qualification remain open.

CP632 verifies 13 Tahoe candidate source tag identities, but authoritative release association and tool compatibility remain HOLD; no Tahoe build or runtime.

CP633: clean public source structural validator regression PASS with GCC on both hosts and Clang on Ryzen; Intel Clang runtime dependency HOLD. No distribution qualification.

CP634: physical Intel Clang runtime repair and unmodified validator PASS; isolated MCP dependency HOLD. CP635: public Python verifier synthetic unit tests PASS on both development hosts. Distribution remains HOLD.

CP636: private source archive reproduction and unpacked tests PASS on both development environments; Python verifier copyright attribution and binary distribution HOLD.

CP637: four strict GCC builds pass 916 synthetic checks; each environment reproduces its own executable, cross-environment identity and Stage A release remain HOLD. Seven recorded review windows remain technically open.

CP638: self-contained source staging and historical CP335 Python source identity PASS; attribution and common pinned binary build HOLD.

CP639: six additional libkern source objects regenerated per host, 28 regenerated inputs in each exact relink; CP640: scoped Tahoe source/dependency comparison only. No runtime qualification change.

CP641: ARM post-kernel source inventory PASS; retained GPU/kext identity does not qualify x86 graphics, desktop, headless, or seamless execution. Component and transitive license closure remains open. See [platform reuse](post-kernel-platform.md).

CP641 plan approval is a documentation decision, not an additional technical result. Open runtime, software display, CPU Metal, host GPU backend, hosted GPU, desktop and seamless have independent future qualification. No new PASS is inferred from approval.

CP642: retained framebuffer helper passes six synthetic packed BGRA conversions and six truncated-input controls per host, with identical output hashes. Live display, stride support and GPU execution remain unqualified.

## CP643-755: scoped research results

- CP700: exact retained link on both hosts, 95 regenerated and 1,019 retained inputs; CP699: 91 independently staged units and 896 paths. Full clean-source reproduction and clearance remain HOLD.
- CP652-654: official release maps and selected device-header comparisons; source associations do not qualify a Tahoe build.
- CP644, CP661-689: synthetic framebuffer stride and numerical graphics checks; complete frameworks, licensing, live display and acceleration remain HOLD.
- CP745-747: scoped compiler frontend, ten code generation fixtures and original Blocks replay across both hosts; eight external imports remain in the Blocks group.
- CP739: six generic string objects linked with no unresolved imports, not a dynamic library. CP753: UUID relocatable group has four external imports. CP754: 249-header declaration stage; full SDK, dynamic linking and runtime remain HOLD.
- CP742-744: source-only archives reproduced; component-local verifier notice completed privately, scoped synthetic verifier contract passed. Public notice integration and release remain separate.
- CP755: shared preprocessed input produced byte-identical instrumented ELF objects; 229/229 native checks on each host. Independent preprocessing and final binaries differ; full common environment and Stage A release remain HOLD.

See [CP643-755 research update](../research/2026-11/updates-643-755/README.md). No new boot qualification or closed technical review is implied.

## CP756-775 scoped results

CP756-775: original Monterey declaration probes expose 18 missing generated userspace headers; retained-header Stage A preprocessing and object identities match, and source-built UBSan passes 916 unchanged fixture checks plus 24 arithmetic diagnostics. Native executable identity remains HOLD. CP771-775 independently regenerate 26 more kernel inputs (121 regenerated, 993 retained); the complete 1,114-input CP602 image remains byte-identical on both hosts. No new boot, full clean-source build, runtime, licensing or release qualification. [Research update](../research/2026-11/updates-756-775/README.md).

## CP776-795 scoped results

CP776-795: independent source regeneration and two local batch runs increased accepted regenerated inputs from 121 to 599 of 1,114; 515 remain retained. Both complete retained-input links match CP602. Shared generated-header blockers were resolved for selected groups; unresolved recipes and dependencies remain HOLD. No new boot, full clean-source build, runtime, licensing or release qualification. [Research update](../research/2026-11/updates-776-795/README.md).

## CP796-815 scoped results

CP796-815: accepted regenerated inputs increased from 599 to 692 of 1,114; 422 remain retained. Batch 02 completed all 209 candidates. Original C++ and assembly source staging advanced; derived-header provenance and historical assembler byte identity remain HOLD. Complete retained-input links match CP602 on both hosts. No new boot, full clean-source build, runtime, licensing or release qualification. [Research update](../research/2026-11/updates-796-815/README.md).

## CP816-835 scoped results

CP816-835: accepted regenerated inputs increased from 692 to 764 of 1,114; 350 remain retained. Historical assembler identities and residual Batch 01 recipes are resolved within their tested scope. Twelve historical UIO compatibility objects now match, while 17 distinct derived C++ dependency paths remain HOLD. Complete retained-input links match CP602 on both hosts. No new boot, full clean-source build, runtime, licensing or release qualification. [Research update](../research/2026-11/updates-816-835/README.md).

## CP836-855 scoped results

CP836-855: accepted regenerated inputs increased from 764 to 839 of 1,114; 275 remain retained. Historical IIG declarations and compatibility-header prerequisites are qualified within their tested scope, and all 64 CP811 original C++ candidates now match. Final build metadata and additional BSD objects also match. Complete retained-input links match CP602 on both hosts. No new boot, full clean-source build, runtime, licensing or release qualification. [Research update](../research/2026-11/updates-836-855/README.md).

## CP856-875 scoped results

CP856-875: accepted regenerated inputs increased from 839 to 920 of 1,114; 194 remain retained. Thirty-seven of forty HFS inputs match, and the first two bounded Batch 03 queues accept 23 original-source or existing project-authored objects. All complete retained-input links match CP602 on both hosts. Synthetic clock arithmetic passes; actual AMD clock return and timer delivery remain HOLD. No new boot, full clean-source build, runtime, licensing or release qualification. [Research update](../research/2026-11/updates-856-875/README.md).

## CP876-895 scoped results

CP876-895: accepted regenerated inputs increased from 920 to 1,012 of 1,114 (90.84%); 102 remain retained. All 38 historical MIG C source prerequisites match, with 35 corresponding objects admitted and three declaration compile failures held. Additional IOKit, CPU contract, libdispatch, compiler-rt, Mbed TLS and BearSSL objects match within their recorded scope. Complete retained-input links match CP602 on both hosts. Actual AMD clock return and timer delivery, full clean-source build, hosted runtime, source licensing and release remain HOLD. [Research update](../research/2026-11/updates-876-895/README.md).

## CP896-915 scoped results

CP896-915: accepted regenerated inputs increased from 1,012 to 1,050 of 1,114 (94.25%); 64 remain retained. Of the 1,050 regenerated inputs, 1,046 have independent source-stage evidence. Complete retained-input links match CP602 on both hosts. Scoped hosted userspace component and recovery regressions do not establish native XNU execution. AMD clock return and timer delivery, full clean-source build, hosted runtime, source licensing and release remain HOLD. [Research update](../research/2026-11/updates-896-915/README.md).

**A: Historical reproduction.** 1,050/1,114 regenerated inputs; 64 retained. This is CP602 byte identity, not product completion.

**B: Functional Monterey.** CP627 remains the Intel-model standalone owned Darwin PID 1 control. Actual AMD clock return, timer delivery and ordinary admission remain HOLD.

**C: Linux-hosted Monterey.** Primary architecture objective: bounded hosted kernel execution and dependable lifecycle/recovery, then a controlled project-owned Darwin program in that hosted context. CP899/900/911/912 are scoped userspace fixtures, not native hosted XNU. No execution architecture has been selected; A need not finish before eligible B/C work.

The public ARM64 FKI v0 header is a reference, not a qualified x86 ABI. Compare hosted execution models using compatibility, failure containment, maintainability, host ownership and existing evidence before choosing one; the historical shadow-CR3 proposal is a hypothesis. A versioned semantic host-service contract and version/vendor adapters are intended, not an implemented production interface.
