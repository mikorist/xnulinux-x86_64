# Dual-host batch build verification

## Purpose

XNULINUX uses a local batch regeneration workflow to reduce repeated manual build operations. The same reviewed candidate set is compiled independently on Intel and AMD development hosts, using a pinned XNU source tree and qualified historical build inputs. The workflow is designed for reproducibility research, not for installing or running XNU on a host.

## Workflow

1. Inventory historical link inputs and identify original-source recipes with verified object identity and source provenance.
2. Freeze a common candidate plan and independently validate each host's inputs.
3. Run separate workers in the existing isolated build environments. Retain successful and failed attempts, verify generated dependencies and compare object hashes and ordered dependency closures.
4. Persist local progress atomically and prevent duplicate workers. A local coordinator can reconnect after a transport interruption; already verified results are reused after integrity checks.
5. When each queue is exhausted, relink the complete reference input set and compare the resulting image against the established reference hash.
6. The central integrator compares the two independent results and admits only mutually verified objects into the project checkpoint journal.

The current laboratory implementation consists of an inventory, a Python worker, a local two-host coordinator, status and result manifests, and optional desktop notifications. The build itself does not require an AI session. A notification indicates queue completion, not acceptance of every candidate.

## Recorded evidence

CP791 recorded 263 newly accepted dual-host object regenerations from a 303-candidate batch. Intel matched 263 and AMD matched 264 locally; 39 candidates were held on both and one was held on Intel only. Both complete retained-input relinks matched CP602. The accepted total increased from 192 to 455 of 1,114 inputs.

CP792 and CP793 subsequently demonstrated exact configuration-header regeneration and source staging for additional platform and OSFMK units. CP793 recorded 467 regenerated and 647 retained inputs. CP794 accepted 119 of 209 further OSFMK candidates, with 90 held on both hosts. CP795 resolved one shared generated dependency and accepted thirteen more units. At CP795 the accounting was 599 regenerated and 515 retained inputs. CP806 completed all 209 Batch 02 candidates. At CP815 the project had accepted 692 regenerated inputs and retained 422. CP824 completed the residual Batch 01 recipe group; CP835 reaches 764 regenerated and 350 retained inputs, including twelve exact historical UIO compatibility objects. CP855 reaches 839 regenerated and 275 retained inputs, including all 64 original CP811 C++ candidates. CP874-875 accept the first two bounded Batch 03 queues (8 and 15 objects) with exact complete retained-link identity. CP875 reaches 920 regenerated and 194 retained inputs. Terminal restart and wrong-plan-hash rejection were checked in the initial queue; interrupted resume and duplicate-worker rejection remain unqualified. Portable tool source remains HOLD.

## Qualification boundary

A local object match is not dual-host acceptance. A byte-identical retained-input relink does not prove a complete clean-source build, runtime correctness, physical hosted operation, license clearance or release readiness. Failed recipes and unresolved dependencies remain held. The worker does not load modules, execute a kernel, modify host protections, advance checkpoint numbers, or publish to Git.

## Public tool packaging

The current lab implementation is tied to historical input manifests, specific qualified toolchains and a private workspace layout. It is not yet a portable public build utility. A reviewed public package is planned under `tools/batch-runner/`, subject to source provenance, license clearance, explicit input validation, and independent build/negative tests on both hosts.

Use an example configuration with placeholders and keep deployment settings local. Do not distribute authentication material, host identifiers, private paths, transport configuration, raw logs, private plans, workspace snapshots, generated kernel binaries or private dependency manifests. Publish a documented example input set and a reproducible test fixture instead. Public documentation and tool code have separate acceptance gates; no release is implied by this description.
