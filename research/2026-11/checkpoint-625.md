# CP625: Ordinary Intel root mount and init load attempt

**Outcome: PASS (ordinary root mount reported); PID 1 completion HOLD.** November 27, 2026.

A separate boot fixture uses the CP624 console-reporting HFS image and the unchanged CP602 kernel. The existing loader source and compiler commands remain identical; only generated ramdisk integrity metadata and the ramdisk contents change. The original CP602 artifacts remain intact.

A Broadwell-v2 TCG UP run on diya without a debugger resumed serial output at 61.8 seconds. At 92.08 seconds, the console reported the md0 root device, mounted XNULROOT and an attempt to load the owned init program at the standard init path. It also reported `devfs_kernel_mount: kernel_mount failed: 2`. No diagnostic pass/fail marker or panic appeared within the 100-second observation budget.

The devfs error is an observed failure, not yet an established cause of missing completion output. Successful exec, PID 1 execution and ordinary console completion remain unverified. Ryzen runtime, AMD admission, native and hosted qualification remain open.

Next: review the devfs mount prerequisite and ordinary console availability without changing kernel protection or admission requirements.

Archived evidence SHA-256: `5eb17515f2576511d88bd6c0f9b94298ee478765d8d7e106986139e56f0d051a`.
