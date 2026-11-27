# Contributing to xnulinux x86_64

Thank you for contributing to XNU for the PC, the x86_64 project derived from [xnulinux](https://github.com/AFK-surf/xnulinux). Development proceeds in parallel on Intel and AMD Ryzen with one shared x86_64 implementation. Contributions target a complete PC-oriented XNU/Darwin compatibility platform, with qualification scoped to each layer. See [platform scope](docs/platform-scope.md). See [project philosophy](docs/project-philosophy.md).

This is experimental kernel research. Contributions are welcome in the form of source changes, reproducible tests, technical documentation, dependency audits and reports of failed approaches. A build that fails for a well-understood reason can be a valuable contribution.

> [!IMPORTANT]
> Standalone XNU experiments and Linux-hosted XNU are separate qualification paths. State which path you tested. Do not load unqualified experimental kernel modules on a production host.

## Start here

Mac users, Hackintosh users, Linux users and curious readers are welcome. You do not need a kernel patch to contribute. A precise question or a well-documented failure is useful. If you are new to the project, [start here](docs/getting-started.md).

Read the [architecture](docs/architecture.md), [roadmap](docs/roadmap.md), [qualification matrix](docs/qualification-matrix.md) and [testing policy](docs/testing.md). For source provenance and licensing, consult [dependencies](docs/dependencies.md) and the existing upstream license notices.

## Repository workflow

The shared x86_64 integration branch is `x86_64-port`. `main` presents reviewed x86_64 development; `arm64-reference` preserves the original ARM64 tree. A contribution should be scoped to one logical subject.

Use a separate branch and working tree for each concurrent task. Do not modify a working directory that another contributor or agent is using. Keep unfinished experiments outside the integration branch.

Before preparing a change:

```sh
git status --short --branch
git diff --check
git diff
git diff --cached
```

Review the current remote state before integration. Never force-push the reference or integration branch. Preserve upstream history, attribution and independent source pins.

## Source and build rules

- Keep XNU version targets and ARM64 configurations, generated headers and patch series separate; Intel and AMD share the appropriate x86_64 target baseline.
- Preserve pinned source checkouts; record necessary source changes as reviewable patches.
- Avoid placeholder implementations presented as real providers, fake SDK headers and silent test bypasses.
- Preserve relevant diagnostic failures and document the reason for changing approach.
- Include the exact source revision and build configuration with a technical claim.

## Tests and review

Include commands, compiler/linker versions, execution environment, exit status, observed boundary and relevant artifact checksums. State which tests were not run and why. A verifier exit code alone is not evidence of a successful boot.

A change affecting common code needs an appropriate ARM64 regression assessment in addition to relevant Intel and AMD regressions. The maintainer reviews the change, test evidence and license boundary before integration. After integration, rerun relevant checks on the combined revision.

## AI-assisted contributions

AI assistance is permitted. Describe its role when relevant, review generated changes, and provide actual test evidence. Do not submit invented test results, fabricated source references or unreviewed generated code. See [AI methodology](AI-METHODOLOGY.md).

## Commits and pull requests

Write public text and commit messages in English. Use concise subjects such as:

- `docs: explain standalone root mount evidence`
- `build: add x86_64 configuration`
- `test: document a reproduced regression`

Stage specific reviewed paths, not the entire research archive. Keep unrelated changes in separate commits. Open an internal pull request for review; an upstream pull request is a separate decision.

## Licensing and privacy

Keep original copyright and SPDX notices. Respect the existing APSL/GPL separation and third-party terms. Do not upload proprietary macOS components, private SDKs, credentials, identifying host data, raw entropy or large build trees. When rights are unclear, hold the affected material for review.

For a security-sensitive report, follow [SECURITY.md](SECURITY.md) rather than posting sensitive details in a public issue.

## Communication

Be concrete and respectful. Disagree with an implementation or conclusion using reproducible evidence. Do not make personal attacks or misrepresent other contributors' results.

## Parallel Intel and AMD development

Use one shared x86_64 source tree and FKI ABI. Ryzen and Intel work may proceed in separate workspaces, with one integration history and a common checkpoint review cycle. Identify CPU, accelerator, Linux kernel, compiler, input hashes and evidence scope in contributions. Do not equate AMD-model TCG or nested WSL2 virtualization with bare-metal AMD Linux qualification.

## A small rule about tone

Be direct, be curious, and keep the jokes aimed at the technology rather than the people using it. A patch may be wrong; the person who sent it is welcome to try again. Facts first, dry humor second. The compiler is already doing enough shouting.
