# macOS 27 Golden Gate: x86_64 feasibility research

**Research only. No qualified x86_64 source pin, build, boot or userspace.**

Apple lists only Apple silicon Macs for Golden Gate. On 2026-11-27, the official XNU tag query returned no `xnu-13432*` tag. This is a dated observation, not a claim that the source will never be published. Tahoe 26.5 remains the verified later x86_64 source reference. See [Apple compatibility](https://support.apple.com/en-us/127255) and [official XNU source](https://github.com/apple-oss-distributions/xnu).

## Research questions

1. Establish the official Golden Gate source release mapping, exact version and license. Inventory retained x86_64 source and build configurations when available; no inferred source pin.
2. Compare portable kernel and userspace interfaces with Tahoe. Identify architecture-specific gaps and evaluate open-source replacement feasibility. Preserve the shared FKI and Linux ownership boundary; no host-policy changes.
3. Determine whether version-matched open Darwin libraries and tools can be compiled for x86_64. Distinguish native x86_64 binaries from ARM64-only proprietary components. A kernel port alone does not establish macOS application or desktop compatibility.
4. Evaluate separately native open x86_64 components and any lawful ARM64 application translation research. Do not assume Rosetta provides ARM64-to-x86_64 translation. Do not distribute proprietary Apple binaries.
5. Establish distinct Intel and AMD build, ABI, functional and hosted qualification gates when genuine source inputs are available. Keep the Tahoe and Monterey candidates separate; no mandatory full system emulation in the native product goal.

Golden Gate research is not a migration from Monterey or Tahoe and is not a commitment to full macOS 27 compatibility. No implementation qualification is implied. [Version targets](version-targets.md) | [Roadmap](roadmap.md)
