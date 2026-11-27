# Commpage initialization, regressions and build provenance

November 27, 2026. Selected milestones from checkpoints 599-612. Monterey XNU 8020.140.41, source pin `27b03b360a988dfd3dfdf34262bb0042026747cc`.

See the [previous machine lifecycle report](amd-machine-lifecycle-556-598.md). The retained CP602 candidate is an experimental standalone image; the complete integrated source has not been cleared for public distribution.

## Initialization and regression evidence

Earlier Intel-model regressions exhibited an intermittent commpage initialization failure. CP599-601 retained failed and recovered observations, including observer errors. CP602 evaluated a lifecycle correction that initializes the allocation before publication using the existing VM policy. Both independently linked images matched; exactly one of the 1,114 ordered object inputs changed relative to CP593. The original VM policy was retained.

CP602-604 yielded six complete strict Broadwell-v2 TCG UP passes across Intel and Ryzen development hosts, including baseline observer replays and successful original userspace mapping API calls. The gate confirmed the HFS file fixture, ENOENT, unchanged disk, Darwin test PID 1 in user mode, and Mach/BSD call returns. The mapping API reported data R/R and text RX/RX. API results do not establish all effective hardware permissions or universal commpage stability.

The same CP602 image was replayed under EPYC Milan TCG on both hosts. Both reached the previous RTC/lock-timeout observation boundary. This is not an AMD PID 1 result.

## Build provenance

| Checkpoints | Result |
| --- | --- |
| 605 | Two retained commpage patches applied to pinned Apple source with zero fuzz and unchanged APSL header. Both hosts verified the same ordered 1,114-object manifest and fixture hashes. |
| 606-607 | Three compiler dependency lists inspected: 366, 366 and 257 entries; 402 unique paths. 328 matched tracked upstream content; 44 were generated build dependencies; 30 were candidate-local files. |
| 608-609 | All 42 configuration headers and both MIG headers matched independently generated outputs. Fresh MIG generation also succeeded on the Intel host. |
| 610 | All 27 candidate-local header dependencies matched the direct predecessor; three candidate C units remain tracked separately. |
| 611-612 | Original timeout and fixed-point conversion arithmetic tested in isolated userspace fixtures: 3,078 and 10,072 cases per host respectively, all passed. These are arithmetic tests, not a clock lifecycle or boot result. |

Matching retained dependency bytes is not proof of full independent source regeneration, original authorship or complete license clearance.

## Exact retained candidate identifiers

| Artifact | SHA256 |
| --- | --- |
| CP602 unstripped kernel | `49d24b6512f178a5d9b19dfd7f10946f936f78c7725e1a7e6e2f8089055720b2` |
| Initrd fixture | `f2fa440f3904c28f462bfbf41b2225510cb174a04016f6a629f3a8e9186b9a0f` |
| Canonical loader | `bacc93be2c0f328138ba543b8830185ed191f2c8fb6cdad35b54f80ac45aa7c7` |
| CP604 mapping contract evidence | `40b25b7a7ee4d4da32edc1d3c972be3135c710c1d4a5f4f29c83207d5a553050` |
| CP605 provenance evidence | `c14b0fa8daf597a9d7d9d06def8e572121d1073f4a169a358e343a7d0b9d337d` |
| CP607 dependency classification | `6f38a753b3f8411e22e59919a275530ee6300f6e020bf1cf92a4ea4469014cd0` |
| CP612 arithmetic evidence | `919ad186cf851111b183e60f23c7e2c81622a457c0bfe090fe61a5f178660d33` |

These identifiers describe locally retained artifacts, not downloads in this repository.

## Remaining work

- Complete AMD clock lifecycle observation, CPU admission and full standalone regression.
- Qualify effective mapping permissions, timer delivery, SMP and physical/hosted ownership separately.
- Continue independent source regeneration, review the remaining candidate-local provenance and license boundaries, and prepare a publicly reproducible integration.

All 115 checkpoint evidence files from CP498-612 were checked against their recorded hashes during the documentation review. This selective status update does not close the pending regular review, promote the individual-record ledger or constitute full source publication. No release or complete hosted XNU boot is claimed.
