# CP639: Additional Monterey source regeneration and exact relink

**Outcome: scoped build and relink PASS.** November 27, 2026.

Six additional libkern units (version parsing, four address conversions and scanf) were independently compiled on both development hosts using the retained historical recipes with redirected output paths. Source bytes match the clean Monterey pin. All twelve compiler invocations succeeded and all objects match CP602.

Each complete 1,114-input link now includes 28 regenerated objects (CP616, CP630 and CP639) and 1,086 retained objects. Both complete images match CP602 exactly, SHA-256 `49d24b6512f178a5d9b19dfd7f10946f936f78c7725e1a7e6e2f8089055720b2`. Ordered input manifests and link results match between hosts. Retained generated headers and toolchains remain dependencies. No new boot, clean-source build or hosted/AMD qualification.

Primary evidence SHA-256: `0a4057d3c375e0c206982710da66d2507816e40631b600be8cbfde58771cbc50`.
