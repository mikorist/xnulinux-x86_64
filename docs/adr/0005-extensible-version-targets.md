# ADR 0005: One platform, extensible version targets

Date: 2026-11-27. Status: Accepted architecture direction; staged implementation.

## Decision

Retain one XNULINUX repository and a common Intel/AMD platform. Monterey 8020.140.41 remains the active baseline. Tahoe 12377 is the next planned version target; future targets extend the same infrastructure. Share versioned FKI contracts, compatible Linux backends, build/test orchestration and application integration where evidence supports reuse. Keep each target's source pin, configuration, generated headers, patches, artifacts and Darwin runtime separate.

Use small declarative descriptors under targets/ rather than duplicating complete source trees. The approved layout is introduced incrementally without wholesale relocation.

## Entry and qualification

CP628 is a source comparison, not ABI, build or boot proof. CP629 establishes offline identity of the Monterey descriptor. Tahoe preparation may proceed after the current series; Tahoe implementation retains the stable physical Linux-hosted Monterey Intel gate. Neither a completed Monterey desktop nor full AMD boot is an additional prerequisite. AMD development continues in parallel. Each version and vendor requires separate qualification.

The existing ARM64 reference, licensing and host-ownership boundaries remain unchanged. See [version targets](../version-targets.md) and [CP629](../../research/2026-11/checkpoint-629.md).
