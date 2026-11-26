# Public progress update: native Darwin PID 1

**Author:** [mikorist](https://github.com/mikorist)  
**Original source:** [AFK-surf/xnulinux Issue #10, comment 7174745326](https://github.com/AFK-surf/xnulinux/issues/10#issuecomment-7174745326)  
**Archive date:** 2026-11-25  
**Scope:** Historical public communication, not a release or independent test report.

## Historical context

This update follows the [initial port announcement](https://github.com/AFK-surf/xnulinux/issues/10#issuecomment-7160958748). It records the change to an independent Monterey baseline, the first native Darwin userspace milestone, the three intended execution modes and the subsequent Tahoe target. The earlier announcement remains intact as a historical source.

The technical context at the time of preparation was checkpoint 174. Later evidence is documented separately in the [PID 1 replay report](../boot/pid1-terminal-replay.md) and [FKI host-service report](../hosted/fki-host-services.md). The comment describes standalone results and intended hosted architecture; it does not claim that the full macOS runtime is already functional or that the local research has been integrated into the public fork.

The GitHub response did not expose creation or modification timestamps. The archive date above is therefore not an independently verified posting timestamp.

## Archived comment (original Markdown)

## x86_64 port progress update

A lot has happened since my previous comment. Several AI agents have been working in parallel on different parts of the port, with extensive documentation and verification of both successful and failed experiments.

My initial Intel baseline is XNU `8020.140.41` (macOS Monterey 12.5), primarily because I also want to investigate support for older Intel hardware, including Haswell and Kaby Lake.

### Current achievements

- Successfully built and linked a complete experimental x86_64 XNU executable with 1,089 input objects and zero undefined symbols.
- Verified Mach VM initialization, scheduler context switching, timer interrupts, Mach IPC initialization, IOKit and BSD startup.
- Implemented experimental open-source PRNG and cryptographic providers.
- Successfully mounted a real HFS+ root filesystem and verified native VFS operations.
- Executed a custom, ad hoc signed Darwin Mach-O program as PID 1 in ring 3.
- Verified native BSD system calls, Mach traps and return to userspace.
- Successfully completed a standalone boot with native userspace file operations, without intermediate debugger stepping.
- Verified rejection of unsupported filesystem operations and multiple invalid HFS volume configurations.

All runtime results above are from isolated standalone QEMU tests. Linux-hosted execution on physical Intel hardware has not yet been demonstrated.

In parallel, work has started on the Intel FKI ABI, capability negotiation and the architecture-specific host integration.

### Long-term goals

I want to support three execution modes through a shared XNU kernel and Darwin runtime:

- **Seamless mode:** Run individual macOS applications directly alongside native Linux applications, without requiring a complete macOS desktop session.
- **Desktop mode:** Run a complete compatible macOS desktop environment within Linux.
- **Headless mode:** Run Darwin command-line applications, development tools and system services without a graphical environment.

The ultimate goal is native XNU hosting on physical Intel Linux systems, without a conventional macOS virtual machine or Hackintosh installation. QEMU is currently a development and testing environment, not a required part of the intended final architecture.

### Beyond Monterey

Once the Monterey-based implementation is stable on a physical Linux host, my next target will be the XNU `12377` family, corresponding to macOS Tahoe, the final macOS generation supporting Intel.

I intend to retain Monterey as a separate target for older Intel hardware while developing Tahoe using as much of the same FKI and Intel world-switch infrastructure as possible.

I'm also preparing extensive English-language documentation, including architecture decisions, reproducible experiments, failed approaches, dependency provenance and a chronological research monograph. The documentation currently contains more than 16,000 words.

Most of the experimental implementation is still local. I prefer publishing reviewed, reproducible milestones rather than uploading an enormous collection of unverified build artifacts.

There is still a lot of work ahead, but we are now executing actual Darwin userspace code. That is a rather encouraging starting point. :)
