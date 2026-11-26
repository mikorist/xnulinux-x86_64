# IIG and Monterey IORPC compatibility

**Date:** 2026-11-25  
**Scope:** Generator, compile probes and host fixtures; checkpoints 36–62.

The portable DriverKit-440 generator initially failed all 17 interfaces in the reconstructed parser environment. A temporary kernel-header prelude resolved the missing type context without permanently defining KERNEL during interface parsing. All 17 headers and implementations were then generated.

The newer generator assumed a kernelContent field absent from Monterey's four-field IORPC structure. The adaptation retained the original ABI and investigated ordinary messages and reply-reuse paths separately. Three annotated by-value Mach port parameters were initially misclassified by the newer generator; the correction was scoped to those annotated parameters.

Measured layouts exposed a four-byte versus eight-byte alignment mismatch. Generated adapters were progressively audited using byte-safe access, typed callbacks and fixture tests. This work does not establish the correctness of the complete live transport.

| Milestone | Result |
| --- | --- |
| Initial generation | 17/17 |
| Initial compile probes | 11/112 |
| Generated implementations at checkpoint 49 | 17/17 |
| All configured component artifacts at checkpoint 62 | 984/984 |
| Independent C++ probes at checkpoint 62 | 115 |

The 984 total comprised 869 accepted compatibility objects and 115 independent probes before diagnostic integration.

## Remaining gates

The IOUserServer transport retained conditional alignment assumptions. Live RPC, rights ownership, cleanup, class ABI, raw interrupt callbacks and remote reply reuse require separate qualification. Compilation and host mock fixtures are not equivalent to the original Apple generator or a full live ABI test.
