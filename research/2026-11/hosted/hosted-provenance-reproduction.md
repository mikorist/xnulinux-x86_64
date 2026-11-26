# Hosted source provenance and reproduction research

Research window: checkpoints 378-397, November 26, 2026. XNU 8020.140.41, pinned commit `27b03b360a988dfd3dfdf34262bb0042026747cc`.

## Source and build checks

- Static MACH_IPC startup inventory: 44 records, including 37 distinct kobject descriptors. Native callbacks were not activated.
- The private hosted candidate has 258 manifest inputs; 117 generated outputs reproduce exactly. Source reconstruction and upstream verification cover 145 distinct inputs, including eight retained BearSSL/NetBSD files. Original notices were restored for several extracted fragments without changing executable tokens.
- The observed runtime closure is 174 inputs. Of those, 109 have reconstruction or upstream verification and 65 local adapter/build files have hash-verified historical copies. Seven lack explicit SPDX notices. Technical provenance is not legal clearance.
- Fifteen native reference translation units were rebuilt from an isolated closure of 496 inputs: 420 pinned Git blobs, 42 regenerated configuration headers, one generated version header and 33 regenerated MIG headers. Dependency records match the closure exactly. All 15 complete Mach-O objects are byte-identical to their references.
- The original configuration tool was also rebuilt from pinned sources with Bison, Flex and GCC 14. All 42 required configuration headers reproduce exactly. The retained LLVM and MIG toolchains are still prerequisites.
- The retained full-image link recipe passed after verifying 1,089 input hashes and substituting 14 freshly reproduced objects. All 35 section descriptors/data and non-STAB symbol tuples match. The complete image hash differs in UUID and LINKEDIT metadata, including when replayed with original paths. Full-image bit identity and a fresh whole-kernel source build are not established.

## Runtime regression

Fresh private Git-tree replay of the 258-input candidate and a reduced 174-input package both pass 94 marker groups on each of Linux 7.3.5-2-liquorix-amd64 and 6.19.14-2-liquorix-amd64. These are isolated Intel-model QEMU TCG component tests, not native hosted XNU boot. No host module load or physical qualification was performed.

## Initial CPU vendor probe

Separate userspace CPUID probes on an Intel i5-7500T host report GenuineIntel for Broadwell-v2 and AuthenticAMD for EPYC-v1 under QEMU TCG. The Broadwell model reports unsupported PCID, TSC-deadline and INVPCID; the EPYC model reports unsupported FXSR optimization, misaligned SSE, OSVW, TOPOEXT, NRIP-save and XSAVEC. These omissions are explicit limitations, not features to advertise. No XNU was executed in the AMD-model guest. AMD physical and native XNU qualification remain open.

## Scope and next step

The full hosted source candidate remains private pending local authorship, derivative notices and redistribution review, and additional complete-source/toolchain reproduction work. This report advances technical reproducibility only. The next native integration step remains IPC startup dependency work, with Linux-owned host resources and the existing APSL/GPL boundary preserved. The ARM64 reference remains unchanged.
