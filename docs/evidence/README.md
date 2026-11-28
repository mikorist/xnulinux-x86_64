# Evidence and demonstrations

Measured results belong here. Planned functionality belongs in the roadmap. A screenshot is useful when it tells us what actually ran.

## Where to start

| Evidence | Report | What it establishes |
| --- | --- | --- |
| Ordinary standalone Monterey PID 1 | [CP627](../../research/2026-11/checkpoint-627.md) | Broadwell TCG UP console completion without debugger on both development hosts |
| Retained executable reproduction | [CP700](../../research/2026-11/updates-643-755/checkpoint-681-700.md) | Matching CP602 executable with 95 regenerated and 1,019 retained inputs |
| Native Ryzen Linux KVM components | [CP460](../../research/2026-11/hosted/native-amd-kvm.md) | Scoped component replay, not full hosted XNU |
| Public userspace tests | [CP633](../../research/2026-11/checkpoint-633.md), [CP634](../../research/2026-11/checkpoint-634.md), [CP635](../../research/2026-11/checkpoint-635.md) | Structural validator and synthetic replay verifier results |
| Source-only tools archives | [CP742-755](../../research/2026-11/updates-643-755/checkpoint-742-755.md) | Scoped source archives and identical shared-input object; release HOLD |
| Platform reuse inventory | [CP641](../../research/2026-11/checkpoint-641.md) | 113 retained GPU/kext file identities; no graphics execution or license clearance |

These are linked reports, not downloadable kernel artifacts. Consult the [current state](../../PROJECT-STATE.json) and [qualification matrix](../qualification-matrix.md) for the latest evidence and limits.

## Screenshots and recordings

No new screenshots or videos have been published here yet. Add genuine captures under a version/checkpoint directory when available, with meaningful alt text and a caption stating the exact artifact, test environment, observation, limitations and related report. Do not publish identifying host data, secrets, proprietary material without permission, or mockups as evidence. Large recordings belong in a reviewed release or evidence archive. See the [distribution plan](../maintainers/distribution-plan.md).

[Project home](../../README.md) · [Research journal](../../research/README.md) · [Documentation](../README.md)

CP642: [synthetic framebuffer conversion](../../research/2026-11/checkpoint-642.md), identical PNG output across both x86 development environments. No live display or GPU execution.


- [CP643-755 research update](../../research/2026-11/updates-643-755/README.md): 113 individually identified outcomes with primary evidence SHA256 values; retained evidence records are not downloadable here.
- [CP754-755](../../research/2026-11/updates-643-755/checkpoint-742-755.md): partial SDK declarations and shared-input object reproduction, not runtime or release qualification.

- [CP776-795 research update](../../research/2026-11/updates-776-795/README.md): 20 reviewed outcomes and primary hashes; no new boot or full replay bundle.
- [CP756-775 research update](../../research/2026-11/updates-756-775/README.md): 20 reviewed outcomes and primary hashes; no new boot or full replay bundle.

---

<p align="center">
  <sub>Support the maintainer via the existing <a href="https://diyaudio.rs/">diyAudio.rs</a> donation button. Thank you!</sub>
</p>
<p align="center">
  <a href="https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&amp;hosted_button_id=AEXH39XRNHZQ2&amp;currency_code=EUR"><img src="https://img.shields.io/badge/PayPal-donate-0070BA?logo=paypal&amp;logoColor=white" alt="Donate via PayPal"></a>
</p>

- [CP796-815 research update](../../research/2026-11/updates-796-815/README.md): 20 reviewed outcomes and primary hashes; no new boot or complete replay bundle.

- [CP816-835 research update](../../research/2026-11/updates-816-835/README.md): 20 reviewed outcomes and primary hashes; no new boot or complete replay bundle.

- [CP836-855 research update](../../research/2026-11/updates-836-855/README.md): 20 reviewed outcomes and primary hashes; no new boot or complete replay bundle.

- [CP856-875 research update](../../research/2026-11/updates-856-875/README.md): 20 reviewed outcomes and primary hashes; no new boot or complete replay bundle.

- [CP876-895 research update](../../research/2026-11/updates-876-895/README.md): 20 reviewed outcomes and primary hashes; no new boot or complete replay bundle.

- [CP896-915 research update](../../research/2026-11/updates-896-915/README.md): 20 reviewed outcomes and primary hashes; no new native boot or complete replay bundle.
