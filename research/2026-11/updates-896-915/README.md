# CP896-915 research update

November 28, 2026. All 20 primary evidence hashes verified. CP896-915: accepted regenerated inputs increased from 1,012 to 1,050 of 1,114 (94.25%); 64 remain retained. Of the 1,050 regenerated inputs, 1,046 have independent source-stage evidence. Complete retained-input links match CP602 on both hosts. Scoped hosted userspace component and recovery regressions do not establish native XNU execution. AMD clock return and timer delivery, full clean-source build, hosted runtime, source licensing and release remain HOLD.

**A: Historical reproduction.** 1,050/1,114 regenerated inputs; 64 retained. This is CP602 byte identity, not product completion.

**B: Functional Monterey.** CP627 remains the Intel-model standalone owned Darwin PID 1 control. Actual AMD clock return, timer delivery and ordinary admission remain HOLD.

**C: Linux-hosted Monterey.** Primary architecture objective: bounded hosted kernel execution and dependable lifecycle/recovery, then a controlled project-owned Darwin program in that hosted context. CP899/900/911/912 are scoped userspace fixtures, not native hosted XNU. No execution architecture has been selected; A need not finish before eligible B/C work.

The public ARM64 FKI v0 header is a reference, not a qualified x86 ABI. Compare hosted execution models using compatibility, failure containment, maintainability, host ownership and existing evidence before choosing one; the historical shadow-CR3 proposal is a hypothesis. A versioned semantic host-service contract and version/vendor adapters are intended, not an implemented production interface.

The intended product runs on the same physical Intel or AMD CPU as its Linux host, without mandatory conventional VM or instruction emulation. Linux retains hardware ownership. Real GPU acceleration through qualified Linux graphics infrastructure and maximum practical measured performance are goals, not demonstrated capabilities. Desktop may be the primary fullscreen startup session; Headless and Seamless remain separate modes of the shared runtime. Prefer compact maintainable code, mature host services, measured memory and runtime cost, focused defect regressions and preserved negative evidence. Lossless distribution compression is separate from runtime optimization. No fixed performance ratio, universal device support, bug-free claim or new release gate.

## Chronological outcomes

### CP896

Seven IOKit header identities reconstructed independently; four original blobs and three reviewed historical patches. Source prerequisites only; object count unchanged.

Primary evidence SHA256: `eecb119ef5de9ae6254894ebdd07ba9ab9532680adda0faf4a12cc9f64f3a25d`

### CP897

Tests, IOKitDebug and IOStatistics independently compiled with 381, 399 and 384 ordered dependencies. Exact retained relink; 1,015 regenerated, 99 retained. Evidence window CP878-897 complete, not technically closed.

Primary evidence SHA256: `9e309311725159a81c248817e4db551c9d05904f3c36dc849c6fb2adaf918c32`

### CP898

Three IOKit callback sources and three exported headers match historical identities. Compile and runtime qualification still separate.

Primary evidence SHA256: `5463dbaa4f9368ebbca6dcfb9d8f9824209f10c79b0b7b365e400084ea6d85b4`

### CP899

Calendar adapter userspace regression: 1,260 projections and 630 rejection/output-preservation cases per host. Initial compatibility-header compile failure retained and test shim corrected. No live FKI or native bootstrap.

Primary evidence SHA256: `dfe541e7fd727b3bf74a643eaf372ba2d6a58fda658137dd2182128dc3712691`

### CP900

Original IPC registration function exercised in a userspace metadata fixture: 37 descriptors matched, 27 unused slots untouched per host. No callbacks or native IPC activation.

Primary evidence SHA256: `1af23c952288e549ef948ce2310257097474bd8d0733e8ef934663867abf03df`

### CP901

Three IOKit callback/continuation objects match from 429 distinct inputs; exact relink. 1,018 regenerated, 96 retained.

Primary evidence SHA256: `d62b1c68ffb0c87eb1f906ef6348f945be4733f79b454561addf2654bf909ea5`

### CP902

Six IOKit event/workloop objects match from 399 distinct inputs; exact relink. 1,024 regenerated, 90 retained. No new interrupt or timer runtime.

Primary evidence SHA256: `cb9cf3585d1766c02976a966e156aadd82a536fbb62baa8a17f74700656a3ce1`

### CP903

Five kernel MIG server objects match from 372 distinct inputs. Initial raw generator HOLD preserved; reversible date-comment restoration only. Exact relink; 1,029 regenerated, 85 retained. No RPC runtime.

Primary evidence SHA256: `86d012381d58d20ef10f9b9d0c2f65efd794da73d30969f0c9323f14624e33c3`

