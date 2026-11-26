# First physical Intel ring-0 execution

**Date:** 2026-11-25  
**Source checkpoints:** 196–198.  
**Physical environment:** Intel Core i5-7500T, Linux 7.3.5-2-liquorix-amd64.

## Static trusted adapter

Checkpoint 196 compiled the owned adapter through native Kbuild, not by mapping arbitrary Mach-O code in ring 0. The trusted linked ELF module retained the typed service contract and used ordinary Linux scheduling and resource ownership. It did not write CR3, GS, IDT, GDT or MSRs and did not register an NMI callback. Kbuild recorded unwind and mitigation metadata, including ENDBR64 and return/indirect thunks.

Two current-kernel four-vCPU guest boots and twenty representative 6.x two-vCPU guest boots passed. Each CPU exercised 128 successful entries, 256 service calls and five negative cases. A preflight initially masked a failure from unavailable sysfs in the isolated environment; the corrected fail-closed preflight was blocked until the physical environment was checked.

## Checkpoint 197: physical host

The maintainer explicitly authorized the bounded module test. Physical preflight verified the exact module hash, kernel vermagic, four online CPUs and actual module/lockdown policy. A missing modinfo PATH entry was corrected. The existing unsigned-module policy was not changed.

One actual insmod and normal rmmod both returned zero. The module was absent afterward, uptime continued and the recorded kernel-log delta contained no panic, oops, BUG or CPU warning.

| Metric | Observed |
| --- | ---: |
| Physical CPUs exercised | 4/4 |
| CPL0 adapter entries | 512 |
| Linux host service calls | 1024 |
| Negative cases | 20 |
| Selected CPU state mismatches | 0 |

Module SHA-256: `6f3f191ca2a5aeac1d6a566155222e2aa48664376eb9db958dc4cb8d016e95dd`. Physical RESULT.json SHA-256: `f913f9bd6267043957464809227d0d14de5ef0fed210099f2fe6c673eb4b6c86`.

Expected out-of-tree/unsigned module taint persisted after unload. This was an approved narrow static adapter, not an original Mach-O XNU ring-0 execution or world switch. The authorization does not carry forward to arbitrary future modules.

## Checkpoint 198: original XNU source components

Original function bodies from the pinned Apple PE device-tree, seed and boot argument sources were extracted with their source provenance and original APSL notices preserved. A separate compatibility adapter supplied fixed owned inputs. The functions were recompiled as Kbuild ELF, not executed as original Mach-O bytes. All 15 imports were audited as ordinary EXPORT_SYMBOL entries in the target symbol manifest. The module declared its non-GPL-compatible classification honestly.

The first guest run actually executed successfully but the verifier expected 4,352 rather than 4,608 checks. The original failed verification was retained; the corrected expected count passed two additional cold boots.

The subsequently authorized physical test loaded and unloaded normally and recorded:

- 256 sessions, 512 successful service calls and 4,608 checks.
- Actual CPL0, original SecureDT, seed consumption/erase and argument parser behavior.
- No recorded panic, oops, BUG or CPU warning; host uptime continued.
- Additional P taint for the APSL-side module. The kernel may automatically limit lock debugging under this taint; no manual bypass was performed.

Module SHA-256: `3411ffab35fdc364bec75e1da618c19ac7c0c584779eafa453394e70435ae287`. Physical RESULT.json SHA-256: `8b8090a90ebf3eceabda03d0fccdf64af1d4db73788bb81cbbd9b522a2107f36`.

This establishes source-level execution of selected original XNU components on a physical Linux host at CPL0. It does not establish physical execution of the complete XNU kernel, arbitrary guest mapping, XNU scheduling, pmap or a full world switch. CPU-affinity coverage of checkpoint 197 must not be attributed to checkpoint 198.

Raw physical logs remain private. The original preflight, manifests and results require sanitized export and independent review before publication.
