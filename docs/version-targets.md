# Extensible version targets and Tahoe entry plan

Adding another XNU version target must extend the existing XNULINUX platform rather than create a separate project. Share validated platform components, not unproven internal ABI assumptions.

## Entry sequence

| Stage | Work | Gate |
| --- | --- | --- |
| CP628-630 | Finish current Monterey development series; retain source comparison | No migration |
| After CP630 | Bounded Tahoe preparation: source pin review, toolchain and dependencies, interface and configuration inventory, proposed target descriptor | Source research only |
| Monterey hosted development | Introduce explicit target identity in common build/test orchestration where justified by actual requirements | Existing Monterey regression evidence preserved |
| Tahoe implementation | Separate pinned source, build/link qualification, owned userspace and hosted qualification | Stable physical Linux-hosted Monterey Intel baseline |
| Product layers | Headless, desktop and seamless for both | Version-matched runtime and independently qualified shared layers |

The hosted entry gate requires genuine hosted user-program execution, repeatable lifecycle and host recovery, preserved protections, documented inputs and regression evidence. Physical testing requires its existing approvals. Monterey desktop completion and full AMD boot are not extra prerequisites for Tahoe implementation; AMD development continues in parallel.

## Proposed logical organization

Keep existing fki-ko/, linux/, scripts/ and tools/ responsibilities. Retain the shared loader interfaces in xnu-ko/. Introduce small declarative version descriptors (proposed targets/monterey/ and targets/tahoe/) for source pins, build profiles, runtime manifests and references to version-specific adapters, patches and tests. Validate the first descriptor against the existing Monterey artifacts before claiming generic build support. This is a proposed layout, not a relocation of existing files.

Keep sources, generated headers, binaries and runtime dependencies separate per target. Qualify each CPU vendor and version independently. The original ARM64 reference stays unchanged.

## Current evidence

[CP628](../research/2026-11/checkpoint-628.md) compares the public source trees. Its 95.9% retained-line statistic covers only common x86 paths; it is not evidence of ABI or runtime compatibility. The Tahoe reference revision remains research-only; no build or boot is qualified.
