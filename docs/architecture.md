# Target architecture

The x86_64 port targets physical Intel Linux hosts. QEMU is a development and regression environment, not a required production layer.

```mermaid
flowchart TD
    H[Headless] --> R[Shared Darwin runtime]
    D[Desktop] --> R
    S[Seamless applications] --> R
    R --> X[XNU x86_64]
    X --> L[xnu.ko / hosted execution]
    L --> F[fki.ko / host interface]
    F --> K[Linux x86_64 kernel]
    N[Linux applications] --> K
    K --> P[Physical Intel hardware]
```

*Proposed architecture, not a demonstrated end-to-end implementation.*

## Source versions

| Architecture | XNU baseline |
| --- | --- |
| x86_64 | 8020.140.41 (Monterey 12.5) |
| ARM64 | Upstream 12377.121.6 |

Independent source pins, build configurations and patch series are intentional. The shared FKI contract requires explicit version compatibility.

## Execution modes

Headless execution targets a minimal open Darwin runtime. Desktop mode targets a compatible complete graphical environment. Seamless mode additionally requires a real Linux window, compositor, input and focus integration layer, not merely hiding the macOS desktop.

## Boundaries

Linux owns host resources. CPU state, memory, exceptions, interrupts, SMP and module lifecycle require independent hosted qualification. Standalone boot evidence cannot substitute for these tests.

The APSL and GPL components retain their existing license separation. Proprietary frameworks remain separate dependencies, subject to their applicable licenses.
