# CP638: Self-contained source staging and historical Python source identity

**Outcome: portable source archive and historical source identity PASS; distribution HOLD.** November 27, 2026.

The four-entry retained CP335 result manifest was reverified. Both Python program/test source files match the later public source bytes exactly, with the original MIT SPDX markers retained. This establishes a retained source lineage, not a legal determination of the copyright holder.

Both development environments independently assembled a nine-member, 5,632-byte private source archive from the verified CP636 input files, preserving all five program/runner files and both existing license texts. A new standalone README replaces references that required the repository checkout. The archive SHA-256 is:

`ac5d05a7b1ce5c6aa23b19f5b703b9c63938b4eed88d915bd1fb686ac0ae5245`

Both separately unpacked archives pass the C validator's 229 checks with GCC/UBSan and all three Python unit test methods. No kernel inputs or additional Python packages are required. The Python attribution question and common pinned binary build environment remain open. Neither Docker nor Podman was found on PATH in the two isolated development environments; no runtime installation or isolation change was attempted.

No archive or binary was released. Existing kernel qualification and release approval requirements remain unchanged.

Next: prepare a common pinned build environment through approved infrastructure and continue independent Monterey/Tahoe work.

Primary evidence SHA-256: `8fbd01154616f05f8918a8cc0e0a07afb7be7526f7e33812ac8e5f36dcd73d89`.
