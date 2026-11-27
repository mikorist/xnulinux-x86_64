# AMD standalone startup: from early CPU state to machine initialization

November 26-27, 2026. Selected milestones from checkpoints 498-555. Monterey XNU 8020.140.41, source pin `27b03b360a988dfd3dfdf34262bb0042026747cc`.

This follows the [CP478-497 report](topology-state-and-reproducibility.md). The Intel and Ryzen development hosts run independent builds and disposable single-vCPU EPYC Milan TCG guests. This is model-based standalone XNU execution, not physical or hosted AMD XNU execution.

| Checkpoints | Observed progress | Limits |
| --- | --- | --- |
| 498-500 | Original FPU/AVX save and restore helpers and early measured TSC/nanotime initialization executed; Intel PID 1 regression passed | No thread context-switch or timer delivery qualification |
| 501-519 | Memory-type and machine-check lifecycle prerequisites examined; early initialization ordering and metadata dependencies resolved incrementally | No general hardware qualification |
| 520-522 | Scoped virtual machine-check handling and separate normal MCA startup continuation observed | No physical machine-check or native SMCA handling qualification |
| 523-528 | Native Ryzen Linux inventory and separate host-owned SMCA visibility model | Inventory and model only; not XNU hardware handling |
| 529-536 | Actual boot CPU initialization, pmap bootstrap and initial VM initialization returned on Milan | Global CPU admission and full memory lifecycle remain open |
| 537-545 | Actual pmap and zone initialization; VM memory bootstrap returned | No full VM runtime qualification |
| 546-555 | Credential initialization, OSLOG setup, MAC policy initialization and mapping allocation completed; machine_init reached | No complete Mach IPC runtime, admission or hosted boot |

The native Linux Ryzen 7 5700X inventory at CP525 is a separate physical observation: all 16 logical CPUs were enumerated; 448 Linux sysfs bank attributes were examined, 114 readable and 334 reporting ENODEV. These observations do not establish a physical bank count or a functioning XNU SMCA implementation. The later visibility model is a standalone software test.

The candidate remained deliberately pre-admission. Independent strict links reached 1,114 inputs with zero undefined symbols. Intel reference replays were maintained separately. Successful diagnostic termination is not proof of a completed boot.

Selected retained evidence SHA256 (private artifacts, not a downloadable replay package):

| Checkpoint | Evidence digest |
| --- | --- |
| 499 | `d3d43f88c7aeffadcb9cdf652d083fd2c1e747d8337015034f81c1c4a3ddf289` |
| 500 | `540b9033b88a6e63259c7654b887e2a481b4e52e4f7a373ca766a35add2887ba` |
| 521 | `263cb8b661f1be824f4e5293a3d3d1842e9fffe4d6c4c17a30f308621ada0707` |
| 525 | `643861432838f75b61ac754246f6e0295c62c7be06a35208c4bb0da142051c3d` |
| 536 | `c0d85dcd33e0582afa5cae2db552d32cb937a772b93912adc9e8ad253d96c543` |
| 545 | `ab2719634324c182eb22df3b150a9e0bd6efa0fa29ff355b4578e93b226a7dce` |
| 555 | `568c40ce01445b2de18f8f4b884f64a86376129bba8670ed4183895103ca781e` |

The next [machine lifecycle report](amd-machine-lifecycle-556-598.md) describes later progress and Intel regression corrections. This is a selective documentation update, not a complete source publication or release.
