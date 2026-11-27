# CP642: Independent framebuffer conversion helper replay

**Outcome: PASS for synthetic tightly packed BGRA conversion.** November 27, 2026.

The unchanged retained ARM-reference helper [fb2png.py](../../tools/hosted/fb2png.py) (GPL-2.0-only) was exercised independently in both x86_64 development environments. Source SHA-256: `ec333009774f7aeab0a0720ea131430a3fd538a06001a40d568d7eea89f5ec8a`.

Six owned deterministic BGRA fixtures per host cover 1x1, 3x2, 7x5, 64x17, 320x200 and 1920x1080. A separate Python standard-library decoder verifies the PNG structure, chunk CRCs, dimensions and every decompressed RGB pixel (2,138,730 pixels per host). Alpha varies independently. All output hashes and the result manifest match across hosts. Six one-byte-short fixtures per host are rejected without generating a PNG.

The existing helper accepts trailing bytes and assumes tightly packed rows. Explicit stride support and general input validation remain open. This is an offline synthetic image conversion result, not a live framebuffer, GPU, desktop or hosted XNU test. No code, kernel, devices, protection settings or license notices were changed.

Next: continue Monterey clean-source closure and separately review version-specific runtime/display adapter contracts. Preserve all hosted and Tahoe gates.

Primary evidence SHA-256: `3336577131abfccd8924a91eb82d6533c35f9c2908ee5d5fa6bf13425e1f3802`.
