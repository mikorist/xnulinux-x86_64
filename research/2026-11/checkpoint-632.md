# CP632: Tahoe dependency references and release mapping HOLD

**Outcome: PASS for public tag identities; HOLD for authoritative release association.** November 27, 2026.

Ryzen verified 13 exact tags in official Apple source repositories. The proposed versions came from a [third-party macOS 26.5 list](https://github.com/apple-open-source/macos/blob/master/release.txt), not a verified Apple release manifest. The [official distribution repository](https://github.com/apple-oss-distributions/distribution-macOS) HEAD at 4e290a9b9d3723c65d2a606223d41eb90ecdbf99 describes macOS 26.0, with XNU gitlink f6217f891ac0bb64f3d375211650a4c1ff8ca1ea, rather than the selected 12377.121.6 reference. A request for Apple release JSON returned HTTP 404. The source grouping therefore remains provisional.

The [candidate reference manifest](../../targets/tahoe/dependency-references.json) records exact commits for XNU, AvailabilityVersions, libdispatch, bootstrap_cmds, dtrace, Libc, Libsystem, libplatform, libpthread, libmalloc, dyld, libclosure and hfs. The existing Clang, ld64, MIG and migcom files were found and hashed. IIG, docc and ctfdump were absent from PATH; their necessity and compatibility are not established by this inventory.

No dependency installation, Tahoe compilation or runtime test was performed. Monterey is unchanged. Next: confirm authoritative release mapping and independently audit the public userspace research tool readiness for CP637 under the existing distribution plan.

Primary evidence SHA-256: `b28047f5d13804141147f7ae8f327777dcd6448da9135943c27b4fde4ffca7e5`.
