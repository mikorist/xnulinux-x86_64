# Linux host compatibility: representative 6.x runtime matrix

**Date:** 2026-11-25  
**Source checkpoints:** 192–194, 196, 199–200.  
**Scope:** Actual per-kernel module builds and isolated Linux guest tests, not complete hosted XNU support.

The maintainer requires both older and current Linux support. Checkpoint 192 built unchanged hostcall sources against both installed Liquorix 7.3.5-1 and 7.3.5-2 headers. The older patch-level build was compile-only at that checkpoint. The current version had separate guest runtime evidence.

## Representative kernel versions

All listed 6.x versions were tested in the recorded matrix, one distribution kernel per minor generation. Package authenticity and checksums were verified against signed distribution indexes; no packages were installed on the live host.

| Minor | Actual kernel release |
| --- | --- |
| 6.0 | `6.0.0-4-amd64` |
| 6.1 | `6.1.0-50-amd64` |
| 6.2 | `6.2.0-39-generic` |
| 6.3 | `6.3.0-1-amd64` |
| 6.4 | `6.4.0-2-amd64` |
| 6.5 | `6.5.0-5-amd64` |
| 6.6 | `6.6.9-amd64` |
| 6.7 | `6.7.12-amd64` |
| 6.8 | `6.8.12-amd64` |
| 6.9 | `6.9.12-amd64` |
| 6.10 | `6.10.6-amd64` |
| 6.11 | `6.11.5-amd64` |
| 6.12 | `6.12.117+deb13-amd64` |
| 6.13 | `6.13-amd64` |
| 6.14 | `6.14.10-2-liquorix-amd64` |
| 6.15 | `6.15.11-1-liquorix-amd64` |
| 6.16 | `6.16.12-1-liquorix-amd64` |
| 6.17 | `6.17.13-1-liquorix-amd64` |
| 6.18 | `6.18.16-2-liquorix-amd64` |
| 6.19 | `6.19.14-2-liquorix-amd64` |

## Test suites

| Checkpoint | Suite | Boot results | Observations |
| --- | --- | --- | --- |
| 193 | Hostcall transport | 20/20 | 1280 sessions, 2560 calls, 11600 assertions |
| 194 | Cooperative SMP entry | 20/20 | 81920 entries and nofault rejections each, 2560 APIC NMI sends, 1954 active-window callbacks |
| 196 | Static ring-0 adapter | 22/22 including two current Liquorix boots | 6144 entries, 12288 calls, 240 negative cases |
| 199 | APSL PE components | 20/20 | 5120 sessions, 10240 calls, 92160 checks |
| 200 | Split FKI/PE memory service | 22/22 including two current Liquorix boots | 5632 sessions, 118272 integration checks, 84480 memory checks |

These are different suites and scopes. Do not interpret their totals as a complete XNU kernel validation.

The hostcall sources were unchanged across 6.x. Header-wrapper path relocation, missing pahole and a 6.13 build-output/include-path problem required local build-environment corrections; failed attempts were retained. Compiler-version warnings and package-specific signing characteristics were recorded without disabling security policy.

The cooperative suite generated an APIC wrapper from actual exported-symbol availability: the older exported apic interface on tested 6.0–6.5 and exported static-call interface on tested 6.6–6.19. No hidden symbol lookup was used. This research-only NMI path requires further ownership review.

## Matrix identities

| File | SHA-256 |
| --- | --- |
| HOSTCALL-MATRIX.json | `9bf4b247e4776d2bba03a70536d2b52e87ef462ed7133342728f1a136115a88e` |
| COOP-MATRIX.json | `f5582be368dd333291b2007453f664e6d5d029f74d021a86e92c6b5a0dce4c5a` |
| Ring-0 matrix | `f82821980a323eee3505c52ec4b5a089deb50ccc98cf812cf8984a7ad9ca7f25` |
| PE-MATRIX.json | `a1293e31502f5c65c66c7426ec4451b8a358a0bbd9e4a9cdef67bb6bb9884125` |

No claim is made for every point release, configuration, Proxmox-specific kernel, signing-enforced installation or physical runtime on all versions. EOL versions are regression fixtures, not deployment recommendations. Modules must be built for the target kernel's actual headers and symbol interface. No bundled set of twenty precompiled modules is required by this research plan.

## Subsequent memory and object regression (checkpoints 203–214)

Each final series below contains the twenty representative 6.x distribution kernels and two current Liquorix cold boots. The 205 warning-affected series is not counted as a clean final suite; its correction is recorded in [the SMP report](fki-smp-and-warning-regression.md).

| Checkpoint | Final suite | Final boots | Key metric (guest aggregate) |
| --- | --- | --- | --- |
| 203 | VM descriptor ownership | 22/22 | 3041280 memory checks |
| 204 | Page zero/copy | 22/22 | 6037504 memory checks |
| 206 | Corrected SMP ownership | 22/22 | 87296 SMP checks |
| 207 | Mapping aliases | 22/22 | 52096 mapping checks |
| 209 | VM object subset | 22/22 | 61952 checks |
| 211 | Resident hash subset | 22/22 | 118272 checks |
| 212 | Mapping lifetime races | 22/22 | 84480 race checks |
| 214 | Empty-object final reference | 22/22 | 137984 checks |

This adds 176 final guest boot passes to the original five-suite total of 104. These 280 boot passes are scoped tests, not 280 independent XNU boots or a sum of unique assertions. Some suites intentionally repeat earlier checks. The stricter no-new-warning runtime gate begins with corrected checkpoint 206; older recorded passes use the contemporaneous gate. Separate physical tests are recorded in the corresponding reports, and are not included in this total.

## Later scope (217–317)

The ten additional historical final series (218, 221, 224, 225, 227, 229, 233, 234, 237, 239) comprise one 22-boot and nine 21-boot series. Independent re-verification of the same boots is not a new test. See [process mapping](owned-process-memory.md) and [inactive root](inactive-root-lifecycle.md). Checkpoint 240 changed ongoing development to two exact kernel releases, 7.3.5-2-liquorix-amd64 and 6.19.14-2-liquorix-amd64. The later integrated two-target milestones (253, 261, 267, 287, 297, 307, 309, 317) are scoped guest tests and do not imply a full XNU boot or fresh qualification of every 6.x release.
