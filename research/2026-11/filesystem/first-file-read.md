# First named file read through XNU VFS

**Date:** 2026-11-25  
**Status:** Confirmed  
**Scope:** Standalone Legacy QEMU TCG, read-only HFS+ RAM disk.

Following the [first root mount](first-root-mount.md), the HFS sizing expression was replaced by equivalent integer arithmetic. The host comparison covered 100,005 cases. Kernel 24 reproduced the root mount with no device-not-available exception; the recorded 1,643 page faults remained classified.

An owned 39-byte file was added to a disposable 8 MiB HFS+ fixture. An initial host-tool attempt damaged its disposable copy; the original root image remained unchanged. A separate open-source HFS utility successfully created the fixture, which passed independent filesystem checking and byte comparison.

## Kernel 25 results

| Check | Result |
| --- | --- |
| Strict link | 1,089 inputs, zero undefined |
| Named lookup | /probe.txt, return 0 |
| VFS read | 39 exact bytes |
| EOF residual | 25 bytes, sentinel preserved |
| Missing pathname | ENOENT (2) |
| Disk integrity | Entire 8 MiB unchanged |
| Verifier / QEMU exit | 0 / 0 |

The test used actual vnode lookup and VFS/HFS read operations, not a direct RAM copy. The file vnode differed from the root vnode.

Kernel SHA-256: `60734fdbcf5c677402a40fa55310969178c0c88547c122c09d8a96d66ff7c153`

File SHA-256: `176667f80465651448a3e7e2fbce5dcf57b928976f017797d9a33ec77374b9d5`

## Limits

This is a kernel-mode file-read test. It does not establish PID 1, ring 3, user syscalls or hosted execution. The public reproduction bundle and source license review remain pending.

**Source records:** checkpoints 152–154.
