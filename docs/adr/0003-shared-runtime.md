# ADR 0003: Three execution modes, one runtime

- Date: 2026-11-25
- Status: Accepted product direction

## Decision

Headless, desktop and seamless modes share the Intel hosted XNU, FKI, loader, Darwin runtime and host backends. Do not create independent kernels for each mode or one kernel per application.

## Consequences

Headless execution can progress without graphics. Desktop mode provides a graphical reference environment. Seamless mode requires actual window, compositor, focus and input integration with Linux.

The minimal open runtime must remain independent of a complete proprietary macOS installation. Compatibility and applicable license restrictions remain separate concerns.

See [architecture](../architecture.md).
