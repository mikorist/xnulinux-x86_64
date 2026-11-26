# 13. Completing configured C and assembly coverage

**Date:** 2026-11-25  
**Source checkpoint:** 34 (R0013)  
**Scope:** Explicit compatibility track, 867-input relocatable link.

The 852-input baseline was preserved. All 15 remaining C targets were rebuilt from their recorded recipes with narrowly identified changes. All passed object checks.

## UIO size and alignment

The pinned uio_stackbuf_t is a char typedef with an eight-byte alignment requirement. Clang rejected arrays whose element size was one byte but alignment eight. This was a hard language diagnostic rather than a warning.

Isolated copies retained each UIO_SIZEOF expression and array name while applying alignment to the entire byte buffer, rather than to its individual byte elements. Thirty-five declarations in 13 configured sources were affected: 34 automatic arrays (including a VLA) and one actual setxattr_ctx member. The nonconfigured vn.c occurrence was untouched.

Compile-time checks and emitted LLVM IR verified intended byte size, fixed/variable allocation alignment and actual member layout. The validation object was not linked. No runtime equivalence was established.

## Firehose

Two additional objects used the explicit OS_FIREHOSE_SPI=1 configuration because the pinned external libdispatch header guarded the required declarations. Both reproduced earlier probe hashes. This was not an exact-recipe result. The original build rules also required libfirehose_kernel and libcc_kext; those archives had not been located in the research tree. The resulting external references remained real dependencies.

## Link evidence

867 distinct validated inputs, ld64-711 exit 0; 16,164,781 bytes. SHA-256 `2291e77c55ce68dc881c19847637245628b3ad2198bf50b741b6b2c38c0f77d1`.

| Before | Resolved | Introduced | After |
| ---: | ---: | ---: | ---: |
| 713 | 463 | 11 | 261 |

The new dependencies included six IOKit platform/resource functions and five Firehose library symbols. The original exact lists, source diffs, object hashes and layout probe evidence were retained.

Coverage now comprised all 846 configured C targets, 19 assembly and two C++ objects: 867/984. The 117 remaining C++ targets included 17 generated IIG implementations. Component coverage did not establish complete linking, runtime ABI or boot. The next investigation concerned C++ recipes, generator dependencies and final-link inputs.
