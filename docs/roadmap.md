# Development roadmap

The sequence below reflects project priorities rather than release dates. The [project philosophy](project-philosophy.md) is XNU for the PC: reuse Linux hardware infrastructure, qualify Intel and AMD x86_64 systems in parallel, and avoid dependence on traditional Hackintosh setups.

| Stage | Acceptance criterion |
| --- | --- |
| Standalone reference | Root mount, file lookup/read, user-mode execution and traps |
| Shared Intel/AMD hosted integration | Verified FKI and world switch; memory, interrupts, SMP and lifecycle tests |
| Hosted Darwin | Root filesystem, userspace and executable programs on the hosted path |
| Headless | Repeatable CLI and service execution |
| Desktop | Compatible graphical environment; software rendering first |
| Seamless | Individual application windows integrated with Linux |
| Product readiness | Reproducible installation, compatibility matrix, recovery and regression tests |

The [standalone PID 1 milestone](../research/2026-11/boot/pid1-terminal-replay.md) and [ordinary FKI service tests](../research/2026-11/hosted/fki-host-services.md) are documented separately. Neither satisfies the actual hosted acceptance criteria. Subsequent [physical CPL0 component tests](../research/2026-11/hosted/physical-ring0.md) and [split memory service](../research/2026-11/hosted/split-memory-service.md) provide further bounded evidence. The physical module pair and restricted source-backed page/object/resident/final-reference tests have since passed. The bounded reference registry, real FKI-backed Linux process mappings, inactive root lifetime and indexed map paths have since passed in Linux guests. Boot metadata, clock/entropy and cooperative CPU/thread/queue/IPC gates are integrated through checkpoint 337 on two selected kernels, including canonical private Git replay, owned worker services and expanded private startup callback coverage. The next gates are genuine hosted bootstrap integration, unresolved task construction, native execution context/translation activation, startup dependencies and real Mach IPC. Native hosted boot is still not demonstrated. See [the scheduler and IPC report through 337](../research/2026-11/hosted/hosted-bootstrap-replay.md).

Through checkpoint 357, private task ownership and ledger construction have passed two-kernel component regression. Native resource allocation, real Mach IPC, execution context and startup integration remain the next gates. See the [task and ledger report](../research/2026-11/hosted/hosted-task-ledger.md).

Through checkpoint 377, private typed task/thread resources and IPC metadata lifecycle have passed canonical two-kernel replay. Native startup resource ownership, real IPC and native execution remain separate gates. See the [task, thread and IPC report](../research/2026-11/hosted/hosted-task-thread-ipc.md).

Through checkpoint 397, source provenance and reference reconstruction have advanced, with both canonical and minimal private runtime replays passing. Native IPC startup dependencies remain the next integration gate. See the [provenance and reproduction report](../research/2026-11/hosted/hosted-provenance-reproduction.md).

Hosted integration may proceed in parallel with standalone reference tests. GPU acceleration is not a prerequisite for the first kernel or headless runtime.


## Subsequent x86_64 source target

One XNULINUX supports multiple version targets. Monterey remains the active baseline; Tahoe preparatory source analysis may proceed in parallel. After stable physical Linux-hosted Monterey execution, implement and qualify Tahoe. Retain both targets and develop headless, desktop and seamless for both with shared compatible layers and per-version adapters. The exact Tahoe target pin and hardware/userspace requirements require separate qualification. No intermediate macOS version port is mandatory. Bounded preparation is recommended after CP630; the implementation gate remains stable physical Linux-hosted Monterey Intel execution. See [version-target entry plan](version-targets.md).

## Parallel Intel and AMD x86_64 development

The roadmap is for a complete PC compatibility platform, not merely a successful kernel boot. Machine-layer portability, cross-vendor regressions, safe host integration, Darwin runtime and application modes are distinct acceptance gates. See [platform scope and evidence](platform-scope.md).

The long-term platform scope includes both Intel and AMD x86_64 Linux PCs. Continue the Intel hosted baseline while developing AMD compatibility in parallel. Evaluate native AMD-aware XNU adaptation and, where necessary, a narrowly scoped compatibility view of CPU identity and capabilities presented to XNU. Select the approach through actual CPU, memory, interrupt, timing, scheduler and userspace tests. Preserve Linux host ownership and expose only capabilities that the hardware and implementation can support. No clean AMD hosted runtime or bare-metal qualification is claimed yet. Do not change the current Intel implementation sequence or source pins merely to announce this goal.

Use isolated AMD-model TCG guest regressions now, on Intel or the Ryzen 7 5700X WSL2 development environment. Progress through component and integrated tests in parallel with Intel, followed by separately qualified nested KVM and bare-metal AMD Linux tests. Do not wait for a complete Intel hosted boot to investigate AMD portability. Keep the two existing Linux kernel targets and add CPU models selectively. See [cross-vendor testing](testing.md#planned-cross-vendor-x86_64-test-strategy).

Through checkpoint 457, the full standalone reference executable is byte-identical across the two development hosts. The AMD-aware diagnostic reaches actual early CPU discovery under Milan TCG, while the new candidate preserves the Intel PID 1 baseline. Next qualify AMD-specific LBR/PMU, MCA, TSC, PAT/MTRR, commpage and topology before AMD admission. Keep strict SRSO qualification separate from functional development. See the [machine-layer report](../research/2026-11/hosted/amd-machine-layer.md).

CP497 closes the corrected 1,109-input candidate review: cross-host section equivalence, bounded topology, generic Darwin subtype grading, guarded XSAVE observation and local synthetic metadata refresh. Continue actual AMD initialization, FPU lifecycle and native/hosted ownership qualification; do not treat the pre-admission diagnostic as a boot. See the [topology and state report](../research/2026-11/hosted/topology-state-and-reproducibility.md).

CP477 extends early AMD discovery with independently tested clock, performance, MCA, memory-type, XSAVE, TLB, TSCI and MONITOR contracts. Continue required machine initialization, microcode/commpage and topology, with Intel full regression and explicit standalone versus hosted ownership. See the [follow-up report](../research/2026-11/hosted/amd-machine-layer-followup.md).

CP460 closes the native SRSO gate for the tested Ryzen Linux KVM component configuration. Guest TSA and CPU feature dependency are separate open items, as is Hyper-V SRSO exposure. Continue AMD machine-layer development; see [native AMD KVM qualification](../research/2026-11/hosted/native-amd-kvm.md).

## Current research boundary (CP630)

The AMD Milan TCG UP path now returns from machine_init and reaches the RTC/lock-timeout observation boundary. CP602 is the current retained standalone candidate, with six strict Broadwell reference passes. Prior early discovery, normal MCA and UP/FPU lifecycle milestones are historical completed scoped tests rather than the immediate next tasks.

Next: establish the complete AMD clock lifecycle, timer delivery and CPU admission; progress toward full AMD standalone PID 1, retain Intel regression, then qualify SMP, physical and hosted execution separately. Continue source provenance and public reproducibility independently. See [current report](../research/2026-11/hosted/commpage-reproduction-599-612.md). CP613-620 establish additional offline and build reproducibility evidence, not a new boot. See [chronological outcomes](../research/2026-11/checkpoint-613-620.md). The regular technical review remains open from CP498; chronological documentation through CP620 does not close it.

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
