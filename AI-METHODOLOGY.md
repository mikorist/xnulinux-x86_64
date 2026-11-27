# AI-assisted development

This project uses parallel AI-assisted research and implementation with human oversight. Agents work on bounded technical questions; results are judged by evidence, not by the confidence of generated explanations.

Intel and AMD Ryzen development uses separate working environments and a shared source, evidence review and integration history. One maintainer-controlled integrator handles public publication. A build on an AMD host, an AMD-model TCG guest, nested KVM and bare-metal AMD Linux execution are distinct evidence classes.

The broader engineering task is a PC compatibility platform, not just a successful boot. Independent builds, cross-vendor tests, negative controls and physical hardware qualification must preserve their distinct scope. See [platform scope](docs/platform-scope.md).

## Workflow

1. Read the durable project decisions and the latest verified research checkpoint.
2. Inspect actual source revisions and relevant evidence before changing code.
3. Keep parallel tasks in separate working trees or branches when modifying the repository.
4. Record the command, configuration, exit status, relevant output and artifact hashes.
5. Distinguish guest failures from verification-harness failures.
6. Review and integrate logically complete changes; retain failed experiments and their explanations.

## Tooling interruptions and historical record

AI tooling interruptions are documented separately from kernel and test failures. The [November 26 support escalation](research/2026-11/history/ai-assisted-tooling-incident-2026-11-26.md) records the maintainer-reported disruption and subsequent observation without asserting a confirmed internal cause or resolution. Preserve authorization, isolation and host-ownership requirements. The [engineering history through CP612](research/2026-11/history/engineering-history-through-612.md) records the wider research progression.

## Evidence policy

A successful object compilation is not a kernel boot. A relocatable link is not a complete kernel link. A standalone QEMU boot is not a Linux-hosted boot. An observed mount does not prove user-mode execution.

Public documentation is prepared incrementally in English. Reports state what each experiment demonstrates and what remains unverified. Publication requires provenance, license and privacy review. No automatic publication is implied by a successful experiment.


Technical integration reviews occur every 20 significant research checkpoints. Reviewed chronological outcomes, including PASS, FAIL, HOLD and incomplete experiments, are published independently under the rule adopted after CP620. Keep the current [project state](PROJECT-STATE.json), README and qualification documents aligned. No report automatically qualifies source, closes a technical review or triggers an unreviewed push.

## Multi-version evidence and ordinary boot

Record target identity separately from CPU model and physical host. CP621-627 illustrate why a missing completion observation must remain HOLD until a separate valid fixture and actual completion establish the narrower result. CP628 source similarity does not establish ABI compatibility; CP629 offline identity validation is not build or runtime qualification. Keep per-target regression and source evidence distinct.

## Writing for humans

Public guides start with the practical question, explain abbreviations on first use and link to the exact evidence. Readers may come from macOS, Hackintosh or Linux. Keep the navigation approachable, the engineering record exact and the humor restrained. Do not turn research measurements or security and licensing rules into jokes. A confident AI paragraph is not a test result; neither is a particularly entertaining one.
