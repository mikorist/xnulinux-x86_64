# Research journal

For a quick overview, see the [current status](../README.md#current-status). If this is your first visit, the [getting-started guide](../docs/getting-started.md) is a shorter route into the project. This journal is the engineering record, including things that did not work.

For chronological individual experiments, see the [research monograph](monograph/README.md). The monograph now contains 47 chapters through the first strict executable link (CP68); later thematic results are documented through CP612, followed by [chronological CP613-620 outcomes](2026-11/checkpoint-613-620.md) and [CP621](2026-11/checkpoint-621.md), [CP622](2026-11/checkpoint-622.md), [CP623](2026-11/checkpoint-623.md), [CP624](2026-11/checkpoint-624.md), [CP625](2026-11/checkpoint-625.md), [CP626](2026-11/checkpoint-626.md), [CP627](2026-11/checkpoint-627.md), [CP628](2026-11/checkpoint-628.md), [CP629](2026-11/checkpoint-629.md), [CP630](2026-11/checkpoint-630.md), [CP631](2026-11/checkpoint-631.md), [CP632](2026-11/checkpoint-632.md), [CP633](2026-11/checkpoint-633.md), [CP634](2026-11/checkpoint-634.md), [CP635](2026-11/checkpoint-635.md), [CP636](2026-11/checkpoint-636.md), [CP637](2026-11/checkpoint-637.md), [CP638](2026-11/checkpoint-638.md), [CP639](2026-11/checkpoint-639.md), [CP640](2026-11/checkpoint-640.md), [CP641](2026-11/checkpoint-641.md).

Experimental milestones, not product releases. Current development runs in parallel on Intel and AMD Ryzen. Historical reports retain the original CPU, accelerator and test scope. Runtime results listed here concern standalone research unless explicitly stated otherwise.

The [platform scope and evidence overview](../docs/platform-scope.md) connects the individual research tracks to the complete PC-oriented XNU/Darwin platform goal. It does not replace historical reports or broaden their qualification.

## [November 2026](2026-11/README.md)

| Topic | Report |
| --- | --- |
| Toolchain | [Build and strict executable link](2026-11/toolchain/build-and-link.md) |
| Boot | [Firmware and clock qualification](2026-11/boot/firmware-and-clock.md) |
| Memory | [Mach VM bootstrap](2026-11/memory/mach-vm.md) |
| Memory | [Typed allocator qualification](2026-11/memory/typed-allocation.md) |
| Scheduler | [Scheduler and Mach IPC bootstrap](2026-11/scheduler/bootstrap.md) |
| IOKit | [Platform and BSD initialization](2026-11/iokit/platform-and-bsd.md) |
| Crypto | [Provider qualification](2026-11/crypto/provider-qualification.md) |
| Crypto | [Diagnostic registration checkpoint](2026-11/crypto/registration-checkpoint.md) |
| Filesystem | [First root mount](2026-11/filesystem/first-root-mount.md) |
| Filesystem | [First named file read](2026-11/filesystem/first-file-read.md) |
| Toolchain | [Kernel-mode MIG generation](2026-11/toolchain/mig-kernel-mode.md) |
| IOKit | [IIG compatibility](2026-11/iokit/iig-compatibility.md) |
| Userspace | [Native PID 1 and terminal-only replay](2026-11/boot/pid1-terminal-replay.md) |
| Host integration | [Intel FKI ordinary Linux-context tests](2026-11/hosted/fki-host-services.md) |
| Host integration | [Intel CPU transition mechanisms and negative controls](2026-11/hosted/intel-transition-mechanisms.md) |
| Host integration | [Selected linked XNU code and hostcalls](2026-11/hosted/linked-xnu-and-hostcalls.md) |
| Host integration | [Representative Linux 6.x compatibility matrix](2026-11/hosted/linux-kernel-compatibility.md) |
| Host integration | [First physical Intel ring-0 execution](2026-11/hosted/physical-ring0.md) |
| Host integration | [Split FKI memory service and open-source boundary](2026-11/hosted/split-memory-service.md) |
| Host integration | [Native VM page descriptors and hosted page ownership](2026-11/hosted/vm-page-ownership.md) |
| Host integration | [Multi-session FKI ownership and corrected warning gate](2026-11/hosted/fki-smp-and-warning-regression.md) |
| Host integration | [Linux-backed aliases and concurrent mapping lifetime](2026-11/hosted/mapping-lifetime.md) |
| Host integration | [Source-backed VM objects and resident hashing](2026-11/hosted/vm-object-resident.md) |
| Host integration | [Restricted final reference and process address-space isolation](2026-11/hosted/vm-final-reference-and-address-spaces.md) |
| Host integration | [Actual FKI process mappings and reference tickets](2026-11/hosted/owned-process-memory.md) |
| Host integration | [Inactive root ownership and cancellation](2026-11/hosted/inactive-root-lifecycle.md) |
| Host integration | [Indexed VM and integrated boot metadata](2026-11/hosted/indexed-map-and-boot-metadata.md) |
| Host integration | [Hosted clock, entropy and PRNG lifecycle](2026-11/hosted/hosted-clock-entropy-runtime.md) |
| Host integration | [Hosted startup, scheduler and private IPC](2026-11/hosted/hosted-startup-scheduler-ipc.md) |
| Host integration | [Hosted task ownership and ledger research](2026-11/hosted/hosted-task-ledger.md) |
| Host integration | [Hosted task, thread and IPC resource lifecycle research](2026-11/hosted/hosted-task-thread-ipc.md) |
| Host integration | [Hosted provenance and reproduction research](2026-11/hosted/hosted-provenance-reproduction.md) |
| Project history | [Intel repository separation](2026-11/history/intel-repository-separation.md) |
| Project history | [Public progress update: native Darwin PID 1](2026-11/history/public-progress-update-01.md) |
| Host integration | [Cross-host OSFMK reproduction and AMD KVM qualification](2026-11/hosted/osfmk-cross-host-reproduction.md) |
| Machine layer | [Full executable reproduction and early AMD machine-layer research](2026-11/hosted/amd-machine-layer.md) |
| Machine layer | [Topology, Darwin ABI, extended-state metadata and build reproducibility](2026-11/hosted/topology-state-and-reproducibility.md) |
| Machine layer | [Vendor-aware machine-layer contracts and early runtime validation](2026-11/hosted/amd-machine-layer-followup.md) |
| Hardware qualification | [Native AMD KVM component replay and SRSO qualification](2026-11/hosted/native-amd-kvm.md) |
| Machine layer | [AMD standalone startup (CP498-555)](2026-11/hosted/amd-startup-498-555.md) |
| Machine layer | [Machine lifecycle and image reproduction (CP556-598)](2026-11/hosted/amd-machine-lifecycle-556-598.md) |
| Machine layer | [Commpage and provenance (CP599-612)](2026-11/hosted/commpage-reproduction-599-612.md) |
| Project history | [Engineering history and evidence audit through CP612](2026-11/history/engineering-history-through-612.md) |
| Development tooling | [AI tooling interruption and support escalation](2026-11/history/ai-assisted-tooling-incident-2026-11-26.md) |
| Cross-cutting | [Failed approaches and lessons](2026-11/lessons-learned.md) |

See also the [selected evidence manifest](2026-11/evidence-manifest.md).

Reports are selected thematic summaries. Complete reproduction bundles and individual checkpoint coverage remain under preparation.

The [public metadata validator regression](../tests/hosted/monterey/mach-header-validator/README.md) is independently runnable. Reports remain scoped to their original evidence; individual chapters and historical results have not all been independently replayed.

These records support the [XNU for the PC philosophy](../docs/project-philosophy.md). Historical Intel-specific results retain their original scope.
