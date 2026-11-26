# 2. OSFMK C coverage and the 316/319-input links

**Date:** 2026-11-25  
**Source checkpoint:** 24 (R0002)  
**Scope:** Compile and offline link; XNU 8020.140.41.

## Generated MIG inputs

Original pinned Makefile lists selected MIG sources for mach, UserNotification, atm, gssd, lockd and kextd. The generation run processed 53 targets: 23 newly generated sources, 30 already available, no missing .defs and no errors. UNDReplyServer and arcade_upcall were additionally generated using their original rules.

Three kernel-user generated C files needed the original kern/ipc_mig.h as a forced include for real helper declarations. The mach_host server was regenerated with KERNEL_PRIVATE and MACH_KERNEL_PRIVATE because the earlier invocation omitted the memory_object_t intran conversion. All 43 previously missing generated MIG objects then compiled successfully.

## OSFMK object inventory

| Category | Objects |
| --- | ---: |
| Source-backed exact recipe | 251 |
| MIG-generated exact recipe | 43 |
| Explicit compatibility | 3 |
| Total | 297 |

The compatibility lane allowed implicit-function-declaration diagnostics for vm32_user.o and vm_map.o. An isolated mach_kernelrpc.c copy moved the task check after the VLA declaration so the existing goto did not cross the variably modified scope; it also used the explicit diagnostic option. No original source file was edited.

## Relocatable results

| Set | Bytes | Undefined |
| --- | ---: | ---: |
| 297 C objects | 4615096 | Not recorded here |
| 297 C + 19 assembly | 4690144 | 621 |
| 319 inputs with three additional providers | 4703952 | 628 |

The final three candidates were IOHibernateRestoreKernel.o, stack_protector.o and systemcalls.o. Their inclusion increased total unresolved references because providers can introduce dependencies.

| Set | SHA-256 |
| --- | --- |
| 297 | `17c9d2f85f19840ff952c71d8ef50db3323516df66c1a4529a24f1ddf5f2e7b5` |
| 316 | `55b49299c4579e857f3014f22ad70ec279fd4f16d945bb76958391a7b220f87a` |
| 319 | `18201e5f4832db9a829a85bbec674c5c5640e1022c174af9293f0676c2dc6318` |

All were Mach-O x86_64 MH_OBJECT outputs. Later current-root work reassessed provider provenance; these historical inputs are not automatically valid for that profile.

## Reproduction records

The original archive records generate-all-osfmk-mig-sources.py, build-generated-mig-c.py, build-osfmk-compat-c.py and OSFMK-C-297-PROVENANCE.tsv, with generated source, original commands and logs. Public clean reproduction awaits export of reviewed dependencies.

No final kernel link, module or boot was established. The remaining BSD, IOKit, libkern, platform and runtime references required source-backed investigation rather than blanket classification as host imports.
