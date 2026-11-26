# Frequently asked questions

## Is this a Hackintosh?

No. The goal is to adapt XNU to standard PC hardware through Linux, rather than make a PC pretend to be a Mac. The intended design hosts XNU within Linux rather than replacing Linux with a conventional macOS installation. See [project philosophy](project-philosophy.md).

## Why PC if the current target is Intel?

PC describes the intended platform, x86_64 the architecture, and Intel the initial implementation and qualification target. AMD support is planned after the stable Intel hosted baseline. Native AMD adaptation or an XNU-facing compatibility layer will be evaluated; neither is yet qualified. Other configurations likewise require separate evidence.

## Does it need QEMU?

QEMU is used for standalone development and regression tests. The intended hosted product does not require a conventional macOS virtual machine. That final execution model must still be demonstrated independently.

## Can I run macOS applications today?

Standalone research has demonstrated root mount, native file reading and execution of an owned Darwin Mach-O PID 1 program. It has not demonstrated a supported macOS application runtime or hosted XNU boot. Follow the [qualification matrix](qualification-matrix.md).

## Why Monterey?

The initial Intel port uses XNU 8020.140.41 as an independent baseline. Newer XNU versions are not mandatory for the first port. See [ADR 0001](adr/0001-independent-xnu-versions.md).

## Will I need the whole macOS desktop?

The intended modes are headless, desktop and seamless. They share a runtime; the minimal open headless path should not require a complete proprietary macOS installation.

## Can you distribute macOS or its frameworks?

The project intends to publish its own code and redistributable dependencies according to their licenses. Compatibility does not grant redistribution rights. Proprietary components are separate.

## Why keep failed experiments?

They record actual constraints and prevent repeated work. See [lessons learned](../research/2026-11/lessons-learned.md).

## Can AMD development start without an AMD computer?

Yes. The planned early test lane uses QEMU TCG with AMD CPU models on the existing Intel Linux host. It can establish scoped emulated behavior, but real AMD hardware is needed for final physical qualification. See [testing](testing.md#planned-cross-vendor-x86_64-test-strategy).
