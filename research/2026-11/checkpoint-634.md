# CP634: Restore the Clang UBSan runtime on the physical Intel host

**Outcome: physical host PASS; isolated Local MCP environment HOLD.** November 27, 2026.

With owner approval, the matching Debian libclang-rt-19-dev package (1:19.1.7-3+b1) and its three required dependencies were installed. No existing packages were upgraded or removed. The initial literal archive path check failed because the distribution uses a different archive layout; the packaged library was subsequently identified and hashed. The unchanged public CP633 runner passed 229 checks with zero failures and UBSan enabled on the physical host.

The separate Local MCP package database does not see the host installation. Its dependency status is not promoted. No kernel or protection changes. The prior CP633 failure remains part of the record.

Evidence SHA-256: `28122db074b15864287cb01e17cf788f3f0c2c961364eb340e558acc2a5bb3a8`.
