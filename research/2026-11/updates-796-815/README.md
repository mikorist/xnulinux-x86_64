# CP796-815 research update

November 27, 2026. All 20 primary evidence hashes were verified. The Monterey retained-link reference remains CP602; newly admitted groups reproduce its exact 1,114-input executable on both hosts. Header qualification and controlled toolchain comparisons are not object admission or runtime qualification.

## CP796

Regenerated the original task declaration and seven OSFMK objects; 419 staged dependencies. 606 regenerated, 508 retained.

Primary evidence SHA256: `6fb2573197f77876d9d82ca8b41ab49b70ccd5b74cac1d81d4a2a78de3079feb`

## CP797

Regenerated the VM map declaration and five OSFMK objects; 391 staged dependencies. 611 regenerated, 503 retained. CP778-797 evidence integrity review completes, not technical closure.

Primary evidence SHA256: `a9de160f4ee6958d70137cd71bcb1e88576f17e385097a484eeac619744eac61`

## CP798

Three Mach declarations and six OSFMK objects match, with 405 dependency paths. 617 regenerated, 497 retained.

Primary evidence SHA256: `e9dd0a1771052cd4cce6ddfc1792dda9106c69cbc9aa338ff8f987ae1b85d512`

## CP799

Five Mach declarations and seven OSFMK objects match, with 428 dependency paths. 624 regenerated, 490 retained.

Primary evidence SHA256: `8ee6a6cf0eafd0a04ecdff5bed6ed8027daa689af45beea1f592db868d46ab9d`

## CP800

Reused independently generated CP776 host declaration for five objects and 384 dependencies. 629 regenerated, 485 retained. Ten-checkpoint series complete; oldest technical window remains HOLD.

Primary evidence SHA256: `5e569dd899bad4f612fdfb267b66124341815a0045c1b5967e3d22cf3e37a877`

## CP801

Original version generator produces the exact RELEASE header; three objects and 400 dependency paths match. 632 regenerated, 482 retained.

Primary evidence SHA256: `900dc187e966b599dc94368483b5f6b25dc9c51b9cab49e5d4512f915414c9e4`

## CP802

Four generated declarations and twelve objects match; 435 dependency paths. 644 regenerated, 470 retained.

Primary evidence SHA256: `3bb70ac8b039223550b397c906aeed36f48bdb2fedd0685ecbd3135cb154184f`

## CP803

Ten original preprocessed declarations and four objects match; 381 dependency paths. 648 regenerated, 466 retained.

Primary evidence SHA256: `a2e2d456744d0f121c1c0f829e28c88bd2539b4c948f1e4a66e4ae8f3d41aa91`

## CP804

Eleven original kernel-user declarations and five objects match; 406 dependency paths. 653 regenerated, 461 retained.

Primary evidence SHA256: `df7409698fab46ebbfdf6c92022c5e24fc041afc4abc03074090f0eb68267e6b`

## CP805

Sixteen kernel-server declarations and twenty objects match; 516 dependency paths. 673 regenerated, 441 retained.

Primary evidence SHA256: `6b53f52defbb13285acf16c4b3ecc1d207dd5a6d788567f93b5b7027b39bd2f4`

## CP806

Two additional declarations and three objects match; 421 dependency paths. All 209 Batch 02 candidates are accepted. 676 regenerated, 438 retained.

Primary evidence SHA256: `92e41da96f51a438bf713331aae336841b8a7e8dc502155bb690486692befe37`

## CP807

Two exported declarations and eight original BSD objects match; 593 dependency paths. 684 regenerated, 430 retained.

Primary evidence SHA256: `d2785020263b719f3b539f8774fb2c55a761fa4157a7e4683908573d7e24b754`

## CP808

Five RELEASE configuration declarations and one original object match; 335 dependency paths. A second object remains HOLD because ordered dependencies differ despite matching local objects. 685 regenerated, 429 retained.

Primary evidence SHA256: `a8d01f5ae796cb7ab4320836125e0ec0e2d185e8fe97eb01c2c3d678b4367c6b`

## CP809

Two original libkern C++ units match with 248 dependency paths. 687 regenerated, 427 retained.

Primary evidence SHA256: `481e2137b2c944d7d34c617d2744018d437db18e132aa8f4e06e40888dd59d56`

## CP810

Eight IOKit configuration headers and a configuration-guarded 680-byte C++ object match with nine dependency paths. 688 regenerated, 426 retained. No IOKit runtime qualification.

Primary evidence SHA256: `b271eb9c75bd330023be23c03ff4c65e25ef4940df2233c3cf7762b8a2296cf4`

## CP811

64 historical original C++ candidates identified among 116 retained C++ inputs. Six configuration headers match on both hosts, resolving 144 dependency occurrences in 24 candidates. All 64 remain HOLD on 22 derived paths; no new object admitted.

Primary evidence SHA256: `e947b2c3f719244613df6a8305994d1c6575625ae824eaedaf58b58c83e64480`

## CP812

Three exported MIG declarations match independently, resolving 159 occurrences across 53 candidates. 19 derived paths remain. No new object admitted.

Primary evidence SHA256: `9cd2f166834dfdd5733a1b8e703521dda7aa21243b95bd901c219b3c102ea742`

## CP813

Eight memory and compression assembly inputs preprocess identically. Four objects match historical bytes on both hosts; four differ at assembly and are excluded. 692 regenerated, 422 retained.

Primary evidence SHA256: `ed16ec814f900b05e37a0d2b1a706ad58d4c83b905f4dd1f69291d71b222934c`

## CP814

Explicit common Clang 24 backend produces matching results on both hosts for all eight inputs. Four still differ from historical Clang 19 output. Historical identity HOLD; no object admitted.

Primary evidence SHA256: `8a4483c821e6ff0f171bafcfc0cc3bbdfe401f8ac27d1b8edf32b1c480d73d65`

## CP815

One additional exported declaration from a pinned MIG definition matches historical bytes independently. 18 derived paths and 267 occurrences remain across 64 C++ candidates. No new object admitted. 692 regenerated, 422 retained.

Primary evidence SHA256: `1fffd7aea9c62f7727a3aeefb5b00cf0b05784d6817c89ca1ab493f6f3fed1ab`

## Remaining work

422 retained inputs, including 21 residual Batch 01 candidates. Batch 03 is not ready. Complete clean-source build, AMD admission, physical hosted runtime, full SDK/runtime, license and release remain HOLD. The last closed technical review is CP497. No portable batch-runner source or private build artifacts are included.
