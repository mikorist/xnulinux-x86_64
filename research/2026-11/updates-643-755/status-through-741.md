# Research status through CP741

This historical snapshot follows the CP642 public research snapshot and covers CP643-741, including unsuccessful attempts and outstanding dependencies. Monterey 12.5 is the active reference; Tahoe 26.5 remains source research only.

## Main results

| Area | Recorded result | Boundary |
| --- | --- | --- |
| Monterey kernel reconstruction | CP700: 95 regenerated and 1,019 retained inputs; exact CP602 executable | Not a complete clean-source build |
| Source dependency stage | CP699: 91 units, 896 paths | Retained compiler and previously generated inputs |
| PureDarwin graphics | CP661: nine frameworks inventoried; CP680 and CP689 scoped offscreen fixtures | No working full framework, desktop or hardware acceleration |
| Versioned SDK | CP737: 240-header candidate | Partial declarations only |
| Open runtime | CP717: Blocks relocatable object, eight unresolved imports; CP739: six generic string objects, zero imports | No dynamic library or runtime execution |
| Compiler | CP727: complete patched Ryzen compiler and scoped regression | Independent Intel candidate qualification remains open in this snapshot |
| Research tools | CP741: 229 successful checks per host | Full cross-host binary identity, attribution and release remain open |

The ordinary standalone owned Darwin PID 1 result from CP627 remains the established Intel-model reference. Complete AMD boot, physical hosted XNU, full runtime, framework licensing and clean-source build remain unqualified. An exact retained link does not establish a new runtime result.

## Editorial and integration boundaries

Publication of these research outcomes does not require every experiment to succeed. It does require a faithful account of the evidence and unresolved limitations. This update includes no source patches, binaries, logs, private paths or proprietary assets. The complete technical review through CP497 remains the last closed regular review. CP741 is an observed journal record, not a new closed review window.

For subsequent results see the [CP755 status summary](status-summary.md). Technical, license and release requirements remain separate.
