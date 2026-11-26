# Testing and evidence

## Evidence classes

| Class | What it establishes |
| --- | --- |
| Compile-only | A particular translation unit builds |
| Relocatable link | A defined object set links as MH_OBJECT |
| Strict executable link | Executable layout and symbol closure for the audited input set |
| Standalone runtime | Observed kernel behavior in a specified guest |
| Hosted runtime | Behavior through the Linux hosting boundary |
| Physical hosted runtime | Behavior on an identified physical Intel/Linux host |

A successful diagnostic capture can have exit code zero while the guest has panicked. A test result therefore needs an explicit observed boundary and assertions, not only a process exit code.

## Recorded standalone environment

Legacy firmware, QEMU TCG, Broadwell-v2, one vCPU, 512 MiB, no network, no physical disk passthrough. Debugger and QMP connections use local Unix sockets in isolated replay directories.

## Reproduction policy

Record the source pin, input manifest, compiler/linker version, configuration, exact command, output hashes, assertion results, exception classification and limitations. Preserve failed attempts. Use separate replay directories rather than overwrite historical evidence.

For physical hosted tests, add host kernel version, CPU model, module versions and recovery plan. Hosted qualification remains separate.

See [root mount](../research/2026-11/filesystem/first-root-mount.md) and [file read](../research/2026-11/filesystem/first-file-read.md).
