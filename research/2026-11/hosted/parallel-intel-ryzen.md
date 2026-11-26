# Parallel Intel and Ryzen development: checkpoints 398-417

Research date: 2026-11-26. XNU 8020.140.41, pin `27b03b360a988dfd3dfdf34262bb0042026747cc`.

## Cross-host development and guest regression

The AMD Ryzen 7 5700X WSL2 environment is qualified for isolated source development, GCC 14 builds and QEMU TCG. Both exact Linux targets, 7.3.5-2-liquorix-amd64 and 6.19.14-2-liquorix-amd64, were rebuilt independently from the existing 174-input hosted component candidate. Under Broadwell-v2 TCG both builds passed all 94 strict marker groups, with import manifests identical to the Intel reference. This is an Intel CPU-model guest test on AMD hardware, not native AMD XNU execution.

EPYC-Milan-v1 TCG replays on the two kernel targets matched all 94 marker groups and exited normally. The strict verifier rejected the SRSO guest boot warning; 15 unsupported TCG feature warnings were retained. An independent module-free guest reproduced the SRSO warning before userspace initialization. The strict AMD runtime result remains HOLD. No security mitigation or verifier was changed. KVM is not available within the qualified isolated environment.

## Source toolchain reproduction

- Fresh GCC 14.3, Bison, Flex, CPIO and supporting build tools were qualified.
- Pinned XNU config tool and original doconf produced all 42 required configuration headers with exact reference hashes.
- Pinned cctools-port e101a6940dcb5988808a16626bc43851f00dc05f built ld64-711 and the assembler; synthetic Mach-O layout and assembler equivalence tests passed. UUID support differs from the reference build; complete XNU linking is not qualified on Ryzen.
- Pinned bootstrap_cmds-122 (3cc6b1cf291f8fccfbf6444d6630a02a54c16831) was rebuilt. All 33 required MIG headers were independently regenerated with exact reference hashes.
- All 496 compiler inputs were reconstructed: 420 pinned source blobs and 76 freshly generated headers, including the Darwin 21.6.0 version header. All input hashes match the reference.

## Compiler and IPC boundary

Stock Clang 21 compiled 10 of 15 reference translation units; five fail because XNU-specific type builtins are missing. None of the ten objects is byte-identical to the custom Clang 24 reference. All ten have identical per-unit dependency sets and dependency hashes, and identical external symbol name/type sets. Selected DWARF records for ipc_entry, ipc_space and ipc_kobject_ops also match. These are static comparisons, not executable ABI or whole-image qualification.

Original host_notify_init and ipc_voucher_init bodies with the original queue initialization macro were exercised in an isolated userspace fixture on Intel and Ryzen. All two notification and 127 voucher queue heads passed repeated initialization checks under GCC and Clang with undefined-behavior instrumentation. No native IPC objects, rights, locks, or startup callbacks were activated in the hosted kernel.

## Remaining gates

The custom Clang 24 toolchain, complete source-only kernel rebuild, full hosted boot, strict AMD runtime and physical AMD qualification remain open. The existing integrated hosted component candidate remains held for source provenance and licensing review. This documentation increment does not export private sources, binary artifacts, or claim an installable release.
