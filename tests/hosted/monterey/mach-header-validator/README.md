# Intel Mach-O structural validator

An independent, bounded metadata check retained from Monterey checkpoint 259 and unchanged in the integrated checkpoint 317 candidate. The original private test used a 4,160-byte header extracted from the pinned open-source research kernel and passed 23 groups, including every shorter prefix. The original result-manifest SHA-256 is `089c4a559fc5f62edfe4279eb36cc90abc966f2bc4c5f7c747ab07e98cbf1630`.

This public test uses independently constructed synthetic metadata, not the original kernel image or any proprietary input. Run from the repository root:

```sh
CC=gcc sh tests/hosted/monterey/mach-header-validator/run.sh
```

The runner builds only a userspace test in a temporary directory with C11 warnings-as-errors and UBSan. On the physical Intel development host, GCC 14.2.0 reported **229 checks, 0 failures**. The exact validator SHA-256 is `ff7b63ef6ecd4613577bb36c216394278783b098d6d9290a060d90f3832c6474`.

The gate checks a private little-endian Intel MH_EXECUTE header snapshot, command bounds, segment/section extents and UUID command size. It does not authenticate a Mach-O image, validate arbitrary load command payloads, map executable pages or implement a boot loader. This is a component regression, not a hosted XNU boot. MIT-licensed source; see LICENSE.

New to the project? See [Getting started](../../../../docs/getting-started.md). This is a normal userspace test; it is not an installation step.

Build requirements: POSIX shell, mktemp, a C11 compiler, standard C library development files and the matching UBSan runtime. GCC 14.2 and 15.2 passed on the two Linux development hosts. Clang 21.1.8 passed on Ryzen; Debian Clang 19.1.7 could not link because its UBSan standalone archive was missing. Install the appropriate compiler runtime through your normal distribution package procedure; do not disable UBSan to obtain a PASS. See [CP633](../../../../research/2026-11/checkpoint-633.md).
