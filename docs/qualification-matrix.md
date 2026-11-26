# Qualification matrix

Snapshot: research checkpoint 437, 2026-11-26. Results apply to the stated scope only. Parallel Intel/Ryzen development is active.

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
| PID 1 / ring 3 | Standalone native execution and terminal-only replay confirmed | Debugger-free boot, general userspace, hosted replay |
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
| AMD nested KVM component replay | Actual Ryzen nested KVM: 94/94 functional marker groups on both kernels; strict HOLD on SRSO warning | Clean strict replay, physical AMD qualification |
| Ryzen source toolchain | Independently rebuilt custom Clang 24; 15 reference objects and dependencies exact; expanded OSFMK C closure | Complete XNU build and link |
| Cross-host OSFMK C reproduction | 290 original, four historical compatibility, three new strict reference objects match; byte-identical 297-object relocatable after canonical paths and input timestamps | Integrated MIG ABI, other subsystems and complete kernel link/runtime |
| Cross-compiler IPC/reference objects | Historical stock compiler limits superseded for the 15-unit custom Clang 24 closure; selected IPC layouts remain static evidence | Executable ABI and native runtime |
| Complete Linux-hosted XNU | Not demonstrated | Actual hosted boot and userspace |
| Headless / desktop / seamless | Goals | End-to-end implementation |

The latest research checkpoint must be consulted before using this snapshot for a public status announcement.
