# 18. Alignment-safe wire parsing and the first generated implementation

**Date:** 2026-11-25  
**Source checkpoint:** 39 (R0018)  
**Scope:** Host fixtures and compile-only provider candidate.

The original transport processes object-reference descriptors separately from arbitrary port arguments. The generic parser prototype therefore checked structural bounds without assuming that a sender annotation determines every received descriptor's disposition.

The isolated wire parser copies header, descriptors and content metadata into aligned locals. It validates capacity, size, version, supported descriptor types/counts and object-reference bounds, without returning typed pointers into potentially misaligned content. Right transfer and method-specific payload validation remain separate.

The local build-test.py compiled actual pinned types with the Darwin recipe to LLVM IR, retargeted that IR to Linux ELF and executed a host fixture. All four stages exited zero; 121 checks covered byte alignments, mixed descriptors and invalid structure cases. IR showed alignment-one input accesses. This was not live Mach IPC.

## IODispatchQueue

The adapter retained the measured packed wire sizes and offsets with byte content and aligned typed locals. Twelve layout assertions covered SetPort and Create request/reply structures. The synchronous reply extent, method ID, descriptor shape and string termination were checked; the nonvirtual SetPort handler used a typed thunk. Original transport accesses were not changed.

The full generated unit compiled without additional warning demotions: 60,248 bytes, SHA-256 `b0a722970089f9117ca1a53617d61f09ebd171f645b9f1e31e237e0888abc121`.

The extracted real adapted invokers passed 30 host checks using opaque identity tokens, not live XNU objects. Separate and overlapping buffers, both wire-aligned positions and malformed cases were tested. An initial fixture-only lifetime diagnostic was resolved by giving the token static storage rather than suppressing the diagnostic.

The 67-object probe manifest now included the first of 17 generated units. Accepted inputs remained 869, undefined 261, total artifact coverage 936/984. Original wire parser, queue adapter and extracted fixture commands remain in the local evidence archive. No production ABI, rights transfer, kernel dispatch or boot was demonstrated.
