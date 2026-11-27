# CP621: Observer-free standalone smoke test

**Outcome: HOLD (insufficient completion evidence).** November 27, 2026.

The unchanged CP602 canonical loader and initrd were launched under QEMU TCG UP with Broadwell-v2 and EPYC-Milan-v1 models on both development hosts, without a debugger. All four runs reached the loader metadata-ready marker, then reached the eight-second observation timeout without an independent completion marker.

The test did not establish a kernel panic, a hang, the cause of the timeout, completion of clock initialization, or PID 1 execution. The six previous strict observed Broadwell passes remain valid within their original scope. No kernel or host policy changes were made.

Next: define and validate a normal boot completion signal and acceptance contract, using the Intel reference as a control before comparing AMD. Keep standalone and hosted qualification separate.

Archived evidence SHA-256: `16697275beb7825bc09348d6eace45822de499a205daa5aaf7fabff88bddaa73`.
