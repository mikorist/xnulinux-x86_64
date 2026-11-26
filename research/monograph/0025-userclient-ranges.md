# 25. IOUserClient range and asynchronous completion boundaries

**Date:** 2026-11-25  
**Source checkpoint:** 46 (R0025)  
**Scope:** Generated unit compilation and host fixtures.

The pinned nested KernelCompletion action derives from OSAction and routes to the shared AsyncCompletion invoker. The adapter preserves redirected IDs, action metadata checks and one-way semantics, without inventing task or memory-map policy.

The range prototype checks a count of 1 through 32, unsigned address-plus-length and cumulative-length overflow. Zero-length individual ranges are not prohibited. Scalar and asynchronous arrays have a maximum of 16 entries; returned counts are checked against captured capacity before copying. OOL descriptors retain the existing virtual-copy placeholders, not presumed transport addresses. Ownership after malformed successful returns remains unresolved.

Ten compiler-measured wire types, 30 layout assertions and four supplementary array assertions were used. The first adapter stopped before compile because it selected the wrong AsyncCompletion overload. After correcting selection, the full TU compiled on the first actual attempt with unchanged warning policy.

IOUserClient.iig.cpo: 266,536 bytes; SHA-256 `ac61297441c1300583e63cd3bbe1cd52c45c2fbe6031352449e64c7dd97d79d6`.

The extracted actual range and entitlement invokers plus external-method and async preflight prefixes passed 60 checks. The measured range request/reply were 620/84 bytes, external method 340/228, async request 260. Fixtures covered full 64-bit range fields, count and arithmetic bounds, descriptor order, output identity and redirected completion with no reply. No real allocation, authorization decision, serialization or live callback occurred.

Full-TU IR supported the inherited IOService and nested OSAction dispatch paths. The manifest reached 80 independent probes, 14 generated units and 949/984 total artifacts; 35 missing. Accepted 869 inputs and 261 undefined remained unchanged. Live metadata and ownership remain separate gates.
