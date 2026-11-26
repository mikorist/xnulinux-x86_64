# Standalone PID 1 and independent terminal-only replay

**Date:** 2026-11-25  
**Source records:** checkpoints 155–160, 163, 173–177.  
**Scope:** XNU 8020.140.41, isolated QEMU TCG, Broadwell-v2, one vCPU.

A custom freestanding, ad hoc signed x86_64 Mach-O executable was placed at the normal bootstrap path on an owned read-only HFS+ fixture. It is not Apple's launchd and has no dyld or libSystem dependency. The initial instrumented run confirmed native exec, ring-3 entry, BSD system calls and a Mach trap.

## Reproducibility correction

The initial short terminal-only attempts did not reach the user marker. Inspection of the waiting kernel thread identified native RTC, NVRAM and IOBSD resource waits, totaling up to 90 seconds. This was not evidence of a scheduler regression. The longer replay changed only the verifier timeout from 90 to 180 seconds.

| Checkpoint | Result |
| --- | --- |
| 156 | Positive instrumented kernel25 PID 1 execution |
| 163 | Positive instrumented HFS v2 regression |
| 174 | Terminal-only v2 boot with read-only filesystem policy tests and native user file read; 92.309 s |
| 176 | Independent kernel25 terminal-only replay; 92.249 s |
| 177 | Direct native HFS sysctl attribution; eight intermediate observational stops |

Checkpoint 176 recorded process and QEMU exit zero, two terminal markers, zero intermediate steps, actual CPL3, PID 1, nonzero Mach task port, expected user success marker and 1,647 classified page faults with no null or unexpected exception vectors. Inputs remained unchanged.

Historical kernel25 SHA-256: `60734fdbcf5c677402a40fa55310969178c0c88547c122c09d8a96d66ff7c153`. Checkpoint 176 RESULT.json SHA-256: `cdbc50b78d6b915e0f8ac197c4a90fca8dd5e4bc5e1ecddf6ae6b35edcc57705`.

## Read-only HFS policy

Checkpoint 174 verified native statfs64, four unsupported filesystem sysctl requests, a rejected write-open and exact 39-byte user open/read/close. Checkpoint 177 observed all four ENOTSUP returns directly from hfs_sysctl. Ten monitored forbidden write/journal/extend execution points remained untouched; this corrects the earlier count of nine. The entire 8 MiB disk matched its input hash.

The separate negative mount fixtures in checkpoints 164–172 documented rejection of unsupported or invalid headers. These are restricted read-only fixture results, not writable HFS or journal support.

## Limits

Terminal-only debugger observation is not completely debugger-free execution. The results support native standalone user-program execution, not full launchd, macOS frameworks, physical hosted execution or universal boot stability. Repeatability, RTC services, debugger-free console output and additional native user tests remain distinct gates.

The original local run-07.py, run.py and run-02.py, result records, commands and fault logs remain in the research archive. A clean public reproduction bundle is not yet available.
