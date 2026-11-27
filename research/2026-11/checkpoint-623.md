# CP623: Serial-only observation and silent PID 1 fixture

**Outcome: HOLD (independent completion signal absent).** November 27, 2026.

Unchanged CP602 Broadwell TCG UP boots on both hosts were observed without a debugger at 12, 30 and 60 seconds. Both produced 1,312 serial bytes by the first sample, ending at BSD buffer initialization, with no further serial bytes by the final sample. Both processes were terminated at the observation deadline.

The current root image on both hosts matches the original owned signed PID 1 fixture. Its success and failure terminal loops produce no console completion output. The earlier historical terminal-only successful run took approximately 92 seconds; a 60-second observation cannot establish a definitive failure. No ordinary PID 1 result, hang or new AMD qualification is claimed. No kernel, fixture or protection changes were made.

Next: define a separate owned userspace fixture with explicit completion output and independent acceptance evidence, while preserving the exact CP602 regression baseline and existing AMD admission requirements.

Archived evidence SHA-256: `ee8b38b2f863102db74ae1fe4a997c6d4bf8c4ac6f462110f2489d065a6d79de`.
