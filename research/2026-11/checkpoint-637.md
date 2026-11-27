# CP637: First research distribution readiness assessment

**Outcome: same-environment binary reproduction PASS; Stage A distribution HOLD.** November 27, 2026.

Both development environments independently built the C validator twice from the exact unpacked CP636 source package, retaining all original C11, warning and UBSan options. All four unprivileged test executions passed, 229 checks each (916 total).

- Intel development environment: Debian GCC 14.2, 27,008-byte executable, SHA-256 `6d6cd7dea398332143a04272d693d261861bbfc3d0f63e6e7f36e29a915ddb64`.
- Ryzen development environment: Ubuntu GCC 15.2, 22,136-byte executable, SHA-256 `03e45beea9965a26007c0471462a02747d40886f16ffcc22767a91c2ce9fe7fb`.

The two builds within each environment match exactly. Cross-environment bytes differ; the compiler and distribution differ, and a common pinned build environment has not yet been tested. CP636 source archive reproduction remains PASS.

Remaining release gates: Python verifier copyright attribution and final license disposition, designated binary reproduction using a common pinned recipe, self-contained package documentation, and separate release approval. The isolated Intel Clang dependency remains HOLD. No binaries or archives have been published.

## Regular review boundary

All 139 existing primary evidence hashes in CP498-636 were rechecked successfully. CP637 completes the recording of the seventh 20-checkpoint window, CP618-637. Integrity and chronology do not constitute technical review closure. The oldest open window remains CP498-517; no source qualification or ledger promotion is implied.

Next: resolve the scoped attribution and build recipe; continue ordered technical review and independent Monterey and Tahoe research. Existing kernel and implementation gates remain unchanged.

Primary evidence SHA-256: `48c0fc93775aa76418a86f33e759b07e88c94243365e48ddc2f4aea4e25184c1`.
