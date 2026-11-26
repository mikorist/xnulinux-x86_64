# 3. Current-root provider expansion to 794 inputs

**Date:** 2026-11-25  
**Source checkpoint:** 25 (R0003)  
**Scope:** Historical component inventory and offline link.

## Profile

XNU 8020.140.41, pinned commit `27b03b360a988dfd3dfdf34262bb0042026747cc`; RELEASE X86_64 NONE, KERNEL_BASE_OFFSET=0x100000; custom Clang 24, MIG-122 and cctools ld64-711.

| Component, as counted at this checkpoint | Pass | Fail |
| --- | ---: | ---: |
| BSD | 425 | 17 |
| libkern C | 41 | 0 |
| libkern C++ | 0 | 24 |
| pexpert | 10 | 0 |
| security | 21 | 1 |
| Total | 497 | 42 |

This table preserves historical accounting. Chapter 9 documents the later correction of source-language classifications without changing object validity.

NFS/gssd/lockd exports, vfs_conf, dtrace_ptss and mac_base fixes entered the main manifest. Ten UIO alignment probes and two Firehose SPI probes remained outside exact-root-recipe acceptance.

The known blockers included generated DriverKit headers, IPC private-type visibility, incomplete SDK type conflicts, Firehose configuration and individual failed targets. Global private macro changes were not accepted.

## OSFMK and combined link

The current-root 297-target OSFMK build comprised 290 exact-root-recipe and seven explicitly marked compatibility objects. Its 4,612,144-byte relocatable SHA-256 was `1bca3dbcdb9c7d611411978ddc40f3a4baba81e76cb03369c8e8c7bd8b24314a`.

The combined link used 297 OSFMK and 497 other manifest-verified inputs. ld64 -r exited 0; 14,316,336 bytes, 1,293 undefined; SHA-256:

`a5cce05e3837c8899074cbcd87e1405cd5862de8351c57f19d47024fa04c096f`

The historical description was C-only: no active assembly or generated IIG implementation objects. Later inventory identified two C++ source-backed objects among the inputs.

## First failed genassym extraction

The root dry-run selected 18 active assembly recipes. Its genassym command emitted assembly text under the historical genassym.o filename using -S, not -c; the next sed recipe extracted assym.s. The first extraction attempt looked for -c and stopped before compiler execution. No new offset file had been produced in that attempt.

The recorded next step was to replay the actual generator and extraction recipes before assembling all 18 units.

## Evidence

Original OBJECTS.tsv, build-osfmk-297-root.py, build-osfmk-297-root-compat.py, PROVENANCE.tsv, RESULT.txt and ld64-r.command are retained locally. The combined RESULT.txt independently inspected for this draft confirms 794 inputs, 1,293 undefined and the output identity above. Public build scripts are not yet exported.

No module, hosted ABI or boot had been demonstrated at this checkpoint.
