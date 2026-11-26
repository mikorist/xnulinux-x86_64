# 8. Historical planning estimate at the 813-input boundary

**Date:** 2026-11-25  
**Source checkpoint:** 29 (R0008)  
**Status:** Historical estimate, not a measured result or current schedule.

At this point 813 validated objects linked into a relocatable Mach-O with 969 unresolved symbols. The hibernation symbol had been resolved, but DriverKit generation and most IOKit C++ work remained open. No final executable, hosted module, runtime or boot had been produced.

The historical estimate assumed one intensive full-time equivalent and an unchanged environment:

| Work package | Original estimate |
| --- | --- |
| Source-backed symbol/provider map | 2–5 focused working days |
| Missing component and IIG/C++ providers | 2–5 weeks |
| Provider closure and FKI boundary | 2–4 weeks after stabilization |
| First boot/debug iterations | 1–3 weeks |

The original overall estimate was roughly 6–12 weeks to a serious hosted proof-of-concept attempt, or 3–6 months or more of spare-time work. These were tentative forecasts, not elapsed durations, promises or updated estimates. Subsequent research changed the standalone evidence substantially, but that does not establish hosted completion.

The key insight was that 969 undefined symbols did not represent 969 independent implementations: one real provider might resolve many. Generated interfaces, component libraries and linker-owned names needed evidence before classification. Host imports required a separately defined FKI contract.

The greatest uncertainty was the Monterey IIG/SDK and generated ABI, followed by toolchain behavior, type metadata, final kernel layout and runtime debugging. The immediate plan was to inventory all targets and classify every unresolved reference before revising the estimate. Chapter 9 describes that audit.
