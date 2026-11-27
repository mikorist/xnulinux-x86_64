# Glossary

| Term | Meaning in this project |
| --- | --- |
| XNU | Apple's kernel combining Mach, BSD and IOKit |
| Darwin | The operating-system foundation used by macOS |
| FKI | Foreign Kernel Interface between Linux and hosted XNU |
| World switch | Architecture-specific transition between Linux and XNU execution contexts |
| Hosted | XNU executes through the Linux hosting boundary |
| Standalone | Independent XNU diagnostic execution, currently tested in QEMU |
| TCG | QEMU software execution backend used in recorded standalone tests |
| Mach-O | Object and executable format used by XNU |
| MH_OBJECT | Relocatable Mach-O object, not a complete kernel |
| MIG | Mach interface generator |
| IIG | DriverKit interface generator |
| IORPC | IOKit RPC interface |
| pmap | Machine-dependent virtual-memory mapping layer |
| VFS | Virtual filesystem layer |
| vnode | Kernel representation of a filesystem object |
| md0 | Memory-backed root device in the recorded fixture |
| KAT | Known-answer test |
| POST | Diagnostic power-on self-test in the provider research |
| ADR | Architecture decision record |
| Checkpoint | Recorded experiment with an explicit observed boundary |
| PID 1 | First userspace process; the project test program is not Apple launchd |
| HOLD | The stated acceptance criteria or evidence are incomplete; not automatically a failure |
| Version target | Independently pinned XNU source, runtime and qualification profile |
| EFI | Firmware boot environment; a Hackintosh EFI folder is not the intended XNULINUX deployment model |
| Seamless | Intended individual application windows alongside ordinary Linux applications |
| GNU | GNU's Not Unix; a project providing free operating-system components, distinct from the Linux kernel |
| XNULINUX | Project name for the proposed XNU-on-Linux platform, not a new name for GNU/Linux |
| CP | Numbered research checkpoint, not a software release |
| PASS | Acceptance criteria met for the stated test scope only |
