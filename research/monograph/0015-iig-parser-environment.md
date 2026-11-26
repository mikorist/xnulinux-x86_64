# 15. Recovering the IIG parser environment

**Date:** 2026-11-25  
**Source checkpoint:** 36 (R0015)  
**Scope:** Generator and independent compile probes; accepted link unchanged.

The portable DriverKit-440 generator was pinned to ea6d147d668ca15d490da638012243fcd705f30d, with an existing 77-line Linux/Darwin adaptation. Its binary SHA-256 was `c2bb4f774365f9d90c6d217d19f878cf4c58ae9ab0b1ab0094059fa86d10be8f`, linked against libclang 19. The reference XNU remained 8020.140.41.

## Recovering the parser context

Seventeen original IIG recipes were extracted from the build dry-run. They selected C++17, __IIG, DRIVERKIT_PRIVATE, PRIVATE_WIFI_ONLY and PLATFORM_MacOSX, without a global KERNEL definition. The portable executable and explicit x86_64 Darwin target were substituted deliberately.

The original-flags attempt generated 0/17 interfaces because the user-space SDK symbol-aliasing header was missing. Adding KERNEL globally also generated 0/17: required user-style declarations disappeared and the annotation named KERNEL conflicted.

A parser-only prelude temporarily defined KERNEL while including the real integer, size, Mach port and DriverKit return type headers, then removed that definition before parsing the interfaces. This preserved user-style declarations and annotations without inventing types or claiming a complete Apple SDK.

The local generate-prelude.py run generated all 17 headers and 17 implementations, all exits zero and stderr empty. Headers were not exported into the live root.

## Compile and ABI findings

The compile-probe.py replay used 95 ordinary consumers and 17 generated implementations; 11 passed, 101 failed. No missing-header or detected frontend-crash diagnostics remained. Ninety-six targets had void-pointer indirection errors and all 17 generated units referenced kernelContent, a field absent from Monterey IORPC. These groups overlapped.

The 11 successful objects were OSObject, OSArray, OSBoolean, OSCollection, OSCollectionIterator, OSDictionary, OSIterator, OSNumber, OSOrderedSet, OSSet and OSString. They remained unaccepted.

Monterey IORPC contains message, reply, sendSize and replySize. The newer generator assumed a different layout. The original IOUserServer uses IORPCMessageFromMach to locate content following descriptors. Adding the newer field to the pinned structure would not establish compatibility.

The accepted 869-object link retained 261 undefined symbols. Original recipes, generator outputs, per-target hashes, stderr and symbol tables remain local. No live ABI, kernel execution or final link was established.
