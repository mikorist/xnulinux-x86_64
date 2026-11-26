# Standalone firmware and clock qualification

**Date:** 2026-11-25  
**Scope:** Legacy QEMU TCG research.

The standalone loader and boot metadata were developed independently of the final hosted FKI architecture. The initial offline metadata fixture and CPU probe did not execute XNU. Subsequent experiments verified actual kernel entry and progressed through platform initialization.

## Clock reference comparison

| Reference | Ordinary runs | Contended runs |
| --- | ---: | ---: |
| PIT baseline | 30/30 | 5/20 |
| PIT bounded retries | 30/30 | 11/20 |
| ACPI PM probe | 20/20 | 20/20 |

The original two-percent acceptance guard was retained. Bounded PIT retries did not solve the observed contention sensitivity. The ACPI PM probe measured real elapsed reference ticks rather than assuming the nominal interval. A further ten contended runs passed; three intentionally frozen-reference tests rejected the handoff.

ACPI PM method 2 became the default Legacy research path. PIT remains an explicit compatibility test path, without silent fallback.

## Other early boot findings

An early console failure was traced to compiler-generated SSE before the required CPU state was enabled. An isolated scalar rebuild removed the premature instructions and the headless console initialization subsequently returned. This is not a global FPU qualification or a visible console-output demonstration.

## Limits

UEFI and physical hardware qualification are distinct. The results do not establish hosted timers, complete ACPI support or production firmware compatibility.

**Source records:** checkpoints 69–90 and 116–118, selected findings.
