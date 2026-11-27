# Tests

There are two reviewed, independently runnable public userspace test suites. Neither boots XNU, installs a driver or requires an Apple system image.

## Start with the public tests

Run from a local checkout on a suitable Linux development system, as an ordinary user. See [getting started](../docs/getting-started.md#what-you-can-run-today) for the checkout and prerequisites.

- [Mach-O structural validator](hosted/monterey/mach-header-validator/README.md): synthetic executable metadata, C11 and UBSan.
- [Replay evidence verifier](hosted/monterey/replay-verifier/README.md): synthetic evidence-handling tests, Python 3 standard library.

Both have reviewed cross-host test evidence. The private source-only archive reproduction and remaining attribution/distribution holds are documented in [CP636](../research/2026-11/checkpoint-636.md). This is not an available binary package. See the [distribution plan](../docs/maintainers/distribution-plan.md) for release gates.

## Other test files

The inherited host and graphics-related test material is retained for investigation, not a supported test suite for every x86_64 machine. Do not assume that a script is qualified merely because it is tracked. Consult its documented scope and the [testing policy](../docs/testing.md) before use.

## Interpreting results

A passing component test establishes only its documented acceptance criteria. A guest test, a physical host component test and a complete hosted boot are different evidence classes. See [qualification matrix](../docs/qualification-matrix.md) and [evidence index](../docs/evidence/README.md).

[Home](../README.md) · [Report a problem](../CONTRIBUTING.md) · [Research](../research/README.md)
