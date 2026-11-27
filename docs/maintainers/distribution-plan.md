# From research tree to public downloads

Planning decision: November 27, 2026, CP631. The maintainer delegates technical staging to the documentation/integration agent. These are acceptance gates, not a release announcement.

## Repository layout

Continue the approved version-target layout incrementally. Monterey and Tahoe descriptors already exist, with Tahoe research-only. Add new qualified sources, target-specific build recipes and tests at their intended paths. Keep the existing shared FKI, loader and Linux interfaces in place. Do not move code merely to make the directory tree look finished.

CP637 is the first scheduled layout and distribution readiness assessment, not a promised release date or permission to skip earlier technical reviews. At subsequent regular reviews, identify small migration candidates, inspect consumers and paths, verify source and license identity, test the actual build and regressions before and after, and publish a separately reviewable move. Shared components remain shared only where compatibility is established. Keep historical evidence and the ARM64 reference intact. Earlier open technical review windows remain open until their own criteria are met.

## Distribution stages

| Stage | Candidate | Acceptance gate |
| --- | --- | --- |
| A: userspace research tools | Existing public Mach-O structural validator and replay verifier tests | Clean public checkout, complete licensed inputs, documented compiler/runtime and dependencies, independent fresh build/test on both development hosts, matching designated artifacts or documented non-reproducibility held for review, test results tied to hashes, unprivileged execution |
| B: standalone research kit | Monterey owned PID 1 fixture and exact QEMU-only kernel/loader/root/initrd bundle | All distributed inputs and corresponding sources cleared; clean build from published or lawfully obtainable pinned source; independent reproduction, exact artifact hashes, documented isolated ordinary boot replay on both hosts, verified failure handling and no host disk/module changes; no claim of AMD runtime support |
| C: hosted technical preview | Qualified version/vendor-specific hosted components and runtime | Actual physical hosted execution and lifecycle, repeatable start/stop and recovery, protection and resource ownership, reviewed source and licenses, tested install/removal instructions and explicit supported configurations |
| D: product release | Qualified headless, desktop or seamless modes | End-to-end mode-specific verification, supported hardware/host matrix, reproducible packaging, recovery and release checklist |

Stage A preparation can begin now; CP637 is the first readiness assessment. Stage A does not depend on clean-source reproduction of the entire XNU kernel or completion of AMD boot, because it distributes only separately qualified userspace tools. Stage B depends on the complete source/provenance and redistribution gates for its own contents. CP627 ordinary standalone completion is valuable evidence but does not itself clear Stage B. CP639 reproduced the full retained link with 28 regenerated and 1,086 retained objects; this is not a clean full-source build. Tahoe preparation continues without changing the hosted implementation entry gate.

## Release packaging

Keep source, small synthetic input fixtures, build recipes, tests, documentation and manifests in Git. Put generated executables, archives and boot images in GitHub Release assets, not repeated binary commits. Use a distinct research prerelease tag such as research/monterey/cpNNN-tools or research/monterey/cpNNN-standalone only when the relevant gates pass and the exact public source commit is verified. No product version is allocated now.

Each release includes a README, scope and known limitations, exact source commit and dependency pins, build environment/instructions, license notices and corresponding source information, SHA256SUMS and a machine-readable artifact manifest, with sanitized test evidence. Verify archive contents and remote downloads against the intended hashes. Use a draft for inspection; publish only after review by the central integrator. Never include proprietary macOS images, frameworks or SDKs without lawful redistribution authorization, private logs or credentials. Do not publish unknown-license code or binaries. Hashes prove identity, not authenticity, safety or successful execution.

## Visual evidence

Add screenshots and short recordings only when they show a real measured result. Keep modest, losslessly readable screenshots under docs/evidence/ by version/checkpoint, with a caption, artifact identity, configuration and link to the actual report. Larger recordings belong in a release or linked evidence archive. Review for personal data and secrets. A console capture must say whether it shows TCG, native component tests or hosted execution. Do not illustrate a planned desktop as a working one. Visual evidence supplements logs and reproduction, never substitutes for them.

## References

- [Version targets](../version-targets.md)
- [Release checklist](release-checklist.md)
- [Versioning](versioning.md)
- [GitHub release guidance](https://docs.github.com/en/repositories/releasing-projects-on-github/about-releases)
- [Reproducible Builds definition](https://reproducible-builds.org/docs/definition/)

CP633: the existing public structural validator source test passes with GCC on both hosts and Clang on Ryzen. Intel Clang has a missing UBSan runtime dependency. This advances Stage A source test evidence only; binary packaging, reproducibility and final license review remain open. [CP633](../../research/2026-11/checkpoint-633.md).

CP634-635: physical Intel Clang UBSan dependency restored (isolated MCP dependency remains HOLD), and public Python verifier tests pass on both development environments. Review package source/license closure and reproducibility before CP637. No release authorized.

CP636: identical source-only archive and unpacked tests on both hosts. The Python verifier references a generic MIT template with unfilled copyright attribution. Attribution and binary reproducibility remain HOLD; no archive or executable published. [CP636](../../research/2026-11/checkpoint-636.md).

CP637 readiness assessment completed: four fresh GCC builds pass, byte-identical within each environment but different between GCC 14.2 and 15.2 environments. Stage A remains HOLD for attribution, common pinned binary reproduction, self-contained documentation and separate release approval. No release or tag created. [CP637](../../research/2026-11/checkpoint-637.md).

CP638: identical self-contained private source archives and unpacked tests on both hosts; the Python sources match the retained CP335 manifest. Copyright attribution and common pinned binary build still HOLD. No archive or executable released. [CP638](../../research/2026-11/checkpoint-638.md).

Historical disposition through CP641: the CP637 assessment was complete, Stage A remained HOLD after CP638. The self-contained instructions and source staging passed their scoped checks; final package review, attribution, common pinned binary recipe and separate owner release approval remained required. No source relocation or binary distribution is authorized by the CP641 platform plan.

Current disposition through CP755: CP742 and CP744 independently reproduce separate source-only packages; CP744 completes the scoped private verifier notice, without public source integration. CP743 verifies the documented synthetic contract, and CP755 reproduces an instrumented object from one shared preprocessed input with 229/229 native checks per host. Independent native preprocessing and final binaries differ. Common sysroot/linker/runtime, final package and public notice review, and separate release approval remain open. Stage A remains HOLD. See [CP643-755 research update](../../research/2026-11/updates-643-755/README.md).
