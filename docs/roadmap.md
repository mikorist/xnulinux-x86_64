# Development roadmap

The sequence below reflects project priorities rather than release dates.

| Stage | Acceptance criterion |
| --- | --- |
| Standalone reference | Root mount, file lookup/read, user-mode execution and traps |
| Hosted Intel integration | Verified FKI and world switch; memory, interrupts, SMP and lifecycle tests |
| Hosted Darwin | Root filesystem, userspace and executable programs on the hosted path |
| Headless | Repeatable CLI and service execution |
| Desktop | Compatible graphical environment; software rendering first |
| Seamless | Individual application windows integrated with Linux |
| Product readiness | Reproducible installation, compatibility matrix, recovery and regression tests |

The [standalone PID 1 milestone](../research/2026-11/boot/pid1-terminal-replay.md) and [ordinary FKI service tests](../research/2026-11/hosted/fki-host-services.md) are documented separately. Neither satisfies the actual hosted acceptance criteria. Subsequent [physical CPL0 component tests](../research/2026-11/hosted/physical-ring0.md) and [split memory service](../research/2026-11/hosted/split-memory-service.md) provide further bounded evidence. The physical module pair and restricted source-backed page/object/resident/final-reference tests have since passed. The bounded reference registry, real FKI-backed Linux process mappings, inactive root lifetime and indexed map paths have since passed in Linux guests. Boot metadata, clock/entropy and cooperative CPU/thread/queue/IPC gates are integrated through checkpoint 337 on two selected kernels, including canonical private Git replay, owned worker services and expanded private startup callback coverage. The next gates are genuine hosted bootstrap integration, unresolved task construction, native execution context/translation activation, startup dependencies and real Mach IPC. Native hosted boot is still not demonstrated. See [the scheduler and IPC report through 337](../research/2026-11/hosted/hosted-bootstrap-replay.md).

Through checkpoint 357, private task ownership and ledger construction have passed two-kernel component regression. Native resource allocation, real Mach IPC, execution context and startup integration remain the next gates. See the [task and ledger report](../research/2026-11/hosted/hosted-task-ledger.md).

Through checkpoint 377, private typed task/thread resources and IPC metadata lifecycle have passed canonical two-kernel replay. Native startup resource ownership, real IPC and native execution remain separate gates. See the [task, thread and IPC report](../research/2026-11/hosted/hosted-task-thread-ipc.md).

Hosted integration may proceed in parallel with standalone reference tests. GPU acceleration is not a prerequisite for the first kernel or headless runtime.


## Subsequent Intel source target

After stable physical Linux-hosted execution of the Monterey baseline, the next planned Intel port targets XNU 12377 (Tahoe). Retain Monterey as a separate version target; reuse validated host infrastructure through version-specific adapters. The exact Tahoe source pin and hardware/userspace requirements require separate qualification. No intermediate macOS version port is mandatory.
