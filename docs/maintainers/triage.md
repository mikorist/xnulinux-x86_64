# Issue triage

## Classify before assigning

| Category | Examples | Initial handling |
| --- | --- | --- |
| Build | Missing dependency, compile or link failure | Check pin, configuration and command |
| Standalone runtime | QEMU diagnostic panic or assertion | Identify last actual boundary |
| Hosted runtime | Linux module lifecycle, host instability | Review privately if security-sensitive |
| Hardware | CPU, firmware or device compatibility | Require exact tested environment |
| Documentation | Incorrect claim, stale command, broken link | Identify affected revision and page |
| Research | New hypothesis or isolated experiment | Record scope and acceptance evidence |

Suggested labels for future configuration: `area:build`, `area:mach`, `area:iokit`, `area:bsd`, `area:fki`, `area:docs`, `scope:standalone`, `scope:hosted`, `needs-evidence`, `blocked`, `confirmed`. These labels are proposed, not already created.

## Evidence review

Verify the reported source commit, command, environment and observed result. Separate guest failures from verifier failures and distinguish a known unsupported configuration from a new regression. Ask for a smaller sanitized reproduction instead of entire disk images or unfiltered register dumps.

A report remains unconfirmed until evidence supports it. A hypothesis may be useful without being promoted to a confirmed defect.

## Closing an issue

Record the relevant fix revision or reason for closure, what was tested and any remaining limitations. Link the canonical report rather than duplicating the full research log.
