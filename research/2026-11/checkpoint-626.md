# CP626: Ordinary Intel-model PID 1 console completion

**Outcome: PASS (scoped standalone owned fixture on diya).** November 27, 2026.

CP625 lacked the ordinary /dev mount directory. Pinned XNU mounts devfs there and propagates path lookup errors. A separate HFS copy adds the empty directory; both existing payload files remain byte-identical and read-only filesystem verification passes. The CP602 kernel and loader source are unchanged; generated ramdisk integrity metadata is refreshed.

The isolated Broadwell-v2 TCG UP run without a debugger reports HFS root mount, init load and exactly one XNUL_PID1_624_PASS at 92.08 seconds. The owned diagnostic checks PID 1, UID 0 and the Mach task call before emitting its marker. No failure marker, panic or previous devfs error appears; SMEP and SMAP enabled messages are present. The host terminates the run after the marker.

This is ordinary console evidence of completion of the owned diagnostic, not Apple launchd, independent CPL register measurement, native boot, AMD admission or hosted qualification. Ryzen replay is pending. Original CP602 and CP625 artifacts are preserved.

Next: independently reproduce the corrected fixture and ordinary Intel-model completion on Ryzen.

Archived evidence SHA-256: `c7e931ef5ac1de8c61c1688c1b04fb3e27d06d5876064237020f00b315cc75e7`.
