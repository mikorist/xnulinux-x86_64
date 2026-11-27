# CP630: Monterey utility source regeneration and complete relink

**Outcome: PASS (scoped source regeneration and retained-input relink).** November 27, 2026.

On diya and Ryzen, independently compile 19 ordinary BSD/libkern utility and compression inputs using the original retained compiler recipes, changing only output and dependency destinations. Verify each source unit against the clean Monterey source pin. All 38 compiler invocations exit successfully; all regenerated objects match the corresponding CP602 input hashes. The two result manifests match.

Each host then independently relinks the complete 1,114-input candidate using 19 CP630 objects, three previously regenerated CP616 objects and 1,092 retained objects. Both links exit successfully; both entire unstripped kernel images match CP602 exactly, as do the ordered input and result manifests.

- Kernel SHA-256: `49d24b6512f178a5d9b19dfd7f10946f936f78c7725e1a7e6e2f8089055720b2`.
- Primary evidence SHA-256: `4ebfd8d3f574911c4d0994ffd7ac84972de7eed1fa5bb8c868eaa85a33d26420`.

Retained generated headers and toolchains remain dependencies. This is not a clean full-source build, a fresh toolchain build, source/license clearance, or new runtime qualification.

## Series CP621-630 completed

The series corrected ordinary serial observation, found the missing /dev directory, confirmed ordinary owned PID 1 console completion under Broadwell TCG on both hosts, compared the Monterey and Tahoe sources, and validated the first Monterey version descriptor. AMD admission, native/hosted execution and clean-source reproduction remain open. The technical review window beginning at CP498 is not closed by publication.

Next: begin bounded Tahoe source, toolchain and version-target preparation on Ryzen, keeping Monterey the active implementation baseline. The approved Tahoe implementation gate remains unchanged.
