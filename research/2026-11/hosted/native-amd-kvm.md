# Native AMD KVM component replay and SRSO qualification

November 26, 2026, checkpoint 460. The owner booted a verified Linux USB on a physical Ryzen 7 5700X (Zen 3), BIOS P10.62, microcode 0x0a201213. The native Linux host ran 7.3.5-2-liquorix-amd64. QEMU 10.0.13 used KVM with host CPU passthrough, two vCPUs, 768 MiB RAM, no network or attached host disk, and a fixed, hash-verified CP426 component fixture. This is hardware-assisted guest component evidence on native AMD Linux, not an XNU bare-metal or full hosted boot.

| Test | Guest kernel | Exit | Original strict verifier | SRSO |
|---|---|---|---|---|
| Current | 7.3.5-2-liquorix-amd64 | 0 | 94/94 PASS | Mitigation: Safe RET |
| 6.x | 6.19.14-2-liquorix-amd64 | 0 | 94/94 PASS | Mitigation: Safe RET |

The native host also reports Mitigation: Safe RET. All nine retained evidence hashes were independently checked, including the original input manifest. The original verifier and marker manifest hashes match the previously retained CP426 inputs, and the unchanged verifier independently accepted both original serial logs. The console initrd hashes match CP426 records; the input binaries were not independently rehashed during this review.

Evidence SHA256:

- Current guest log: `0306ee0c58e36511b2146fc7b859d2bc636e72c3f25ddee815027ec2f78defb8`
- 6.x guest log: `ab9315edae87a95a5c9bb963caaad8fed7810c22d490e33e96887d83d06ec7f5`
- Original verifier: `a825d8ff46b8eeb6d6e995b2ca5cc27c58f20a94d2c1778ea8a26c110bf09196`
- Reviewed result: `f8e6f94781fc239f4798db5aafd52cd9875d9f3c865bdab6a781dc7bc00461af`

## Separate outstanding qualifications

Native SRSO and CP426 strict component replay are PASS for this configuration. The earlier Hyper-V/WSL2 SRSO HOLD is not superseded for that environment. The native host reports TSA mitigation (Clear CPU buffers), but both KVM guests report Transient Scheduler Attacks: Vulnerable: No microcode. A CPU feature dependency warning is also retained. The original broader control/aggregate HOLD remains intact. TSA and the feature dependency require separate investigation; no mitigation or verifier was weakened.

The AMD machine layer remains under development. The later CP458/459 clock and performance capability previews are separate TCG diagnostics, not native AMD boot evidence. Complete AMD standalone admission, hosted integration, source redistribution and general hardware/security qualification remain open.
