# 1. Restoring cctools and assembling the first Intel units

**Date:** 2026-11-25  
**Source checkpoint:** 23 (R0001)  
**Scope:** Compile and offline link; historical experiment.  
**XNU:** 8020.140.41, `27b03b360a988dfd3dfdf34262bb0042026747cc`

## Recovered toolchain

The handoff archive was checksum-verified before the cctools subtree was restored without overwriting the existing project. The source pin was `e101a6940dcb5988808a16626bc43851f00dc05f`; the linker identified itself as ld64-711. The assembler wrapper required explicit `-arch x86_64`. The restored cctools checkout contained packaged build products and was not assumed clean.

## Structure offsets

Fresh RELEASE_X86_64 genassym output was obtained with both custom Clang 24 and Debian Clang 19.1.7. The resulting assym.s files were byte-identical, with 468 lines and 234 base definitions.

| Offset | Older bootstrap | Fresh configuration |
| --- | ---: | ---: |
| TH_SYSCALLS_MACH | 1672 | 1740 |
| CPU_HIBERNATE | 4308 | 4388 |
| CPU_NESTED_ISTACK | 4264 | 4296 |

Other task, AST, map, PCID and processor offsets also differed. The historical file was retained, not substituted into the new build. The fresh configuration used an existing narrow include overlay, including declaration-only string.h and the bootstrap uint_t alias; this was not a complete Apple SDK.

Fresh assym.s SHA-256: `50b636a01f8666b6d367a6a2635c487dedf0e4fee496cfaa064f13c5a6c2ca58`.

## Actual assembly

| Original unit | Preprocessed bytes | Result |
| --- | ---: | --- |
| start.s | 19553 | Mach-O x86_64 MH_OBJECT |
| cswitch.s | 13313 | Mach-O x86_64 MH_OBJECT |
| idt64.s | 72138 | Mach-O x86_64 MH_OBJECT |
| locore.s | 22440 | Mach-O x86_64 MH_OBJECT |

Clang preprocessing and cctools assembly operated on unmodified pinned source files.

The recorded relocatable-link command was:

```sh
x86_64-apple-darwin-ld -arch x86_64 -r \
  start.o cswitch.o idt64.o locore.o \
  -o xnu-4asm-relocatable.o
```

Exit 0; 72,152 bytes; 482 relocation records retained; 34 undefined symbols. SHA-256: `988981f939e4c91d0c8d8c20e46bcb13d3b2ca34ff84133ceec131debed9c34a`.

The separate kernel-layout link exited 1 with 34 unresolved external symbols. No illegal-text-relocation diagnostic was reported in that attempt. Missing providers were not replaced by dummy definitions.

## Evidence and limits

The original experiment directory contains reproduce.sh, preprocessing outputs, object hashes and separate linker logs. The journal records a repeated reproduction with matching hashes. These materials are not yet included in the public draft.

This demonstrated actual Intel assembly compilation and relocatable linking, not kernel execution, FKI, world switch or physical hardware compatibility. The pinned XNU checkout remained clean.
