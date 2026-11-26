# Release checklist

Use this checklist for an actual public distribution. A documentation-only research export does not imply product readiness.

## Source and integration

- [ ] Target branch, commit and upstream ancestry reviewed.
- [ ] Independent architecture pins and generated header paths verified.
- [ ] No unrelated work, unexplained stubs or hidden test bypasses.
- [ ] All intended patches and dependency manifests available.
- [ ] Appropriate Intel and AMD tests (with explicit evidence boundaries) and shared-code ARM64 regressions recorded.

## Reproduction and qualification

- [ ] Clean build procedure tested against exact revisions.
- [ ] Link and runtime results tied to corresponding artifact hashes.
- [ ] Supported configurations listed with evidence.
- [ ] Host lifecycle, recovery, memory and CPU-state gates tested for hosted releases.
- [ ] Negative tests and unresolved defects recorded.
- [ ] End-user instructions tested for each advertised execution mode.
- [ ] No unsupported modes or architectures marketed as working.

## Licensing and distribution

- [ ] File-level provenance and third-party terms reviewed.
- [ ] Existing license texts, copyright notices and source obligations preserved.
- [ ] Proprietary Apple content excluded unless independently authorized for redistribution.
- [ ] No secrets, identifying private data or raw sensitive traces.
- [ ] Artifact checksums and corresponding source information included.

## Documentation and publication

- [ ] README, changelog, requirements, compatibility matrix and limitations agree.
- [ ] Screenshots show the actual tested configuration and are cleared for publication.
- [ ] Security-reporting route confirmed available.
- [ ] Relative links and rendered diagrams checked.
- [ ] Tag and release target reviewed by maintainer.
- [ ] Remote commit and published contents independently confirmed.

Do not mark these items complete from local notes alone. If a gate is not applicable, record why. An unresolved safety or licensing gate blocks the affected distribution.
