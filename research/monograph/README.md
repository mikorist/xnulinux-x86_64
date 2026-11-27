# Research monograph

This chronological series expands the thematic research reports into individual historical experiments. Original journal order is preserved, including nonsequential section numbers. Results are scoped to their original checkpoint; later corrections are identified explicitly.

## Volume I: Recovering the Intel build chain

| Chapter | Source checkpoint | Report |
| --- | ---: | --- |
| 0001 | 23 | [Restoring cctools and assembling the first Intel units](0001-cctools-and-assembly.md) |
| 0002 | 24 | [OSFMK C coverage and the 316/319-input links](0002-osfmk-and-mig.md) |
| 0003 | 25 | [Current-root provider expansion to 794 inputs](0003-root-provider-expansion.md) |
| 0004 | 21 | [The public fork and source-version decision](0004-fork-and-source-pins.md) |
| 0005 | 26 | [Current-root genassym and the 812-input link](0005-current-root-assembly.md) |
| 0006 | 27 | [Rejecting an unproven hibernation provider](0006-hibernate-provider-rejected.md) |
| 0007 | 28 | [Correcting MIG exports and linking 813 inputs](0007-mig-exports-and-hibernate.md) |
| 0008 | 29 | [Historical planning estimate at the 813-input boundary](0008-historical-planning.md) |
| 0009 | 30 | [Component inventory and the 969-symbol audit](0009-component-and-symbol-audit.md) |
| 0010 | 31 | [Reconstructing missing component recipes: 841 inputs](0010-missing-c-batch.md) |
| 0011 | 32 | [BSD syscall generation and the 845-input link](0011-bsd-syscall-generation.md) |
| 0012 | 33 | [Exact-recipe C recheck: 852 inputs](0012-exact-recipe-recheck.md) |
| 0013 | 34 | [Completing configured C and assembly coverage](0013-c-compatibility-track.md) |
| 0014 | 35 | [First complete C++ target audit](0014-cxx-first-pass.md) |

## Volume II: DriverKit generation and C++ provider compatibility

| Chapter | Source checkpoint | Report |
| --- | ---: | --- |
| 0015 | 36 | [Recovering the IIG parser environment](0015-iig-parser-environment.md) |
| 0016 | 37 | [Ordinary Monterey RPC adaptation and typed-allocation probes](0016-monterey-rpc-kalloc.md) |
| 0017 | 38 | [Annotated Mach port direction and measured wire layout](0017-port-direction-and-layout.md) |
| 0018 | 39 | [Alignment-safe wire parsing and the first generated implementation](0018-alignment-safe-wire.md) |
| 0019 | 40 | [IOEventLink and IOWorkGroup port families](0019-eventlink-workgroup.md) |
| 0020 | 41 | [One-way action dispatch and inheritance](0020-action-inheritance.md) |
| 0021 | 42 | [Local CheckForWork and InterruptOccurred reply reuse](0021-reply-reuse.md) |
| 0022 | 43 | [Service and state notification families](0022-notification-families.md) |
| 0023 | 44 | [Memory map and buffer descriptor wire families](0023-memory-wire-families.md) |
| 0024 | 45 | [Fixed-array contracts in memory descriptor and DMA methods](0024-memory-dma-arrays.md) |
| 0025 | 46 | [IOUserClient range and asynchronous completion boundaries](0025-userclient-ranges.md) |
| 0026 | 47 | [IOService generated dispatch](0026-ioservice-wire.md) |
| 0027 | 48 | [OSObject base dispatch and qualified vtable calls](0027-osobject-base-wire.md) |
| 0028 | 49 | [Completing the generated IOUserServer unit](0028-userserver-generator.md) |
| 0029 | 50 | [First handwritten IOKit provider repairs](0029-handwritten-format-repairs.md) |
| 0030 | 51 | [Cross-translation-unit vtable consistency](0030-cross-tu-vtable-audit.md) |

## Volume III: Handwritten providers and the first strict executable

| Chapter | Source checkpoint | Report |
| --- | ---: | --- |
| 0031 | 52 | [Independent architecture version targets](0031-architecture-version-decision.md) |
| 0032 | 53 | [Darwin knote layout and five handwritten providers](0032-knote-and-handwritten-probes.md) |
| 0033 | 54 | [Polled I/O and command-gate callback storage](0033-polled-and-commandgate.md) |
| 0034 | 55 | [Typed startup and member callback adapters](0034-typed-startup-and-members.md) |
| 0035 | 56 | [Typed startup, timer storage and filter block lifecycle](0035-startup-timer-and-filter.md) |
| 0036 | 57 | [Statistics startup and NVRAM serializer evidence](0036-statistics-and-nvram.md) |
| 0037 | 58 | [Interrupt event-source and power queue callback contracts](0037-interrupt-and-power-queue.md) |
| 0038 | 59 | [Thread-start and workloop continuation contracts](0038-thread-and-workloop.md) |
| 0039 | 60 | [IOService and controller conditional integration gates](0039-service-controller-gates.md) |
| 0040 | 61 | [Hibernate diagnostics and power-management adapters](0040-hibernate-and-power-management.md) |
| 0041 | 62 | [Complete component coverage and conditional integration](0041-complete-component-coverage.md) |
| 0042 | 63 | [First complete 984-input diagnostic relocatable link](0042-diagnostic-link-984.md) |
| 0043 | 64 | [Original final-build providers and the 988-input link](0043-final-build-providers-988.md) |
| 0044 | 65 | [Correct kernel-mode MIG generation](0044-kernel-mode-mig.md) |
| 0045 | 66 | [Bootstrap lifecycle and original KLD routing](0045-bootstrap-and-kld.md) |
| 0046 | 67 | [External Firehose and historical profiling providers](0046-firehose-and-historical-pgo.md) |
| 0047 | 68 | [First strict Intel XNU executable link](0047-first-strict-executable.md) |

Coverage snapshot: 47 individual chapters through R0047 (CP68). The retained journal has 591 indexed records through CP612; the next individual chapter is R0048 (CP69). The [engineering history](../2026-11/history/engineering-history-through-612.md) and thematic reports cover later milestones without pretending to be individual-record monograph coverage.

These drafts do not constitute a complete public reproduction bundle. Historical commands, results and hashes require independent review. No new runtime tests were performed for this series.

[Back to research journal](../README.md)
