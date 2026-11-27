# Versioning and milestones

Keep target identity and the following identifiers independent:

| Identifier | Meaning |
| --- | --- |
| Version target | Monterey, Tahoe or a future target; independent qualification |
| XNU source version and commit | Exact Apple kernel baseline |
| Experimental image number | Local diagnostic lineage |
| FKI ABI version | Host/guest contract compatibility |
| Product release version | Reviewed distributable project revision |

A source pin or local image number is not a product release number. XNU 8020.140.41 and the upstream ARM64 pin remain independent.

## Proposed convention

Use annotated research milestone tags only after the maintainer verifies a meaningful, reproducible result at a public commit. A possible naming scheme is `research/x86_64/<milestone>`. Example names are illustrative; no tag is created by this document.

For a future distributable x86_64 product, consider a separate pre-1.0 version series such as `v0.x.y`, with prerelease qualifiers where necessary. Adopt the actual numbering convention only after maintainer review and compatibility criteria are defined.

Breaking FKI contract changes require an explicit ABI revision and compatible loader/runtime selection. Do not infer ABI compatibility merely from matching product versions.

A release note should identify the exact commit, source pins, supported host and CPU combinations, execution modes, verified checksums, unresolved limitations and recovery instructions.

The approved target layout uses version-specific descriptors and artifacts. A new target does not imply a new product repository or ABI compatibility. See [version targets](../version-targets.md).

Research prereleases use target-specific milestone tags only after the applicable [distribution gates](distribution-plan.md) pass. Keep generated binary assets in GitHub Releases, not the tracked source tree. No tag or release is created by this decision.
