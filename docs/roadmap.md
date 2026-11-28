# Development roadmap

The sequence below reflects project priorities rather than release dates. The [project philosophy](project-philosophy.md) is XNU for the PC: reuse Linux hardware infrastructure, qualify Intel and AMD x86_64 systems in parallel, and avoid dependence on traditional Hackintosh setups.

| Stage | Acceptance criterion |
| --- | --- |
| Standalone reference | Root mount, file lookup/read, user-mode execution and traps |
| Shared Intel/AMD hosted integration | Verified FKI and world switch; memory, interrupts, SMP and lifecycle tests |
| Hosted Darwin | Root filesystem, userspace and executable programs on the hosted path |
| Headless | Repeatable CLI and service execution |
| Software display | Owned framebuffer, presentation and input |
| CPU graphics | Target-compatible software render/compute tests |
| Hardware GPU | Host backend, transport, hosted Vulkan/Metal and lifecycle independently qualified |
| Desktop | Compatible graphical environment with software rendering acceptable |
| Seamless | Individual application windows, input/focus and lifecycle integrated with Linux |
| Product readiness | Reproducible installation, compatibility matrix, recovery and regression tests |

The [standalone PID 1 milestone](../research/2026-11/boot/pid1-terminal-replay.md) and [ordinary FKI service tests](../research/2026-11/hosted/fki-host-services.md) are documented separately. Neither satisfies the actual hosted acceptance criteria. Subsequent [physical CPL0 component tests](../research/2026-11/hosted/physical-ring0.md) and [split memory service](../research/2026-11/hosted/split-memory-service.md) provide further bounded evidence. The physical module pair and restricted source-backed page/object/resident/final-reference tests have since passed. The bounded reference registry, real FKI-backed Linux process mappings, inactive root lifetime and indexed map paths have since passed in Linux guests. Boot metadata, clock/entropy and cooperative CPU/thread/queue/IPC gates are integrated through checkpoint 337 on two selected kernels, including canonical private Git replay, owned worker services and expanded private startup callback coverage. The next gates are genuine hosted bootstrap integration, unresolved task construction, native execution context/translation activation, startup dependencies and real Mach IPC. Native hosted boot is still not demonstrated. See [the scheduler and IPC report through 337](../research/2026-11/hosted/hosted-bootstrap-replay.md).

Through checkpoint 357, private task ownership and ledger construction have passed two-kernel component regression. Native resource allocation, real Mach IPC, execution context and startup integration remain the next gates. See the [task and ledger report](../research/2026-11/hosted/hosted-task-ledger.md).

Through checkpoint 377, private typed task/thread resources and IPC metadata lifecycle have passed canonical two-kernel replay. Native startup resource ownership, real IPC and native execution remain separate gates. See the [task, thread and IPC report](../research/2026-11/hosted/hosted-task-thread-ipc.md).

Through checkpoint 397, source provenance and reference reconstruction have advanced, with both canonical and minimal private runtime replays passing. Native IPC startup dependencies remain the next integration gate. See the [provenance and reproduction report](../research/2026-11/hosted/hosted-provenance-reproduction.md).

Hosted integration may proceed in parallel with standalone reference tests. GPU acceleration is not a prerequisite for the first kernel, headless runtime or basic desktop. Independent post-kernel source and host-only tests may proceed without changing the Monterey/Tahoe implementation gates. See the [approved platform reuse and adaptation backlog](post-kernel-platform.md).


## Subsequent x86_64 source target

One XNULINUX supports multiple version targets. Monterey remains the active baseline; Tahoe is an active development target; preparatory source analysis and version-matched build planning proceed in parallel. After stable physical Linux-hosted Monterey execution, implement and qualify Tahoe. Retain both targets and develop headless, desktop and seamless for both with shared compatible layers and per-version adapters. The exact Tahoe target pin and hardware/userspace requirements require separate qualification. No intermediate macOS version port is mandatory. Bounded preparation is recommended after CP630; the implementation gate remains stable physical Linux-hosted Monterey Intel execution. See [version-target entry plan](version-targets.md).

