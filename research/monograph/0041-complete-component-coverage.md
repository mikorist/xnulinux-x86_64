# 41. Complete component coverage and conditional integration

**Date:** 2026-11-25
**Source checkpoint:** 62 (R0041)
**Scope:** All configured objects available; no accepted final executable.

The final two units were IOPMrootDomain and IOUserServer. The root-domain build retained the earlier power producer candidate. Preparation corrections included the actual count of 23 sysctl registrations rather than 24. Their 46 relocations and original ranks were preserved; power transitions, callback identity and request lifetime were not tested.

IOUserServer compiled with its original wire declarations retained, but the actual parser and typed access alignment evidence exposed an unresolved mismatch. The report treated this strictly as a conditional compile probe. It did not change the wire protocol or assert that hardware tolerance established compiler-language correctness. Descriptor bounds, rights, ownership, cleanup and transport remained open.

The native fixture exercised four root-adapter calls and five parser cases with zero errors, confirming the observed alignment concern without claiming live RPC execution. The two objects were 1,366,616 and 859,872 bytes.

All 115 separate probes were now verified, so 869 accepted inputs plus 115 probes accounted for 984/984 configured artifacts. Static name inventory found 221 of the 261 baseline undefined names with one candidate provider each, 40 without a provider and no multiple probe providers. That was not yet actual symbol resolution. The next experiment would be a separate diagnostic relocatable link.

Historical source-record SHA256: `25ce8defce65e3bbc0173efd84a740ab1fabe9922b2642e86c0286f9f19ae5e1`. The original experiment and evidence remain in the private research archive. This account is a documented historical result, not a new replay.
