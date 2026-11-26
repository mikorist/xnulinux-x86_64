# Hardware compatibility

> [!NOTE]
> A development machine, target machine and emulated CPU model are three different things. This matrix is not a supported-hardware list.

PC hardware is the project target; Intel is the current qualified research lane. See [project philosophy](project-philosophy.md).

Historical hardware snapshot: checkpoint 317, 2026-11-26. Later guest-only milestones do not imply additional physical hardware qualification.

| CPU or model | Environment | Recorded status |
| --- | --- | --- |
| Intel Core i7-4770 (Haswell) | Physical target | Planned; no physical hosted result in the reviewed records |
| Intel Core i5-7500T (Kaby Lake) | Physical Debian development host, Liquorix 7.3.5-2 | Selected original linked XNU code in Linux userspace; bounded CPL0 adapter, recompiled original XNU PE/VM subsets and FKI mapping races confirmed; not complete hosted XNU |
| QEMU Haswell-v2 | Standalone TCG | Early checkpoints; later kernel rejected emulated pre-C0 stepping |
| QEMU Broadwell-v2 | Standalone TCG | Read-only root mount, native PID 1 and terminal-only replay confirmed |
| QEMU Broadwell-v2 | Isolated Linux guest | FKI module lifecycle, cooperative SMP and bounded service regression confirmed |
| Other Intel generations | Physical hosts | Not qualified by these records |
| AMD x86_64 | Physical hosts | Active parallel development; bare-metal qualification pending |

The development host records identify Debian 13 and Clang 19.1.7; these are observations rather than minimum supported versions.

## Firmware and features

Legacy SeaBIOS and UEFI firmware probes were investigated separately. Standalone Legacy QEMU is the verified mount/read lane; the UEFI probe does not establish a booted XNU. Physical Libreboot compatibility is not established by the reviewed results.

Record CPU model and stepping, host kernel, firmware where relevant, RAM, graphics and devices, execution mode, exact project commit and observed test boundary. Redact serial numbers and other identifying machine data.

Graphics, SMP, NMI, runtime isolation and physical hosted lifecycle require independent qualification. A successful build on a CPU does not establish runtime compatibility.

For exact representative kernel versions and scoped build/runtime tests, see the [Linux host compatibility matrix](../research/2026-11/hosted/linux-kernel-compatibility.md). No general 6.x deployment guarantee is implied. Checkpoint 240 narrowed ongoing development regression to the running Liquorix kernel 7.3.5-2 and selected 6.19.14-2. No new physical insertion is established by the later guest-only results.

AMD-model QEMU TCG guests run on Intel or Ryzen development hosts. EPYC-Milan-v1 approximates Zen 3, not an exact Ryzen model. The Ryzen WSL2 host is operational; TCG, nested KVM, and bare-metal AMD Linux are separate evidence classes. Independently qualify physical AMD execution before claiming support. See [testing](testing.md#planned-cross-vendor-x86_64-test-strategy).
