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

## Owner-approved logical organization

Keep existing fki-ko/, linux/, scripts/ and tools/ responsibilities. Retain the shared loader interfaces in xnu-ko/. Introduce small declarative version descriptors (targets/monterey/, targets/tahoe/ and reserved targets/future/) for source pins, build profiles, runtime manifests and references to version-specific adapters, patches and tests. Validate the first descriptor against the existing Monterey artifacts before claiming generic build support. The owner approved this layout on November 27, 2026. Adopt it incrementally; no immediate relocation of existing files is implied. Preserve existing auxiliary directories and licensing boundaries.

Keep sources, generated headers, binaries and runtime dependencies separate per target. Qualify each CPU vendor and version independently. The original ARM64 reference stays unchanged.

## Current evidence

[CP628](../research/2026-11/checkpoint-628.md) compares the public source trees. Its 95.9% retained-line statistic covers only common x86 paths; it is not evidence of ABI or runtime compatibility. The Tahoe reference revision remains research-only; no build or boot is qualified.

Approved target layout (logical; implementation staged):

```text
XNULINUX/
    fki-ko/
    xnu-ko/
    linux/
    scripts/
    tools/
    targets/
        monterey/
        tahoe/
        future/
    xnu-patches/
    tests/
    docs/
    research/
```

The future/ entry reserves a logical place for subsequent versions, not a requirement to commit an empty directory. Start with a Monterey descriptor validated against existing artifacts, then prepare the Tahoe descriptor after CP630. Existing build and regression evidence must remain valid.

CP629 introduces the first [Monterey descriptor](../targets/monterey/target.json), validated offline on both hosts. The wider approved layout remains staged.

CP630 completes the work series. The bounded Tahoe source and toolchain preparation stage is now eligible; the implementation gate is unchanged. [CP630 report](../research/2026-11/checkpoint-630.md).

CP631 adds the [Tahoe research descriptor](../targets/tahoe/target.json); it is not a qualified build profile. [CP631 report](../research/2026-11/checkpoint-631.md).

The [distribution and staged migration plan](maintainers/distribution-plan.md) schedules the first readiness assessment at CP637. This does not change the Tahoe implementation gate or close any technical review.

CP632 adds [provisional dependency references](../targets/tahoe/dependency-references.json), with exact tag identities but no authoritative release mapping or build qualification.

CP640: 21 of 25 compared utility source units match across versions, but only three have identical directly referenced pinned paths; other generated and exported dependencies remain unqualified. [CP640](../research/2026-11/checkpoint-640.md).

CP641: [post-kernel platform reuse](post-kernel-platform.md) is a shared architectural plan; the Darwin runtime, IOKit/graphics interfaces and target build remain version-specific until compatible behavior is demonstrated.
