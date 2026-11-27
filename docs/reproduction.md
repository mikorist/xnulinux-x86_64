# Reproduction and evidence index

Independent Intel/Ryzen reproduction and native AMD KVM component qualification are recorded in the [platform evidence overview](platform-scope.md). The public reproduction bundle is under preparation. The historical observations are documented, but a clean public replay has not been performed.

| Experiment | Required evidence |
| --- | --- |
| Toolchain | Exact pins, patch provenance, compiler probe and output object |
| Strict link | Ordered input hashes, linker command, executable header and undefined-symbol result |
| Root mount | Matching kernel, loader, RAM disk, boot plan and replay assertions |
| Named file read | Matching kernel and owned fixture, lookup/read result and disk integrity comparison |

See [selected evidence manifest](../research/2026-11/evidence-manifest.md).

Do not publish raw register traces or entropy-bearing logs without review. Export minimal reviewed evidence and license-compatible reproduction scripts instead. Historical result hashes identify artifacts; they are not a replacement for the artifacts or build procedures.

A reproduction run must use its own output directory and independently check both verifier outcome and actual guest boundary.

## Latest retained reproduction evidence (CP612)

CP602: matching unstripped 1,114-input kernel, ordered input manifest, loader and fixture across Intel/Ryzen; six strict Broadwell TCG UP passes. CP605-610 verify patch lineage, dependency identity and generated-header closure. All 44 generated dependencies match recorded generation outputs; 27 inherited candidate-local headers match the direct predecessor. Clean full-source generation and public replay remain open. The [current report](../research/2026-11/hosted/commpage-reproduction-599-612.md) records candidate identifiers. The [history audit](../research/2026-11/history/engineering-history-through-612.md) distinguishes 371 verified primary evidence hashes from older entries using other formats.
