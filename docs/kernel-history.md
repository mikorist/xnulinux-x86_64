# Experimental kernel image history

All entries are research images, not releases. The source baseline is XNU 8020.140.41. Later diagnostic branches do not necessarily inherit every feature of earlier images.

| Image | Checkpoint | Purpose | Inputs |
| ---: | ---: | --- | ---: |
| 1 | 68 | First strict executable | 993 |
| 2 | 74 | Legacy platform adapter | 993 |
| 3 | 75 | Measured clock adapter | 993 |
| 4 | 83 | ACPI parser candidate | 993 |
| 5 | 89 | Scalar early console | 993 |
| 6 | 98 | Standalone typed allocation consumer | 993 |
| 7 | 100 | Bounded typed-zone capacity | 993 |
| 8 | 118 | ACPI PM reference | 993 |
| 9 | 120 | Legacy UP platform personality | 993 |
| 10 | 123 | BearSSL diagnostic KAT | 1000 |
| 11 | 125 | NetBSD DRBG diagnostic KAT | 1002 |
| 12 | 126 | Native PRNG lifecycle integration | 998 |
| 13 | 131 | Static pthread integration | 1001 |
| 14 | 132 | Mbed TLS primitive tests | 1014 |
| 15 | 133 | Digest/HMAC ABI tests | 1015 |
| 16 | 135 | Scalar AES ABI tests | 1022 |
| 17 | 137 | GCM ABI tests | 1025 |
| 18 | 139 | DES/TDES ABI tests | 1029 |
| 19 | 141 | Remaining crypto candidates | 1048 |
| 20 | 142 | Diagnostic crypto registration | 1049 |
| 21 | 146 | Root media correction | 1049 |
| 22 | 149 | Block I/O probe | 1049 |
| 23 | 150–151 | First HFS+ root mount | 1089 |
| 24 | 152 | Integer-only HFS regression | 1089 |
| 25 | 153–154 | Named file read | 1089 |

All listed strict links reported zero undefined symbols. This is not a claim that all images completed boot or passed equivalent runtime tests.

## Selected image identities

| Image | SHA-256 |
| ---: | --- |
| 1 | `75487040094e5c5a4733ec594cf49146b0644883c856abcd0bf0916c1d7b50fc` |
| 7 | `543499b8b27ccba8944d7de2e47cd5677584ca7f51d964fef0227a0c0dbfbb2e` |
| 12 | `e80763dc779155f530e591eb20b63b16f0cdf68b7336ff41de709d59853815cf` |
| 20 | `3b99bd41637f53fc3af8d0edc036e973e7b8e0282f933449f5e7f980cc9bf3e2` |
| 23 | `56276f72bb54f6747a010db74305546c0f6ca6402740a760682add412524d002` |
| 24 | `ab08abae45036e955225de91cfcab22210a40936cd3dc031aa441426e6ccb950` |
| 25 | `60734fdbcf5c677402a40fa55310969178c0c88547c122c09d8a96d66ff7c153` |

These identities are transcribed from the research journal, not newly computed hashes. Full artifact manifests remain in the local archive.
