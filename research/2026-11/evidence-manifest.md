# Selected evidence manifest

Snapshot: 2026-11-25, checkpoint 154. Values below are transcribed from the journal and inspected result records; no new kernel build was performed.

| Artifact or observation | Identity or value |
| --- | --- |
| Source pin | `27b03b360a988dfd3dfdf34262bb0042026747cc` |
| Root mount kernel 23 | `56276f72bb54f6747a010db74305546c0f6ca6402740a760682add412524d002` |
| Original HFS fixture | `8b249ed15652b47db5090b8ff7d86db6fe7ec3f278b7dc597622c0b37a887d73` |
| File-read kernel 25 | `60734fdbcf5c677402a40fa55310969178c0c88547c122c09d8a96d66ff7c153` |
| Owned HFS+ disk containing the test file | `a0d86d09a8241591ef8882edb8fc7d3d70dbdce8930069740c934260d0fce2aa` |
| Owned 39-byte file contents | `176667f80465651448a3e7e2fbce5dcf57b928976f017797d9a33ec77374b9d5` |

## Selected file-read evidence

The inspected FILE-READ.json reports:

- Path: /probe.txt
- Bytes: 39
- Lookup and read return: 0
- Residual: 25
- Missing pathname errno: 2
- Disk unchanged: true

The complete raw result files and replay inputs have not been exported. See [root mount](filesystem/first-root-mount.md) and [file read](filesystem/first-file-read.md).

The [CP643-755 chronology](updates-643-755/README.md) records all 113 primary evidence identities. Digests identify retained records, not downloadable proof bundles; no individual ledger promotion is implied.
