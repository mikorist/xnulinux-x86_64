# Indexed VM ownership and the first integrated boot metadata consumers

**Date:** 2026-11-26  
**Checkpoints:** 243–267

## Native source-backed map subsets

243–248 established independent map and inactive-root references using original vm_map_reference/deallocate bodies and bounded destroy adapters. Entry disposal before root release, original zap append/pop/dispose, a surviving alias to independently retained backing, mixed object/submap disposal and two map owners sharing a root were verified. The child submap in 247 is empty; 248 retains both root pages until the last owner releases them.

249–252 incorporated the original ordered list and red-black store macros/comparator, predecessor lookup through a gap, original range protection checks and removal of a whole selected entry from both indexes before disposal. Partial spans are rejected unchanged. These are metadata permission and bounded lifetime checks, not hardware mapping protection or general clipping. 253 verified the completed source set on both selected Linux kernels, reusing the current-kernel result. 254 then connected indexed lookup to actual FKI backing read; a gap returned ENOENT without modifying output.

## Boot metadata

255 identified a real early-boot data consumer: original Intel doublemap_init needs HIB segment/text metadata. Offline extraction from the verified linked kernel produced 4,160 bytes with 21 load commands and 13 segments. 256 staged that exact header across two read-only owned entries. 257 read the full header atomically across object and provider transfer boundaries. 258 executed original Mach-O segment/section accessors on the validated private bytes, matching all 13 segments and 35 sections.

259 tested a bounded structural validator in GCC14 UBSan userspace: 23 test groups including all shorter prefixes, malformed commands, section counts and extents. Structural validity is not authentication. 260 distinguished malformed snapshots from a valid-structure provenance mismatch, rejecting both before legacy access. 261 repeated the same source on both targets.

262 replaced the fixed-length read with bounded prefix-discovered length and a map-locked snapshot; missing entry or invalid prefix/cap preserves output. 263 executed original i386_vm_init range-calculation statements, matching 15 oracle fields. No actual native VM initialization. 264 retained a 248-byte pointer-free layout after teardown, with actual RNG/UTC packet; clock failure preserves output. An initial wire type mismatch was fixed. 265 used exact 4096-byte boot_args and original PE parser for five options; firmware/physical fields remain unset. 266 consumed actual FKI seed through original PE device-tree code once, then erased it. 267 closed the integrated milestone on both Linux targets, with identical source, ten serial gates, four matched allocations/frees and six closes per guest.

| Integration evidence | SHA-256 |
| --- | --- |
| Two-kernel indexed map (253) | bde3b389c2a9565b1bac5ac1ef1d1b3279439a9dc0945a579998fe36683d74e3 |
| Header oracle (255) | 595b4197a60305060f37e48abb5d27a4be952d80a6382c2a0c3b3c5841a4ea84 |
| Two-kernel metadata (261) | 5c0dd52b1a9ba9867b6587508dea89c8a52478eedfda5a1479127e9f2a374e96 |
| Two-kernel PE seed/layout (267) | be58fd0bebc4acd70962e28001689fb87e08bf52b6e74323c03aab84c63315de |

The source diary records actual sh run.sh guest tests, exact-source extraction commands and individual manifest hashes. All integrated tests here are isolated Linux guests, not a loaded native XNU image, executable guest mapping, actual firmware handoff or physical hosted boot. The next real boot dependencies are clock, entropy and early machine/thread initialization.
