# Engineering history and qualification discipline through CP612

November 27, 2026. XNULINUX x86_64 began with an architecture-port investigation and has developed into a shared Intel/AMD PC-oriented XNU/Darwin compatibility platform. This retrospective connects the recorded research stages and the tooling history. It does not replace individual experiments, grant source clearance or constitute a release.

## Historical progression

| Checkpoint or range | Recorded development |
| --- | --- |
| Initial investigation, CP23 onward | Recover the x86_64 toolchain, pinned Monterey XNU build, generated sources, Mach-O assembly, relocatable and strict executable links. |
| CP151 and later standalone research | Native HFS+ root mount, real file reads, owned signed Darwin test PID 1 in user mode, native Mach/BSD returns. Not Apple's launchd. |
| CP240-397 | Narrow Linux regression to two kernel targets, qualify bounded physical Intel components and integrated hosted memory, startup, cooperative scheduler and private task/thread/IPC resources. Canonical private component replays reach 94 marker groups. |
| CP398-460 | Independent Intel/Ryzen development, reference object regeneration, full executable reproduction, vendor-aware discovery and physical Ryzen Linux KVM SRSO verification. CP460 confirms strict 94/94 on each guest kernel; Hyper-V SRSO and guest TSA remain separate. |
| CP461-497 | Machine-layer contracts, address widths, cache/TLB, extended-state and topology validation. CP497 full Intel reference regression; AMD remains pre-admission. |
| CP498-555 | Actual AMD-model early startup progresses through MCA, bootstrap, pmap and VM, zone, credential and MAC initialization. CP525 native Linux SMCA inventory is a separate physical observation, not XNU SMCA handling. |
| CP556-598 | Independent byte-identical 1,114-input image and loader, strict Intel reference gate with 19 negative controls, AMD-model LAPIC/UP/FPU and machine lifecycle progress, RTC and lock-timeout observation boundary. |
| CP599-612 | Diagnose intermittent commpage initialization failures, test a scoped lifecycle correction, verify six strict Broadwell CP602 passes across both development hosts, audit dependency provenance and test original timeout/time-conversion arithmetic. AMD clock lifecycle and CPU admission remain open. |

References: [research index](../README.md), [initial build research](../toolchain/build-and-link.md), [native AMD KVM qualification](../hosted/native-amd-kvm.md), [AMD startup](../hosted/amd-startup-498-555.md), [machine lifecycle](../hosted/amd-machine-lifecycle-556-598.md), [CP599-612 report](../hosted/commpage-reproduction-599-612.md).

## Historical evidence audit

The private research journal contains 591 distinct numbered entries through CP612, with CP22 absent from the inspected numeric headings. The numbering is retained as recorded; no missing experiment is inferred. An independent integrity review checked all 371 entries using the standardized primary Evidence/SHA256 reference format. All matched their retained artifacts. The other 220 historical entries use different documentation formats and need separate review. A hash match is not a fresh experimental replay.

The public thematic documentation reaches CP612, while the last closed regular publication review remains CP497. The earlier public monograph covers only part of the individual chronology. Source provenance, licensing, clean public build reproduction and the individual-record ledger are not cleared by this historical audit.

## Why the work is difficult

The initial port is only one part of the project. The shared PC machine layer must accommodate actual CPU capabilities across vendors and generations while preserving Linux ownership of host resources. Reproducibility, negative tests and controlled regression boundaries are independent of simply reaching userspace. A diagnostic can terminate successfully without booting, and a successful boot can coexist with an unresolved intermittent failure. The project retains these distinctions.

Other independent x86_64 efforts have reported progress in the [upstream discussion](https://github.com/AFK-surf/xnulinux/issues/10). Their reported launchd milestones and our owned PID 1 test fixture are different evidence, not interchangeable claims. We welcome comparison and collaboration.

AI-assisted research also encounters tooling failures and interruptions. See [the tooling incident record](ai-assisted-tooling-incident-2026-11-26.md). These are part of the development history, not kernel qualification results.
