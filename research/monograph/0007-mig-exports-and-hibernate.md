# 7. Correcting MIG exports and linking 813 inputs

**Date:** 2026-11-25  
**Source checkpoint:** 28 (R0007)  
**Scope:** Corrected build environment and relocatable integration.

The pinned Mach Makefile distinguishes public MIG_USHDRS from internal MIG_KSHDRS. Three overlapping names were incorrectly exported from the internal generation lane:

- exc_server.h
- mach_exc_server.h
- memory_object_default_server.h

The private versions pulled private IPC declarations into an IOKit recipe that did not define MACH_KERNEL_PRIVATE or MACH_KERNEL.

| exc_server.h version | SHA-256 |
| --- | --- |
| Public | `61f52312677a8da72b443dfc01af29208c97b7cb3f92f0b2ebfa54c71e3924f2` |
| Internal | `ae33d35acede799473132facdf82ba2463f25e78711460481c372adcd60fa608` |

The previous export symlink was preserved; only the three overlapping files were replaced in the new 198-entry export directory. The 14 public generated headers were inventoried. Component-local OSFMK kernel headers remained internal.

## Minimal IOKit include shim

The old SDK tree was a minimal shim, not an Apple SDK. The corrected IOKit path used pinned libsa string.h and the SAN export overlay, deliberately without kernel/types.h. The actual successful dependency list excluded that types header, the internal MIG overlay, mach_pagemap.h and mach_ldebug.h.

The original strict IOKit recipe retained -Werror with seven explicit newer diagnostic groups demoted: reserved-identifier, pre-c11-compat, unsafe-buffer-usage, four-char-constants, shadow-header, declaration-after-statement and switch-default. No global demotion was used.

## Results

IOHibernateRestoreKernel.o: compiler exit 0, 875 warnings, zero errors, 54,504 bytes, ten undefined references, verified _hibernate_kernel_entrypoint export. SHA-256 `f7c4adf87bda11edc63ebb84789f0ef1c0d0d373ed2eb68336785dcb614baf2b`.

An earlier ad-hoc overlay produced the same hash, but the canonical build followed correction of the actual export tree.

The prior 812 inputs were revalidated and the new object added. ld64 -r exited 0; 14,404,924 bytes; undefined 972 to 969. The resolved symbols were _hibernate_kernel_entrypoint, _hibernate_page_bitset and _hibernate_page_bittst, with no new unresolved references.

Output SHA-256: `ab7c7b95c1ee8c234067ebba4f0043e925a454d4960a8e91548a830d05760162`.

The source journal retains the header manifest, corrected export result, canonical compile and link evidence. No hibernation runtime functionality was demonstrated. All prior outputs remained separate, and the C++/IIG provider work remained open.
