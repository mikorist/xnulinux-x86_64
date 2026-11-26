# Cross-host OSFMK reproduction and AMD KVM component qualification: checkpoints 418-437

Research date: 2026-11-26. Monterey XNU 8020.140.41, pin `27b03b360a988dfd3dfdf34262bb0042026747cc`. This report supersedes the relevant open compiler and KVM findings in the [previous cycle](parallel-intel-ryzen.md).

## Independent source toolchain and compilation

LLVM revision `58c46bae21181fb4240cf964461bea738d96d50e` and the retained UniXNU compiler patch were reconstructed on Ryzen. All nine modified source hashes match the reference. The independent Clang 24 build completed 3,323 Ninja steps, passed the XNU builtin probe and installed the driver and resource headers. All 15 initial reference objects and dependency maps match Intel exactly. Compiler executable identity is not claimed.

The expanded OSFMK C inventory reached 200 of 297 reference objects, including a corrected hardlink identity for a pragma-once header. The remaining 73 generated inputs were independently regenerated: 34 match directly, and 39 generated C sources match after restoring only the historical MIG timestamp comment. Raw outputs were retained. The pinned syscall generator also reproduced its configured input and output.

All 290 historically successful original-recipe C objects now match across hosts. Four historical compatibility objects also match. Three previously diagnostic-relaxed units were replaced by new strict Intel/Ryzen references: `mach_kernelrpc.o`, `vm32_user.o`, and `vm_map.o`. Fresh kernel-mode MIG server headers supply the correct declarations; an isolated one-line early return in the null-task case avoids jumping across VLA initialization while preserving the return value. All three compile with implicit-function-declaration diagnostics treated as errors, and all 407 input hashes and dependency maps match. The pinned XNU checkout was not edited.

## Reproducible OSFMK relocatable

Both independently built ld64-711 linkers (cctools-port revision `e101a6940dcb5988808a16626bc43851f00dc05f`) linked the same 297 selected C objects successfully with `-r -arch x86_64`. Initial outputs differed in debug provenance; all 21 section contents and relocation counts, 6,581 external symbol records, and the 932 undefined symbol names matched. Canonical paths equalized the string table size. The remaining discrepancy was traced to 292 N_OSO records containing input object modification times.

Copying the hash-verified inputs to matching staging paths and assigning epoch zero to the copies, without changing the original objects, produced the same 4,598,216-byte Mach-O x86_64 relocatable on both hosts.

SHA256: `1c5b45fcd55236d54703f0b69d8c0ddf2b2a2adba1bc867969a077f3aa8fa5d4`.

The 297 selection consists of 290 original, four historical compatibility and three new strict reference objects. This is not an assertion that every historical object is unchanged, that the integrated MIG provider ABI is qualified, or that the complete kernel links or boots. Assembly and other subsystem integration, outstanding undefined symbols and runtime verification remain open.

## AMD nested KVM and SRSO

A separate approved fixed-input test interface on the actual Ryzen 7 5700X host enabled nested KVM component tests without changing generic development isolation. Both selected Linux guest kernels, 7.3.5-2-liquorix-amd64 and 6.19.14-2-liquorix-amd64, now exit normally and match all 94 functional marker groups. Serial output interleaving was resolved by sending the three guest init markers through the kernel log; module binaries and the strict verifier remain unchanged.

Both strict runs remain HOLD solely because of the SRSO guest boot warning, which is independently reproduced before init in a module-free guest. The owner reported Windows mitigation enabled, but WSL and a separate Alpine Hyper-V guest continue to expose a vulnerable status and no usable microcode revision. The physical firmware/hypervisor exposure cause is not proven. No mitigation or verifier was weakened. Functional component evidence does not establish clean strict AMD qualification, bare-metal AMD execution or a complete hosted XNU boot.

## Remaining gates

Continue the shared Intel/Ryzen build with integrated MIG provider consistency and additional kernel components. Keep strict SRSO HOLD separate from functional development. Source redistribution and licensing review, full-image reproduction and end-to-end hosted runtime remain open. This documentation increment contains no private source snapshots or binary artifacts.

**CP460 update:** [native AMD Linux KVM](native-amd-kvm.md) passed both strict component replays and SRSO Safe RET; the nested Hyper-V results above remain historical and platform-specific. Guest TSA remains open.
