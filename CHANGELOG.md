# Changelog

## Unreleased

There is no x86_64 product release represented by this document. The entries below distinguish recorded research milestones from integrated, supported functionality.

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
- Public repository renamed and ARM-only deployment retired; original reference branch preserved.

See the [kernel image history](docs/kernel-history.md), [research journal](research/README.md) and [qualification matrix](docs/qualification-matrix.md).

### Not established by these milestones

Complete physical Linux-hosted XNU boot and world switch, a complete Darwin application runtime, desktop or seamless integration, general hardware compatibility and an end-user installer.

### Documentation

An English developer reference, research index, architecture decisions and reproducibility methodology are being prepared for review. Historical research records are not release tags or claims of upstream integration.

Future entries should describe actual integrated changes by release or Unreleased section; avoid listing every diagnostic build as a released feature.
