# AI-assisted development

This project uses parallel AI-assisted research and implementation with human oversight. Agents work on bounded technical questions; results are judged by evidence, not by the confidence of generated explanations.

## Workflow

1. Read the durable project decisions and the latest verified research checkpoint.
2. Inspect actual source revisions and relevant evidence before changing code.
3. Keep parallel tasks in separate working trees or branches when modifying the repository.
4. Record the command, configuration, exit status, relevant output and artifact hashes.
5. Distinguish guest failures from verification-harness failures.
6. Review and integrate logically complete changes; retain failed experiments and their explanations.

## Evidence policy

A successful object compilation is not a kernel boot. A relocatable link is not a complete kernel link. A standalone QEMU boot is not a Linux-hosted boot. An observed mount does not prove user-mode execution.

Public documentation is prepared incrementally in English. Reports state what each experiment demonstrates and what remains unverified. Publication requires provenance, license and privacy review. No automatic publication is implied by a successful experiment.


Reviewed incremental source, test and documentation updates are prepared after every 20 significant research checkpoints. Unresolved components remain held; a successful experiment does not automatically trigger a push.
