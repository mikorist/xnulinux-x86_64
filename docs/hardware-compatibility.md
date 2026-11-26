# Hardware compatibility

> [!NOTE]
> A development machine, target machine and emulated CPU model are three different things. This matrix is not a supported-hardware list.

PC hardware is the project target; Intel is the established reference research lane, with bounded physical results; Ryzen is the primary compute and parallel AMD development host. See [project philosophy](project-philosophy.md).

Physical Intel component evidence is recorded through checkpoint 317; CP460 adds scoped native Ryzen Linux KVM qualification. Development environments, emulated models and physical hardware remain separate evidence classes. See [platform scope](platform-scope.md).

| CPU or model | Environment | Recorded status |
| --- | --- | --- |
| Intel Core i7-4770 (Haswell) | Physical target | Planned; no physical hosted result in the reviewed records |
| Intel Core i5-7500T (Kaby Lake) | Physical Debian development host, Liquorix 7.3.5-2 | Selected original linked XNU code in Linux userspace; bounded CPL0 adapter, recompiled original XNU PE/VM subsets and FKI mapping races confirmed; not complete hosted XNU |
| QEMU Haswell-v2 | Standalone TCG | Early checkpoints; later kernel rejected emulated pre-C0 stepping |
| QEMU Broadwell-v2 | Standalone TCG | Read-only root mount, native PID 1 and terminal-only replay confirmed |
| QEMU Broadwell-v2 | Isolated Linux guest | FKI module lifecycle, cooperative SMP and bounded service regression confirmed |
| Other Intel generations | Physical hosts | Not qualified by these records |
| AMD Ryzen 7 5700X (Zen 3) | WSL2 development host | Operational compute environment; no native AMD hosted qualification |
| QEMU EPYC-Rome-v1 / EPYC-Genoa-v1 | AMD model / decoder fixtures | Cache and topology investigation; not complete XNU runtime or physical CPU qualification |
| QEMU EPYC-Milan-v1 | Isolated TCG guest | Active Zen 3 model development and regression lane; not native AMD execution |
| AMD Ryzen 7 5700X | Nested KVM under WSL2 | Both selected Linux guests: 94/94 functional marker groups; strict SRSO HOLD, not bare-metal qualification |
| AMD Ryzen 7 5700X | Native Linux KVM | CP426 strict 94/94 on both selected guests, SRSO Safe RET; guest TSA and CPU feature dependency HOLD; not full XNU boot |
| AMD x86_64 | Physical hosts | Active parallel development; bare-metal qualification pending |

The development host records identify Debian 13 and Clang 19.1.7; these are observations rather than minimum supported versions.

## Firmware and features

Legacy SeaBIOS and UEFI firmware probes were investigated separately. Standalone Legacy QEMU is the verified mount/read lane; the UEFI probe does not establish a booted XNU. Physical Libreboot compatibility is not established by the reviewed results.

Record CPU model and stepping, host kernel, firmware where relevant, RAM, graphics and devices, execution mode, exact project commit and observed test boundary. Redact serial numbers and other identifying machine data.

Graphics, SMP, NMI, runtime isolation and physical hosted lifecycle require independent qualification. A successful build on a CPU does not establish runtime compatibility.

For exact representative kernel versions and scoped build/runtime tests, see the [Linux host compatibility matrix](../research/2026-11/hosted/linux-kernel-compatibility.md). No general 6.x deployment guarantee is implied. Checkpoint 240 narrowed ongoing development regression to the running Liquorix kernel 7.3.5-2 and selected 6.19.14-2. No new physical insertion is established by the later guest-only results.

AMD-model QEMU TCG guests run on Intel or Ryzen development hosts. EPYC-Milan-v1 approximates Zen 3, not an exact Ryzen model. The Ryzen WSL2 host is operational; TCG, nested KVM, and bare-metal AMD Linux are separate evidence classes. Independently qualify physical AMD execution before claiming support. See [testing](testing.md#planned-cross-vendor-x86_64-test-strategy).
