# 5. Current-root genassym and the 812-input link

**Date:** 2026-11-25  
**Source checkpoint:** 26 (R0005)  
**Scope:** Compile and relocatable link.

The actual root dry-run recipes 3646–3647 were recovered. The custom Clang invocation translated -arch x86_64 to -target x86_64-apple-macos12.5 and removed the unsupported historical Apple trivial-auto-var-init driver option; other recorded flags and include paths were preserved.

| Generator output | Bytes | SHA-256 |
| --- | ---: | --- |
| genassym.o (assembly text) | 52129 | `1ad4acea9de32f796630f2e1a4c4d9ecae275b4ec864ff8561aff689e1178a55` |
| assym.s | 11542 | `50b636a01f8666b6d367a6a2635c487dedf0e4fee496cfaa064f13c5a6c2ca58` |

Both compiler and extraction exited 0 without stderr. The fresh offset hash matched the earlier independent result.

## Active assembly target set

BSD: cpu_copy_in_cksum, cpu_memcmp_mask.

OSFMK: pal_routines_asm, start, bcopy, bzero, WKdmDecompress_new, WKdmCompress_new, WKdmData_new, lz4_decode_x86_64, fp_simd, i386_lock, locore, cswitch, machine_routines_asm, commpage_asm, fifo_queues and idt64.

All 18 compiled to x86_64 MH_OBJECT. Attempt 01 had incorrect -x ordering and relative output handling in the runner; Clang stopped before assembly. Attempt 02 corrected output paths and completed. This was a tooling failure, not 18 XNU source failures.

## Link and symbol delta

The old recorded link command file contained status and warning text after the command, so the 794 prior input paths were reconstructed from the actual staged input set rather than treating the entire file as argv.

ld64-711 -r -arch x86_64 combined 794 existing inputs and 18 assembly objects. Exit 0, sole missing Frameworks directory warning; output 14,390,560 bytes, x86_64 MH_OBJECT.

SHA-256: `0f5daae9e05a0c77a8063c0445802d65f161e118fe52bb5029ecd2425e9c202b`.

| Undefined before | Resolved | Introduced | Undefined after |
| ---: | ---: | ---: | ---: |
| 1293 | 322 | 1 | 972 |

The new dependency was _hibernate_kernel_entrypoint. The historical hibernation object required independent provenance checking before inclusion; Chapter 6 records that rejection.

The input TSV/JSON, command, stdout, exit code, header audit and undefined list were retained. No final image, module or boot was produced. The journal's contemporary public-source-version constraint was later superseded by checkpoint 52.
