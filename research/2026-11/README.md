# November 2026 research index

Reports cover the recorded November 2026 research; their scope and limits are stated in each report. The [monograph](../monograph/README.md) preserves individual checkpoint chronology.

| Report | Topic |
| --- | --- |
| [Standalone firmware and clock qualification](boot/firmware-and-clock.md) | boot |
| [Standalone PID 1 and independent terminal-only replay](boot/pid1-terminal-replay.md) | boot |
| [Open-source PRNG and cryptographic provider research](crypto/provider-qualification.md) | crypto |
| [Diagnostic crypto registration checkpoint](crypto/registration-checkpoint.md) | crypto |
| [Selected evidence manifest](evidence-manifest.md) | General |
| [First named file read through XNU VFS](filesystem/first-file-read.md) | filesystem |
| [First successful standalone XNU root filesystem mount on x86_64](filesystem/first-root-mount.md) | filesystem |
| [Intel FKI ordinary Linux-context qualification](hosted/fki-host-services.md) | hosted |
| [IIG and Monterey IORPC compatibility](iokit/iig-compatibility.md) | iokit |
| [IOKit initialization and the path to BSD](iokit/platform-and-bsd.md) | iokit |
| [Failed approaches and diagnostic lessons](lessons-learned.md) | General |
| [Mach virtual memory bootstrap](memory/mach-vm.md) | memory |
| [Standalone typed allocator qualification](memory/typed-allocation.md) | memory |
| [Scheduler and Mach IPC bootstrap](scheduler/bootstrap.md) | scheduler |
| [From Intel assembly to a strict XNU executable](toolchain/build-and-link.md) | toolchain |
| [Kernel-mode MIG generation](toolchain/mig-kernel-mode.md) | toolchain |
| [Public progress update: native Darwin PID 1](history/public-progress-update-01.md) | history |
| [Intel CPU transition mechanisms and negative controls](hosted/intel-transition-mechanisms.md) | hosted |
| [Selected linked XNU code and hostcalls](hosted/linked-xnu-and-hostcalls.md) | hosted |
| [Representative Linux 6.x compatibility matrix](hosted/linux-kernel-compatibility.md) | hosted |
| [First physical Intel ring-0 execution](hosted/physical-ring0.md) | hosted |
| [Split FKI memory service and open-source boundary](hosted/split-memory-service.md) | hosted |
| [Native VM page descriptors and hosted page ownership](hosted/vm-page-ownership.md) | hosted |
| [Multi-session FKI ownership and corrected warning gate](hosted/fki-smp-and-warning-regression.md) | hosted |
| [Linux-backed aliases and concurrent mapping lifetime](hosted/mapping-lifetime.md) | hosted |
| [Source-backed VM objects and resident hashing](hosted/vm-object-resident.md) | hosted |
| [Restricted final reference and process address-space isolation](hosted/vm-final-reference-and-address-spaces.md) | hosted |
| [Actual FKI process mappings and reference tickets](hosted/owned-process-memory.md) | hosted |
| [Inactive root ownership and cancellation](hosted/inactive-root-lifecycle.md) | hosted |
| [Indexed VM and integrated boot metadata](hosted/indexed-map-and-boot-metadata.md) | hosted |
| [Hosted clock, entropy and PRNG lifecycle](hosted/hosted-clock-entropy-runtime.md) | hosted |
| [Hosted startup, scheduler and private IPC](hosted/hosted-startup-scheduler-ipc.md) | hosted |
| [Intel repository separation](history/intel-repository-separation.md) | history |
| [Hosted component integration and canonical Git replay](hosted/hosted-bootstrap-replay.md) | hosted |
| [Hosted task ownership and ledger research](hosted/hosted-task-ledger.md) | hosted |
| [Hosted task, thread and IPC resource lifecycle research](hosted/hosted-task-thread-ipc.md) | hosted |
| [Hosted provenance and reproduction research](hosted/hosted-provenance-reproduction.md) | hosted |
| [Parallel Intel and Ryzen development: checkpoints 398-417](hosted/parallel-intel-ryzen.md) | hosted |
| [Cross-host OSFMK reproduction and AMD KVM component qualification](hosted/osfmk-cross-host-reproduction.md) | hosted |
| [Full executable reproduction and early AMD machine-layer research](hosted/amd-machine-layer.md) | machine layer |
| [Topology, Darwin ABI, extended-state metadata and build reproducibility](hosted/topology-state-and-reproducibility.md) | machine layer |
| [Vendor-aware machine-layer contracts and early runtime validation](hosted/amd-machine-layer-followup.md) | machine layer |
| [Native AMD KVM component replay and SRSO qualification](hosted/native-amd-kvm.md) | Hardware qualification |
| [AMD standalone startup: early CPU state to machine initialization (CP498-555)](hosted/amd-startup-498-555.md) | machine layer |
| [Reproducible image and AMD machine lifecycle (CP556-598)](hosted/amd-machine-lifecycle-556-598.md) | machine layer |
| [Commpage initialization, regressions and build provenance (CP599-612)](hosted/commpage-reproduction-599-612.md) | machine layer |
| [Engineering history and evidence audit through CP612](history/engineering-history-through-612.md) | history |
| [AI-assisted tooling interruption and support escalation](history/ai-assisted-tooling-incident-2026-11-26.md) | development tooling |