### CP904

Three IOKit BSD/platform-support objects match from 455 distinct inputs; exact relink. 1,032 regenerated, 82 retained.

Primary evidence SHA256: `a31b480d532f8afbfcdd00f3249a33c8c7964f9411689139b53c1be4485ef3f3`

### CP905

Two catalogue/test objects match from 405 distinct inputs; exact relink. 1,034 regenerated, 80 retained. No test execution; IIG format changes remain under review.

Primary evidence SHA256: `ed08b91a64093d06e48976c58b87ddb1e1bdd4072c5386d11115391e46097e46`

### CP906

Six historical AES/GCM/DES diagnostic objects match from 132 distinct inputs. Initial resource-header preflight failure corrected using qualified resource provenance. Exact relink; 1,040 regenerated, 74 retained. No runtime KAT or provider qualification.

Primary evidence SHA256: `1a3a4a5fbcc55570f9a69ac8c7293b4446781a38e47631ac1552e64f70b80bdb`

### CP907

Three historical crypto diagnostic/provider objects match from 147 distinct inputs; public fixture provenance checked, ten CTS vectors recomputed and two public signatures verified. Exact relink; 1,043 regenerated, 71 retained. No production cryptography claim.

Primary evidence SHA256: `862d1271b8b56287f6e8e854c78a22007836c89656efbdc4e4a0393d7f79ae7f`

### CP908

Two historical NetBSD DRBG/provider objects match from 224 distinct inputs. Malformed patch failure preserved; LF-only serialization retains original form feeds and notices. Exact relink; 1,045 regenerated, 69 retained.

Primary evidence SHA256: `18910f2c8b75b2593414ce034deb76e772b4ac3086443caef16845ea94c8b93d`

### CP909

Original SHA1 wrapper matches with 263 ordered dependencies; exact relink. 1,046 regenerated, 68 retained.

Primary evidence SHA256: `83e3fa069482fc3931f3c9fe6b1ff0abf53a58ac974cc0de6cc2a336e327a173`

### CP910

Historical XTS wrapper matches with 126 ordered dependencies; exact relink. 1,047 regenerated, 67 retained. Series CP901-910: 32 additional objects, ten material scoped advances, no parent HOLD closure; oldest window CP498-517 unchanged.

Primary evidence SHA256: `b317f52bb89518abd71e2d35f811c2cc1b7ce679e97135646d14ff5343c7b2dd`

### CP911

CP397 entry rebuilt as an ELF userspace harness using ordinary Linux process transport and real time/random services. Two normal completions, one refusal, three children reaped, no net descriptor leak per host. Unbounded wait/recovery limitation remains; no XNU or Mach-O execution.

Primary evidence SHA256: `345947f249dbbbb77b7accda7a50e2802c5fd2a313cd89b9294bdeebffb1842f`

### CP912

Separate harness regression addresses bounded waits and owned-child cleanup. Three normal completions, one refusal, one early exit, two deliberate stalls, seven children reaped, zero net descriptor leak and no UBSan diagnostics per host. Not native kernel recovery or production supervision.

Primary evidence SHA256: `42f38bf220c43f7c2f11bdccd4c18e50c1e6b111e52af92bf675632b34bb9020`

### CP913

Historical GSS wrapper matches with 443 ordered dependencies. Initial compile failure from wrong historical recipe preserved; successful recorded recipe restores include path. Exact relink; 1,048 regenerated, 66 retained.

Primary evidence SHA256: `c51f154f57f15f2c650340f326eaee154a8b38391fdf9a1a6d0f67b067478e76`

### CP914

Original MAC file object matches with 311 ordered dependencies. Incorrect initial configuration provenance assumption rejected; CP808 proof used. Exact relink; 1,049 regenerated, 65 retained. No security runtime qualification.

Primary evidence SHA256: `ff06cc5bab6abb9c1c7522873f862b3053ab668ae010a1321706e3bb4b56ac34`

### CP915

Historical standalone VFS diagnostic object matches with 454 ordered dependencies, using reviewed cumulative source diff. Exact relink; 1,050 regenerated, 64 retained. No new mount, HFS or hosted runtime.

Primary evidence SHA256: `5f892366a70dc59bbe25f81557d02e7992946f3232d2da87aac3b6f9c9f6d166`

## Next work

Prioritize eligible native hosted and AMD functional prerequisites; continue independent historical reproduction, license and SDK work. Tahoe preparation remains active, with implementation gated on stable physical Linux-hosted Monterey Intel execution. Golden Gate is research only. CP498-517 remains the oldest open technical review. No new source, binary, release or technical closure accompanies this report.
