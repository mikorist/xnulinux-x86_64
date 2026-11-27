# ADR 0003: Three execution modes, one runtime

- Date: 2026-11-25
- Status: Accepted product direction

## Decision

Headless, desktop and seamless modes share the Intel hosted XNU, FKI, loader, Darwin runtime and host backends. Do not create independent kernels for each mode or one kernel per application.

## Consequences

Headless execution can progress without graphics. Desktop mode provides a graphical reference environment. Seamless mode requires actual window, compositor, focus and input integration with Linux.

The minimal open runtime must remain independent of a complete proprietary macOS installation. Compatibility and applicable license restrictions remain separate concerns.

See [architecture](../architecture.md).

## Clarification (November 27, 2026)

The original shared-runtime decision applies within each version target and across qualified CPU vendors. Monterey and Tahoe require version-matched runtimes; common Linux backends and FKI contracts are reused only when validated. See [ADR 0005](0005-extensible-version-targets.md).
