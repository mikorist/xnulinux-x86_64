# CP627: Cross-host ordinary Intel-model PID 1 completion

**Outcome: PASS (scoped standalone owned diagnostic on both hosts).** November 27, 2026.

The Ryzen development host independently rebuilt the loader using the transferred, SHA-256-verified CP626 HFS image and retained compiler commands. Kernel, HFS, canonical loader, initrd and test runner hashes match diya exactly.

Both isolated Broadwell-v2 TCG UP runs reached exactly one XNUL_PID1_624_PASS without a debugger: diya at 92.08 seconds and Ryzen at 91.35 seconds. Neither run reported a failure marker, panic or previous devfs mount error. SMEP and SMAP enabled messages were present.

The HFS image was transferred rather than independently regenerated on Ryzen. This is cross-host Intel-model console completion of the owned PID 1 diagnostic, not Apple launchd, AMD-model admission, physical execution or hosted qualification.

Next: retain the cross-host Intel baseline and review remaining AMD qualification requirements and independent source/build work.

Archived evidence SHA-256: `8fff2d0702ab8fc1b3d12f9f0219799ec8db763b28af6c79328596a5b1b0e818`.
