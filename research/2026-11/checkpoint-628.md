# CP628: Monterey and Tahoe source comparison

**Outcome: PASS (source comparison only).** November 27, 2026.

The clean Monterey source at 27b03b360a988dfd3dfdf34262bb0042026747cc was compared on Ryzen with the Apple public Tahoe reference xnu-12377.121.6 at ac9718fb1af618d5ce8678d0dc6e8a58f252216f.

| Scope | Monterey files | Tahoe files | Common paths | Identical blobs |
| --- | ---: | ---: | ---: | ---: |
| All tracked blobs | 4851 | 6113 | 4596 | 2241 |
| osfmk/i386 | 140 | 141 | 138 | 80 |
| osfmk/x86_64 | 30 | 31 | 27 | 18 |
| osfmk/mach | 175 | 182 | 168 | 86 |
| bsd | 1616 | 1708 | 1555 | 723 |
| iokit | 284 | 304 | 282 | 148 |
| libkern | 287 | 304 | 286 | 173 |

Across the 165 common x86 paths, the default Git diff retains 62,672 of 65,324 Monterey lines (95.9%). The comparison excludes files without common paths from the line statistic. It establishes neither semantic equivalence nor build, ABI or runtime compatibility. Tahoe is a research reference, not yet a qualified target pin.

The owner adopts one XNULINUX with multiple version targets: shared platform infrastructure and compatible product layers, separately versioned XNU and Darwin inputs and qualification. Monterey remains the active implementation baseline. Tahoe source preparation may proceed without replacing it. Both targets are intended to support headless, desktop and seamless modes after their respective qualification. ARM64 reference unchanged.

Next: resume Monterey AMD qualification and independent source/build work; retain Tahoe inventory for subsequent preparation.

Archived evidence SHA-256: `5e694b81f914cb66b833691e0649e95acf418aeade0b6c2eae21f1ecf028baff`.
