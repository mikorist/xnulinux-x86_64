# 12. Exact-recipe C recheck: 852 inputs

**Date:** 2026-11-25  
**Source checkpoint:** 33 (R0012)  
**Scope:** Recompiled C objects and relocatable integration.

All 22 remaining C targets were retried against the corrected export environment using captured recipes, changing only dependency/output paths. No new flags or source transformations were introduced.

Seven passed: gss_krb5_mech, ipsec, kern_shutdown, kern_symfile, nfs_vfsops, uipc_mbuf and ptrauth_utils. This was consistent with earlier header corrections, although the exact exclusive cause was not established for every target.

Thirteen UIO aligned-array failures remained: decmpfs, kern_descrip, kpi_socket, nfs_serv, sys_generic, uipc_syscalls, vfs_attrlist, vfs_quota, vfs_subr, vfs_syscalls, mac_vfs_subr, vfs_lookup and vfs_vnops. The nfs_serv target now reached that failure after its prior IPC blocker was removed. Two Firehose header/configuration failures remained: bsd/subr_log and libkern/log.

## Result

The separate 852-input link exited 0, with the existing missing Frameworks warning. Output 15,494,820 bytes; SHA-256 `8ae022f04f863e43346e6a6a59a3200e8f2c99fa066d1be0d86debfec51f31e4`.

Undefined 904 to 713: 202 resolved, 11 introduced. New dependencies included I/O mapping, shutdown/sleep notifications, VFS lookup and mount functions. The exact symbol lists and object input manifest were preserved.

Coverage 852/984: 831 C, two C++, 19 assembly; 15 C and 117 C++ remained. The next step was to inspect the actual UIO size/alignment contract and Firehose SPI configuration, with any modifications explicitly labeled as compatibility work.

The original recheck.py, per-target commands, diagnostic logs and RESULT.json are retained. No prior baseline was overwritten. No final kernel, module or boot was demonstrated.
