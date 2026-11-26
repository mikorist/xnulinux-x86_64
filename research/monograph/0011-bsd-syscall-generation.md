# 11. BSD syscall generation and the 845-input link

**Date:** 2026-11-25  
**Source checkpoint:** 32 (R0011)  
**Scope:** Generated sources and offline linking.

The original unifdef -URC_ENABLE_XNU_PRODUCT_INFO_FILTER operation regenerated the configured syscall master byte-for-byte. The pinned makesyscalls.sh generated sysproto.h and syscall.h; raw comparison initially differed only in the generated provenance-path comment. Normalized header content matched, and the exact diffs were retained.

Four missing C sources were generated through the original systrace, audit, table and names modes, then compiled with the recorded BSD recipes and redirected source/output paths.

| Object | Bytes | SHA-256 |
| --- | ---: | --- |
| systrace_args.o | 115800 | `328018e1703dec93405e8df78ff71000136e1f56dac34255ced8bf07ecb39f62` |
| audit_kevents.o | 3264 | `693d4db18734b4b8da931b6c4d572c91c6469eb201171e34831f2b9ec3cd1e94` |
| init_sysent.o | 70968 | `903eb00a2b37cab844ba7b813c6c3f7720871fe06c473fc37c4220d6ae60f8e5` |
| syscalls.o | 31288 | `c97c6b69791ef5912ee28ab29e05c2a6e10d6622d50cd177cc26e1c2c7ef8443` |

All four passed Mach-O format and symbol checks. Existing headers were not overwritten.

The new 845-input link exited 0; 15,112,112 bytes; SHA-256 `aa42bc2993f1366fb30ecb391a87545c25db58df59c4006985b13d34987d6e8a`.

Undefined symbols increased from 731 to 904: seven resolved and 180 introduced. The real syscall table exposed additional BSD implementation dependencies, including ordinary file and socket operations. The increase was expected from newly linked real dispatch structures, not loss of previous providers.

Coverage reached 845/984 (824 C, two C++, 19 assembly); 22 C and 117 C++ remained. The original build.py, header diffs, exact manifests and symbol deltas are retained locally. No live syscall or user-mode execution was tested.
