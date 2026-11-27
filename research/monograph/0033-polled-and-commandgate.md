# 33. Polled I/O and command-gate callback storage

**Date:** 2026-11-25
**Source checkpoint:** 54 (R0033)
**Scope:** Isolated full translation-unit builds and typed-callback fixture.

The polled I/O unit presented 52 promoted format diagnostics. The isolated source revision mapped them to 21 distinct changes, preserving control flow, disk, crypto and hibernation behavior. It compiled to a 276,144-byte Mach-O object.

IOCommandGate required a different kind of review. The base event-source storage is type-erased, while the concrete command action has a defined owner/argument/result signature. The investigation checked that actual invocation used the restored concrete type. The first build exposed a second cast diagnostic; the failed attempt was retained and the exception scope was restricted to the existing storage conversions, not the entire translation unit.

Full emitted IR confirmed the concrete return and argument shape. An isolated native fixture recorded four successful checks for callback identity, argument widths, signed return and null storage. The resulting command-gate object was 173,000 bytes. This did not execute a real kernel workloop or prove virtual override, block ownership or arbitrary erased callback behavior.

The separate probe count rose to 96 and configured coverage to 965/984. The accepted 869-input baseline and 261 undefined symbols did not change.

Historical source-record SHA256: `0aa592549ae33a99580898493aa790eea999d307f5f8e457e19a46fb490f9a43`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
