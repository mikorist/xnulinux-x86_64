# Source tree guide

The following paths were inspected in the pinned Apple XNU 8020.140.41 checkout. They describe the upstream source layout, not a new public fork directory structure.

| Path | Area |
| --- | --- |
| osfmk/i386/ and osfmk/x86_64/ | x86 machine-dependent code (vendor-specific paths require review) |
| osfmk/kern/ | Mach kernel services and startup |
| osfmk/vm/ | Virtual memory |
| osfmk/ipc/ and osfmk/mach/ | IPC and Mach interfaces |
| osfmk/prng/ | Random subsystem |
| bsd/kern/ and bsd/vfs/ | BSD initialization and VFS |
| bsd/pthread/ | Kernel pthread interface |
| bsd/net/, bsd/netinet/, bsd/skywalk/ | Networking |
| iokit/ | IOKit and DriverKit interfaces |
| libkern/ and libsa/ | Kernel runtime and bootstrap |
| pexpert/ | Platform expert |
| config/ and makedefs/ | Configuration and build rules |
| EXTERNAL_HEADERS/ | External interface headers |

The intended fork also retains the upstream xnulinux FKI, loader, patch and tool separation. Exact new x86_64 public paths must be verified against the integration branch before publication.

The pinned source is not a place for undocumented experiments. Keep source provenance and architecture-specific patches separate.
