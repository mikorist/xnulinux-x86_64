# Security policy

## Project status

The x86_64 port is experimental. No production-supported Intel release or security-maintenance lifetime is asserted by this policy. Research checkpoints, local diagnostic images and proposed product versions are not supported release lines.

Kernel hosting involves privileged execution and shared host resources. Experimental builds may crash or corrupt state. Use isolated development systems, recoverable test environments and reviewed test inputs.

## Reporting a potential vulnerability

Use the repository's private vulnerability reporting feature if available under its Security tab. If private reporting is unavailable, request a private maintainer contact through a minimal public issue without revealing the vulnerability, sensitive logs or reproduction details.

Include privately, where applicable:

- Affected commit, architecture, host kernel and configuration.
- Whether the issue occurs in standalone or Linux-hosted execution.
- Expected and observed behavior, impact and relevant sanitized evidence.
- Any safe reproduction constraints and affected versions you have actually tested.

Do not publish credentials, raw entropy, private memory/register contents, personal information or proprietary binaries. Do not test against systems you do not own or have authorization to assess.

## Triage and disclosure

The maintainer should distinguish a functional defect, research limitation and credible security issue, then coordinate a fix and disclosure with affected upstream projects as appropriate. No guaranteed response or remediation timeframe is specified.

Production cryptographic assurance, guest isolation and full host lifecycle qualification remain separate release gates. Passing known-answer tests does not establish production security or certification.

For ordinary non-sensitive build and compatibility failures, use the normal issue process described in [CONTRIBUTING.md](CONTRIBUTING.md).
