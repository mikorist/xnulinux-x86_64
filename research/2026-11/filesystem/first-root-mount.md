# First successful standalone XNU root filesystem mount on x86_64

**Date:** 2026-11-25  
**Status:** Confirmed, reproduced  
**Scope:** Standalone QEMU TCG; Legacy firmware path; one CPU; 512 MiB  
**Source:** XNU 8020.140.41, commit `27b03b360a988dfd3dfdf34262bb0042026747cc`

> [!NOTE]
> This result establishes a standalone root mount, not hosted FKI execution or a production HFS+ driver.

## Experiment

The goal was to mount a real filesystem through XNU's block-device and VFS paths and verify that BSD installed the actual root directory vnode.

The fixture was an 8 MiB clean, nonjournaled HFS+ RAM disk, mounted read-only through `md0`. A permanently resident experimental HFS driver was registered through the original VFS registration path.

## Results

| Check | Observed result |
| --- | --- |
| Strict kernel link | 1,089 inputs; zero undefined symbols |
| Kernel image | 21,544,224 bytes |
| BSD initialization | 77 traced calls returned |
| RAM disk | 8,388,608 bytes; 512-byte sectors |
| Root device | md0, major 1, minor 0 |
| Block read | Three sectors matched original fixture |
| HFS registration | Successful |
| HFS mount | Return 0 |
| Root mount | Return 0 |
| Root vnode | Actual directory vnode installed; VROOT verified |
| Mount flags | MNT_ROOTFS and MNT_RDONLY |
| Disk integrity | Entire fixture unchanged |
| Replay verifier / QEMU exit | 0 / 0 |

The successful replay stopped deliberately at the root lock release boundary in BSD initialization, after the inlined root-vnode installation. The root vnode matched the HFS root result, the mount list and the registered filesystem operations.

## Failed attempts and corrections

Earlier root-device tests reached ENODEV because no suitable filesystem was registered. A missing IOMedia metaclass also caused a fault during root discovery; the corrected null-root path was subsequently verified.

The first successful HFS mount replay missed the root installation boundary because the compiler inlined the expected function. It subsequently observed a process-1 exec panic on the empty fixture. The revised verifier targeted the actual root installation boundary and confirmed the mount and vnode state. PID 1 execution was not demonstrated.

The successful replay recorded 1,643 page faults and one device-not-available exception in HFS floating-point sizing code. The latter resolved before mount return, but the HFS integer arithmetic and FPU-context audit remains a qualification requirement.

## Evidence and reproduction status

The original research archive contains the strict-link manifest, replay scripts and machine-readable results (RESULT.json, HFS-MOUNT.json, ROOT-DEVICE.json, HFS-REGISTRATION.json, BLOCK-READ.json and FAULT-CLASSIFICATION.json). The public reproduction bundle has not yet been prepared or license-reviewed; this report is not a runnable installation guide.

| Artifact | SHA-256 |
| --- | --- |
| Kernel 23 | `56276f72bb54f6747a010db74305546c0f6ca6402740a760682add412524d002` |
| Loader | `1ad6bc7db1cc4a3721c3acc8851790592a1a2903c42cdce7b658fec69c104acc` |
| HFS+ fixture | `8b249ed15652b47db5090b8ff7d86db6fe7ec3f278b7dc597622c0b37a887d73` |

## Limitations

Only the known read-only fixture and standalone uniprocessor path were tested. Arbitrary media, writes, protected or corrupt volumes, production crypto and PRNG qualification, RTC, hosted execution, SMP, NMI and user programs remain outside this result. HFS source provenance and licensing require review before publishing the implementation.

Next reference checkpoints are pathname lookup, file reading and real user-mode execution.