## Parallel Intel and AMD x86_64 development

The roadmap is for a complete PC compatibility platform, not merely a successful kernel boot. Machine-layer portability, cross-vendor regressions, safe host integration, Darwin runtime and application modes are distinct acceptance gates. See [platform scope and evidence](platform-scope.md).

The long-term platform scope includes both Intel and AMD x86_64 Linux PCs. Continue the Intel hosted baseline while developing AMD compatibility in parallel. Evaluate native AMD-aware XNU adaptation and, where necessary, a narrowly scoped compatibility view of CPU identity and capabilities presented to XNU. Select the approach through actual CPU, memory, interrupt, timing, scheduler and userspace tests. Preserve Linux host ownership and expose only capabilities that the hardware and implementation can support. No clean AMD hosted runtime or bare-metal qualification is claimed yet. Do not change the current Intel implementation sequence or source pins merely to announce this goal.

Use isolated AMD-model TCG guest regressions now, on Intel or the Ryzen 7 5700X WSL2 development environment. Progress through component and integrated tests in parallel with Intel, followed by separately qualified nested KVM and bare-metal AMD Linux tests. Do not wait for a complete Intel hosted boot to investigate AMD portability. Keep the two existing Linux kernel targets and add CPU models selectively. See [cross-vendor testing](testing.md#planned-cross-vendor-x86_64-test-strategy).

Through checkpoint 457, the full standalone reference executable is byte-identical across the two development hosts. The AMD-aware diagnostic reaches actual early CPU discovery under Milan TCG, while the new candidate preserves the Intel PID 1 baseline. Next qualify AMD-specific LBR/PMU, MCA, TSC, PAT/MTRR, commpage and topology before AMD admission. Keep strict SRSO qualification separate from functional development. See the [machine-layer report](../research/2026-11/hosted/amd-machine-layer.md).

CP497 closes the corrected 1,109-input candidate review: cross-host section equivalence, bounded topology, generic Darwin subtype grading, guarded XSAVE observation and local synthetic metadata refresh. Continue actual AMD initialization, FPU lifecycle and native/hosted ownership qualification; do not treat the pre-admission diagnostic as a boot. See the [topology and state report](../research/2026-11/hosted/topology-state-and-reproducibility.md).

CP477 extends early AMD discovery with independently tested clock, performance, MCA, memory-type, XSAVE, TLB, TSCI and MONITOR contracts. Continue required machine initialization, microcode/commpage and topology, with Intel full regression and explicit standalone versus hosted ownership. See the [follow-up report](../research/2026-11/hosted/amd-machine-layer-followup.md).

CP460 closes the native SRSO gate for the tested Ryzen Linux KVM component configuration. Guest TSA and CPU feature dependency are separate open items, as is Hyper-V SRSO exposure. Continue AMD machine-layer development; see [native AMD KVM qualification](../research/2026-11/hosted/native-amd-kvm.md).

## Current research boundary (CP875)

**Parallel priorities:** preserve CP627 Intel-model ordinary boot; close Monterey source regeneration and hosted/AMD gates; continue active Tahoe preparation; complete Stage A package review and common pinned native build; review outstanding technical windows in order. The approved post-kernel plan adds independent source/host-only preparation, not a requirement to finish graphics before kernel qualification.

Earlier Milan TCG UP observations establish machine_init return and the RTC/lock-timeout observation boundary; CP622 separately records the explicit unqualified admission rejection. CP602 is the current retained standalone candidate, with six strict Broadwell reference passes. Prior early discovery, normal MCA and UP/FPU lifecycle milestones are historical completed scoped tests rather than the immediate next tasks.

Next: establish the complete AMD clock lifecycle, timer delivery and CPU admission; progress toward full AMD standalone PID 1, retain Intel regression, then qualify SMP, physical and hosted execution separately. Continue source provenance and public reproducibility independently. See [current report](../research/2026-11/updates-856-875/README.md) and [earlier retained-link report](../research/2026-11/hosted/commpage-reproduction-599-612.md). CP613-620 establish additional offline and build reproducibility evidence, not a new boot. See [chronological outcomes](../research/2026-11/checkpoint-613-620.md). The regular technical review remains open from CP498; chronological documentation through CP875 does not close it.

Historical CP621: an independent completion-evidence gap was identified: four ordinary smoke launches time out without a validated completion marker. The subsequent CP626/627 Intel-model control resolves that scoped evidence gap; AMD qualification remains separate. No new AMD clock return or boot is qualified. [CP621 report](../research/2026-11/checkpoint-621.md).

The [project state manifest](../PROJECT-STATE.json) separates current research from the ordered technical-review backlog and source-build clearance. Technical acceptance does not depend on how quickly historical documents are published.

CP622 captures the ordinary serial console: Broadwell reaches BSD buffer initialization; Milan explicitly rejects unqualified AMD admission. Neither establishes ordinary PID 1 completion. Preserve admission requirements. Next qualify ordinary Intel completion independently. [CP622 report](../research/2026-11/checkpoint-622.md).

CP623 confirms that serial-only observation cannot validate the original silent PID 1 fixture. Next define a separate owned completion-output fixture and validate its acceptance evidence without changing CP602 or admission requirements. [CP623 report](../research/2026-11/checkpoint-623.md).

CP624 builds the separate console-reporting diagnostic identically on both hosts. The diya HFS image passes offline checks; matching boot preparation and runtime validation remain open. [CP624 report](../research/2026-11/checkpoint-624.md).

CP625 reports ordinary HFS root mount and init load attempt on diya without a debugger. The devfs mount fails with error 2; causal diagnosis and ordinary completion remain open. [CP625 report](../research/2026-11/checkpoint-625.md).

CP626 reports scoped ordinary Intel-model owned PID 1 completion on diya after correcting the missing /dev directory in a separate fixture. Cross-host replay and further qualification remain open. [CP626 report](../research/2026-11/checkpoint-626.md).

CP627 independently reproduces ordinary Intel-model console completion on Ryzen with the exact corrected fixture. AMD-model admission and hosted qualification remain separate. [CP627 report](../research/2026-11/checkpoint-627.md).

CP628 documents the initial public-source comparison: 165 common x86 paths, 98 identical blobs, 95.9% retained lines across common Monterey paths. No Tahoe build or runtime qualification. [CP628 report](../research/2026-11/checkpoint-628.md).

CP629 validates the first Monterey target descriptor against actual retained artifacts on both hosts. Generic build orchestration remains open. Current priorities: independent Monterey build-input regeneration and AMD qualification, followed by bounded Tahoe source preparation after the active series. The Tahoe implementation gate remains stable physical Linux-hosted Monterey Intel execution. [CP629 report](../research/2026-11/checkpoint-629.md).

CP630 completes the active work series with exact dual-host regeneration and retained-input relink. Begin bounded Tahoe preparation on Ryzen under the existing entry plan; Monterey remains active. [CP630 report](../research/2026-11/checkpoint-630.md).

CP631 records the Tahoe draft descriptor and upstream build-input inventory. Resolve version-matched open dependencies and tool availability next; the implementation gate remains unchanged. [CP631 report](../research/2026-11/checkpoint-631.md).

CP632 records provisional Tahoe dependency references. Confirm release mapping and audit public userspace tool readiness for CP637; no implementation gate change. [CP632](../research/2026-11/checkpoint-632.md).

CP633 verifies the public structural validator from clean source checkouts; three compiler/host runs pass, one Clang runtime dependency is missing. Continue the independent verifier replay before CP637 readiness assessment. [CP633](../research/2026-11/checkpoint-633.md).

CP634-635: physical Intel Clang dependency corrected and public Python verifier replayed on both development hosts. Next: Stage A source/license and packaging review before CP637; existing kernel gates unchanged. [CP635](../research/2026-11/checkpoint-635.md).

CP636 reproduces the source-only tools staging archive independently; resolve copyright attribution and binary reproducibility before any release. CP637 readiness assessment next. [CP636](../research/2026-11/checkpoint-636.md).

CP637 first Stage A readiness assessment: same-environment binary reproduction PASS, cross-environment identity and release HOLD. Resolve attribution, common pinned build recipe and package documentation, while continuing kernel research and ordered review. [CP637](../research/2026-11/checkpoint-637.md).

CP638 confirms self-contained source packaging and the retained Python source lineage. Prepare the common pinned build environment and resolve attribution before release; continue independent kernel research. [CP638](../research/2026-11/checkpoint-638.md).

CP639-640 complete the work series with scoped Monterey source regeneration and Tahoe dependency comparison. Continue Monterey source closure and hosted/AMD qualification, and separate Tahoe release mapping and generated headers. [CP639](../research/2026-11/checkpoint-639.md), [CP640](../research/2026-11/checkpoint-640.md).

CP641 records the [post-kernel platform reuse plan](post-kernel-platform.md): version-matched open runtime and device adapters, software display and rendering, isolated Linux GPU backend tests, then hosted acceleration, desktop and seamless integration. The owner approved this development direction after CP641; it is not a new qualification or change to the Tahoe implementation gate.

CP642 independently validates the retained offline framebuffer conversion helper on both x86 hosts; the next display prerequisite is a version-appropriate framebuffer contract, including stride. This does not change the Monterey hosted or Tahoe entry gates. [CP642](../research/2026-11/checkpoint-642.md).

## CP755 historical boundary

CP700 reproduces the exact CP602 executable with 95 regenerated and 1,019 retained inputs. CP745-747 establish scoped dual-host compiler and Blocks compile/link regressions; CP754 reaches 249 staged SDK headers. CP755 reproduces an instrumented object from one shared preprocessed input and passes 229 native checks per host; independent preprocessing and final binaries still differ.

Continue genuine Monterey locale and numeric conversion dependencies, independent source regeneration, common native build environment and AMD/hosted qualification; continue active Tahoe preparation and Golden Gate research-only feasibility and review open technical windows in order. For the open SDK and toolchain direction see [the approved plan](../research/2026-11/updates-643-755/sdk-direction.md). For graphics, continue scoped source/provenance and software rendering work; no live display or complete graphics framework is qualified. CP652 resolves the selected Tahoe release association, but Tahoe implementation remains gated on stable physical Linux-hosted Monterey Intel execution. Stage A still requires common native build reproduction, reviewed source packages and separate release approval. [CP643-755 research update](../research/2026-11/updates-643-755/README.md).

## Historical boundary CP775

CP756-775: original Monterey declaration probes expose 18 missing generated userspace headers; retained-header Stage A preprocessing and object identities match, and source-built UBSan passes 916 unchanged fixture checks plus 24 arithmetic diagnostics. Native executable identity remains HOLD. CP771-775 independently regenerate 26 more kernel inputs (121 regenerated, 993 retained); the complete 1,114-input CP602 image remains byte-identical on both hosts. No new boot, full clean-source build, runtime, licensing or release qualification.

Prioritize actionable existing HOLD prerequisites, including independent kernel source regeneration, genuine Monterey SDK declarations, common native build environment and AMD/hosted qualification; review the oldest open technical window. Continue Tahoe preparation and Golden Gate feasibility research without changing implementation gates. [Research update](../research/2026-11/updates-756-775/README.md).

## Current work after CP875

Latest evidence: CP856-875: accepted regenerated inputs increased from 839 to 920 of 1,114; 194 remain retained. Thirty-seven of forty HFS inputs match, and the first two bounded Batch 03 queues accept 23 original-source or existing project-authored objects. All complete retained-input links match CP602 on both hosts. Synthetic clock arithmetic passes; actual AMD clock return and timer delivery remain HOLD. No new boot, full clean-source build, runtime, licensing or release qualification. [Research update](../research/2026-11/updates-856-875/README.md).
