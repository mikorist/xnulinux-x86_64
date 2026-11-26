# 9. Component inventory and the 969-symbol audit

**Date:** 2026-11-25  
**Source checkpoint:** 30 (R0009)  
**Scope:** Static audit; no build or link was run.

The generated RELEASE Makefiles supplied paired OBJS, COBJS, CXXOBJS and SOBJS lists. BSD qsort.o was already in OBJS and was not counted twice.

| Component | Accepted | Configured | Missing |
| --- | ---: | ---: | ---: |
| BSD | 427 | 469 | 42 |
| IOKit | 1 | 95 | 94 |
| libkern | 41 | 73 | 32 |
| libsa | 0 | 1 | 1 |
| OSFMK | 313 | 313 | 0 |
| pexpert | 10 | 10 | 0 |
| security | 21 | 23 | 2 |
| SAN | 0 | 0 | 0 |
| Total | 813 | 984 | 171 |

The accepted language split was 793 C, two C++ and 18 assembly objects. The 171 missing targets comprised 53 C, 117 C++ and one assembly; 42 previously failed and 129 had not appeared in the earlier manifest.

This corrected the historical C-only label: priority_queue.cpp and libclosure/runtime.cpp had been built with .o suffixes. Actual libkern C++ coverage was 2 of 26; 22 had failed and two were previously omitted. The 24 failed libkern rows included two C objects, log.o and ptrauth_utils.o. Component coverage did not include all final-link-specific objects and libraries.

## Unresolved-symbol evidence classes

The 813-input baseline hash and actual llvm-nm output matched the 969-symbol inventory.

| Classification | Count |
| --- | ---: |
| UNACCEPTED_BINARY_DEFINITION | 225 |
| MISSING_TARGET_SOURCE_CANDIDATE | 662 |
| SOURCE_REFERENCE_ONLY | 37 |
| GENERATED_SOURCE_REFERENCE | 23 |
| OTHER_SOURCE_DEFINITION_CANDIDATE | 9 |
| LINKER_SYNTHETIC | 9 |
| NO_INDEXED_SOURCE_REFERENCE | 4 |
| Total | 969 |

Ten unaccepted Mach-O objects provided exact binary definitions for 225 names. These were not accepted as compatible inputs. Lexical matching found missing-target candidates for 879 names, overlapping the binary evidence. Text matches were not proof of C/C++ definitions or ABI.

Four lexical misses were traced manually to internal mbuf symbol naming and SYSCTL_NODE macro expansion. Version symbols required original generated version.o. MIG prefixes also required generator-specific investigation, not arbitrary aliases or classification as host imports.

## Reproduction and next steps

The original audit.py and TARGETS.tsv, SYMBOLS.tsv, UNACCEPTED-OBJECT-EVIDENCE.tsv, MISSING-TARGET-CANDIDATES.tsv, RESULT.json and README.md contain the audit. The runner is not yet exported. The next work targeted 33 unattempted C sources, one IOKit assembly target, 20 earlier C failures and 117 C++ targets. Final-link inputs remained separate. The pinned source and baseline stayed unchanged.
