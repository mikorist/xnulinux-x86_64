# CP629: Monterey version-target descriptor

**Outcome: PASS (offline identity validation only).** November 27, 2026.

The first declarative Monterey profile records the source commit, Darwin major version, retained LLVM and linker identity, CP602 kernel and CP626/627 fixture hashes. The same descriptor was validated independently on diya and Ryzen against the clean pinned checkout, retained toolchain identity record and actual kernel, HFS root, loader and initrd files. Both produced the same result hash.

Nine negative controls on each host rejected wrong target, architecture, source, runtime, toolchain, artifact hash, missing artifact role, baseline checkpoint and inflated qualification. The descriptor is now in the approved target directory. This is not generic build orchestration, fresh toolchain reproduction, a new boot, or source clearance.

Next: continue independent Monterey source regeneration before Tahoe preparation.

Evidence SHA-256: `59b2ee795475fef7c941a9bdf7f05295f7d74c8dc0467464faa38652966f97e2`.
