# 6. Rejecting an unproven hibernation provider

**Date:** 2026-11-25  
**Source checkpoint:** 27 (R0006)  
**Status:** Historical failed build and rejected candidate.

An existing IOHibernateRestoreKernel.o had the desired _hibernate_kernel_entrypoint export, Mach-O x86_64 format, 54,216 bytes and SHA-256 `7f6a9c2ebf6726ddf29bb7d23b7f36ab55d47462b4ec449128d0a3a1b47482e1`.

That evidence was insufficient. Its recorded attempt exited 1 with 26 warnings and 960 errors; the old base offset differed from the current 0x100000 profile. The object timestamp followed the failed compilation, but no successful matching command was established. It was excluded from the current 812-input baseline.

## Current-root reconstruction

A direct generated IOKit Makefile dry-run recovered the real IOHibernateRestoreKernel.c recipe for RELEASE X86_64 NONE, BUILD_LTO=0, IOKIT_KERNEL_PRIVATE, the current base offset and custom Clang 24. The make command exited 0 despite missing xcrun diagnostics.

After only the recorded target translation, unsupported option removal and output redirection, the compiler exited 1 with 310 errors under the strict warning policy. Private IPC types and generated header availability were investigated alongside newer Clang diagnostics.

## Compatibility attempt 01

The isolated exploratory run added MACH_KERNEL_PRIVATE, MACH_KERNEL, an exported mach_pagemap.h symlink and a temporary global warning demotion for diagnosis. It produced 181 warnings and 13 hard errors, including daddr_t and clock_t type conflicts and setbit/clrbit declaration conflicts. No object was produced.

The generated mach_pagemap.h was 22 bytes and defined MACH_PAGEMAP 0. Its SHA-256 was `8394f10f9994f7cf170b5af3526c80df0fa83bf80c2aeddc179e9554df1b8894`.

## Decision

Preserve the accepted 812-input image and all failure logs. Do not fabricate typedefs, patch the original source to hide include errors or accept the stale candidate. Inspect public versus private generated interfaces and the actual SDK include path.

**Correction:** the subsequent investigation established that the type conflicts belonged to the exploratory macro changes, not the original IOKit recipe. Chapter 7 records the actual export defect and successful correction. This chapter preserves the original failed investigation without promoting its preliminary diagnosis.
