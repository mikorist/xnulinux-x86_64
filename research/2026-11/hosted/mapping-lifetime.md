# Linux-backed aliases and concurrent mapping lifetime

**Dates:** 2026-11-25 to 2026-11-26  
**Source checkpoints:** 207, 212–213.  
**Scope:** Actual Linux vmap/vunmap and bounded logical mapping services; not an independent XNU pmap.

## Physical mapping service (207)

The GPL FKI provider introduced bounded ENTER, REMOVE, PROTECT, READ and WRITE operations. The logical address is an identifier; Linux chooses the actual alias. The provider uses real vmap/vunmap and validates backing-page identity. Mapping is limited to nonexecutable aliases; protection downgrade creates a read-only alias before dropping the old mapping, preserving the original on failure. Live mappings prevent backing-page free; cleanup unmaps first.

The test covers distinct sessions using the same logical address, two coherent aliases of one page, independent backing pages, bad handles/ranges/alignment, permission rejection, downgrade, stale identity and cleanup. It does not deliberately fault on a read-only alias or audit hardware PTE permissions; existing trusted raw allocator access can still mutate the backing page. Therefore the API is not a hostile-kernel isolation boundary.

A first successful guest runtime was misclassified because the verifier expected 2,304 rather than 2,368 checks. The expected count was corrected, not the runtime result. The final 22 cold boots passed the strict warning gate with 1,408 mapping rounds, 52,096 mapping checks, 5,632 map/unmap operations each and 1,408 downgrades. All representative Linux 6.x targets and two current Liquorix boots used the same source.

Physical testing recorded 286,144 combined checks, 256 maps/unmaps, 64 downgrades and 1,408 matched allocations/frees. Normal dependency-aware module removal passed.

Matrix SHA-256: `652bd44402d0aeba3bd31d4c70a5a126ef8155166f70fe48831baa4e72e01b3f`. Physical result: `24bf8651243f5f2dbfac7a4c05281a78864e1697ec6342a45c855337339f6e2e`.

## Concurrent lifetime gate (212–213)

The provider and APSL resident client were unchanged from checkpoint 211. A distinct GPL-only regression driver with no exports tests four pairs of competing operations, using CPU-pinned workers and a rendezvous. The existing mutex still serializes actual provider operations.

| Race | Checked invariant |
| --- | --- |
| ENTER versus FREE | One commit at the shared sequence; mapped or stale page rejection |
| PROTECT versus WRITE | Preserve correct data and reject writes after downgrade |
| REMOVE versus FREE | No backing free before alias removal |
| READ versus CLOSE | Correct data or stale-session rejection |

Failure mailboxes must remain unchanged. The first guest runtime passed with 3,840 checks, but the verifier expected 4,096; the original record was preserved and the expected count corrected.

The final 22 boots recorded 2,816 rounds, 11,264 paired races, 84,480 race checks and 118,272 resident checks. All four vCPUs participated in each run; 14,080 allocations/frees, 15,300 maps/unmaps and 5,632 closes matched. No active sessions remained.

The independently authorized physical test of the exact candidate recorded the following:

| Outcome | Guest aggregate | Physical run |
| --- | ---: | ---: |
| Enter wins / free wins | 1220 / 1596 | 92 / 36 |
| Protect wins / write wins | 1200 / 1616 | 80 / 48 |
| Remove first / free busy | 1149 / 1667 | 84 / 44 |
| Read wins / close wins | 1179 / 1637 | 78 / 50 |

All four physical cores participated. The 128 rounds included 512 paired races, 3,840 race checks and 5,376 resident checks; 640 allocations/frees, 732 maps/unmaps, 128 downgrades and 256 closes. No remaining sessions or modules; no new warning/fault markers in the verified log delta.

MAP-RACE-MATRIX SHA-256: `3c50c0ae265f99f6e3ca4cbf9ac1715644ea81aedee9587183c5c52ce3b60908`. Physical result: `363a20cf6af2ecf0b313d9c2d75060da7c99f84c4f8e430e8182ae984773319b`.

These are actual Linux alias lifetime tests, not concurrent manipulation of live XNU PTEs. No independent XNU page-table root, hardware TLB qualification, executable alias, allocation failure injection or native XNU scheduler follows from them.
