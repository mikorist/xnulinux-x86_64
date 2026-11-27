# CP622: Ordinary standalone console and AMD admission rejection

**Outcome: HOLD (AMD admission and ordinary Intel completion).** November 27, 2026.

CP621 omitted the serial console despite the existing loader requesting serial output. CP622 enables standard serial capture and uses a bounded twelve-second observation window. The CP602 loader and initrd remain unchanged. Both CPU models were tested on both development hosts under isolated QEMU TCG UP without a debugger.

| CPU model | Both hosts |
| --- | --- |
| Broadwell-v2 | BSD buffer initialization reported; no independent PID 1 completion marker within the budget |
| EPYC-Milan-v1 | Explicit kernel admission rejection: AMD admission remains unqualified after boot CPU identity; restart reported |

All four emulator processes reached the observation timeout. The AMD console independently confirms deliberate rejection by the existing admission policy. This is not proof of a defect in the previously observed lock-timeout routine. The Intel console establishes progress beyond the loader, not autonomous PID 1 completion. Previous scoped observed Intel passes remain valid. No admission or protection requirement was weakened.

Next: establish ordinary Intel boot completion with independent evidence; retain AMD admission HOLD and continue separately permitted source and build qualification.

Archived evidence SHA-256: `fbfde815963a7ebd74f50e6f51bf336e8555b6030b71369ea368d8a40c9646a5`.
