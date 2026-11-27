# Project navigation and responsibilities

Start with the [root README](../README.md) and [project state manifest](../PROJECT-STATE.json) for the current checkpoint, qualified scope, blockers and next step. The [qualification matrix](qualification-matrix.md) separates evidence classes; the [roadmap](roadmap.md) gives the acceptance order. The [research journal](../research/README.md) preserves history. The [architecture](architecture.md) describes the intended design, and the [source map](source-map.md) describes the pinned upstream tree.

## Repository map

| Path | Purpose |
| --- | --- |
| fki-ko/ | Linux host interface and retained provider sources |
| xnu-ko/ | XNU loader and adapter sources |
| xnu-patches/ | Version-specific patch and reference material |
| linux/ | Linux-side interface material |
| scripts/, tools/ | Build and research tooling |
| tests/ | Reviewed fixtures and regression tests |
| gpu/, kexts/ | Retained components for later qualification |
| docs/ | Current design, build, testing and maintenance reference |
| research/ | Chronological and thematic experimental reports |
| CHANGELOG.md | Reviewed changes and research milestones |
| LICENSE, LICENSES/ | Preserved licensing and attribution |

Directory presence does not establish runtime support. Some material is retained for review; no supported x86_64 release is available.

## Workflow and ownership

1. Development agents record significant results with evidence, test scope and unresolved questions. Intel and AMD share the same source baseline; compute and regression lanes remain distinct.
2. Documentation maintainers review each checkpoint in chronological order, including failed and incomplete outcomes. They reconcile the root README, qualification matrix, roadmap and relevant indexes with verified results.
3. The central integrator reviews source provenance, licensing, build and regression gates and publishes explicit reviewed changes. Documentation can be published independently of code qualification.
4. The next agent verifies the current state and continues the first unfinished eligible task.

Public main and x86_64-port normally contain the same reviewed increments. The arm64-reference branch preserves the original ARM64 implementation. Experimental candidates remain separate from the qualified baseline. Ten-checkpoint development series and twenty-checkpoint technical reviews do not delay publication of reviewed outcomes.

The technical sequence is standalone reference qualification, shared hosted machine layer, hosted Darwin userspace, headless, desktop and seamless modes, with reproducibility and source review throughout. See the roadmap for the actual acceptance gates. The current standalone AMD clock lifecycle and full hosted boot remain open.

Version targets share one repository and central chronology. Monterey is the active baseline; Tahoe source preparation is separate. Track evidence and qualification per version and CPU vendor. See [architecture](architecture.md) and [CP628 comparison](../research/2026-11/checkpoint-628.md).

For the version-target extension principle, logical layout and Tahoe entry gates, see [version-target entry plan](version-targets.md).
