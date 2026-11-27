# CP636: Reproducible research tools source package

**Outcome: source archive reproduction PASS; attribution and binary distribution HOLD.** November 27, 2026.

Two independent development environments assembled a normalized tar.gz from nine exact files at the previously tested public commit c6076e925f6e2d4ebbe0c9946edba994ce88d8c7, plus generated source manifest and package notes. Both archives contain 11 regular files, are 6,270 bytes, and have identical SHA-256:

`57bc2e36755befa24f9b8c9328479ce9a08d91b7c23c1162d7a84da7292fe847`

Each archive was unpacked separately. All source bytes matched; GCC/UBSan passed 229 checks and Python passed three unit test methods on each host. The package contains source only, not a kernel, executable or proprietary SDK.

Public history identifies introduction commits 4f90aa6 and 8f9a111. All five program source/runner files carry MIT SPDX identifiers. The C validator has a component license naming contributors; the Python verifier references the generic MIT template with an unfilled copyright notice. Confirm attribution and final license disposition before redistribution. Repository-wide documentation links in the source package require the full checkout. This private staging candidate is not a published archive or a binary reproducibility result.

Next: CP637 readiness assessment, including binary reproducibility, attribution and the ordered technical review backlog. Release approval and kernel qualification gates remain unchanged.

Evidence SHA-256: `13fff2b916d70873652774f6d0aba0bd99a3b3c42fc12f097eb27d026f490a54`.