## Chronological development log

- [CP613-620: all recorded outcomes](checkpoint-613-620.md)
- [CP621: observer-free standalone smoke (HOLD)](checkpoint-621.md)
- [CP622: ordinary serial console and AMD admission rejection (HOLD)](checkpoint-622.md)
- [CP623: serial-only observation and silent PID 1 fixture (HOLD)](checkpoint-623.md)
- [CP624: separate PID 1 console fixture (build PASS, runtime HOLD)](checkpoint-624.md)
- [CP625: ordinary root mount and init load attempt (scoped PASS, PID 1 HOLD)](checkpoint-625.md)
- [CP626: ordinary Intel-model PID 1 completion (scoped PASS)](checkpoint-626.md)
- [CP627: cross-host ordinary Intel-model PID 1 completion (scoped PASS)](checkpoint-627.md)
- [CP628: Monterey/Tahoe source comparison (source-only PASS)](checkpoint-628.md)
- [CP629: Monterey descriptor (offline PASS)](checkpoint-629.md)
- [CP630: utility source regeneration and exact relink (scoped PASS)](checkpoint-630.md)
- [CP631: Tahoe source and build-input inventory (source-only PASS)](checkpoint-631.md)
- [CP632: Tahoe dependency references (tag PASS, release mapping HOLD)](checkpoint-632.md)
- [CP633: public structural validator replay (GCC PASS, Intel Clang dependency HOLD)](checkpoint-633.md)
- [CP634: physical host Clang runtime repair (host PASS, MCP HOLD)](checkpoint-634.md)
- [CP635: public Python verifier replay (synthetic PASS)](checkpoint-635.md)
- [CP636: reproducible source package (source PASS, attribution HOLD)](checkpoint-636.md)
- [CP637: first research distribution readiness assessment (release HOLD)](checkpoint-637.md)
- [CP638: portable source staging and Python source lineage (release HOLD)](checkpoint-638.md)
- [CP639: additional Monterey source regeneration and exact relink](checkpoint-639.md)
- [CP640: Tahoe utility dependency comparison (source-only PASS)](checkpoint-640.md)
- [CP641: ARM post-kernel platform reuse audit](checkpoint-641.md)

- [CP642: synthetic framebuffer conversion replay](checkpoint-642.md)

- [CP643-755: chronological research update (113 outcomes)](updates-643-755/README.md)

[CP756-775 chronological research update](updates-756-775/README.md).

[CP776-795 chronological research update](updates-776-795/README.md).

[CP796-815 chronological research update](updates-796-815/README.md).

[CP816-835 chronological research update](updates-816-835/README.md).

[CP836-855 chronological research update](updates-836-855/README.md).

[CP856-875 chronological research update](updates-856-875/README.md).

[CP876-895 chronological research update](updates-876-895/README.md).

[CP896-915 chronological research update](updates-896-915/README.md).

[CP916-935 chronological research update](updates-916-935/README.md).
