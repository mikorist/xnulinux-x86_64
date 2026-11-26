# 10. Reconstructing missing component recipes: 841 inputs

**Date:** 2026-11-25  
**Source checkpoint:** 31 (R0010)  
**Scope:** Component compile and relocatable link.

Direct generated Makefile dry-runs recovered recipes for 33 previously omitted C targets and IOAsmSupport.o. Reconstructed BSD, libkern and security recipe arguments were compared token-for-token with earlier targets. IOKit recipe arguments were checked against the corrected hibernation recipe. Target translation, unsupported driver-option removal and isolated output redirection were explicit; original include ordering and warning policies were retained.

## Results

28 of 34 targets passed (27 C, one assembly). The new objects were:

- BSD: nfs4_subs, dtrace_xoroshiro128_plus, devfs_vfsops, net_stubs, if, ether_inet_pr_module, ndrv, network_agent, pf_ioctl, pf_norm, pf_pbuf, if_llreach, content_filter, restricted_in_port, classq, classq_subr, pktsched_fq_codel, ioconf, kperfbsd.
- libkern: kernel_mach_header, infback, corecrypto_sha1, coretrust, apple_encrypted_archive, amfi.
- security: mac_file.
- IOKit: IOStringFuncs and IOAsmSupport.

The if.o exports confirmed the two SYSCTL macro-provider candidates. Two VFS targets failed the aligned-byte-array type diagnostic; four syscall targets lacked generated sources because dry-run does not execute makesyscalls.sh.

The configured syscall master hash was `b216ba0bd79748f5299c2c02b40c0fc6793a6ae3e9d3df02209ac604797be2c4`. The four generation modes were systrace, audit, table and names.

## Integration

All prior 813 inputs were validated against their original manifest and 28 new inputs verified. The 841-input relocatable link exited 0 with only the missing Frameworks directory warning; 15,005,728 bytes.

SHA-256: `e1347b59d1f9e30aab81417b42bb77a5b9f805348d8a85ebe08bf9b5d9fbe572`.

| Before | Resolved | New | After |
| ---: | ---: | ---: | ---: |
| 969 | 249 | 11 | 731 |

The introduced references concerned mbuf operations, MAC extended-attribute operations and NFS attribute/path/client structures. The original exact lists and manifests were retained.

Component coverage reached 841/984: 820 C, two C++ and 19 assembly. All configured assembly targets now built. Remaining: 26 C and 117 C++. The original build.py and per-target commands, stdout/stderr, RESULT.json, OBJECTS.tsv and link symbol delta lists are local reproduction evidence. No boot or final executable was established.
