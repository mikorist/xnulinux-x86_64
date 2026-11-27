# AI-assisted development: tooling interruption and support escalation

November 26, 2026. Maintainer-reported incident, documented on November 27. This is a historical account of an external development-tool interruption, not an evaluation of OpenAI's internal safety systems.

During legitimate open-source XNU kernel development in ChatGPT, repeated cyber-safety messages interrupted the maintainer's workflow. Kernel engineering naturally involves low-level CPU state, memory-management semantics, interrupts, and execution-context transitions; the work is conducted within the project's documented isolation, authorization and host-ownership boundaries.

The maintainer contacted OpenAI Support on November 26 and supplied the relevant prompt, warning text, screenshot and development-environment details. Support acknowledged the interruption and stated that the case would be forwarded for review with the supplied materials. It noted that reducing the working context was impractical and did not require those materials to be resent. At that point support had not confirmed whether the messages had been triggered in error or whether a change was appropriate.

Later the same day, the maintainer reported that the previous slowdown was no longer occurring. This observation does not establish causation, a policy exemption, a confirmed classification error, or permanent resolution. The exact original banner and screenshot were not available for this retrospective. The case identifier and other private correspondence are retained outside the public repository.

The incident illustrates why tooling problems should be recorded separately from compiler, linker, observer and runtime failures. The project continues to judge technical results by actual evidence. Safety and host-ownership requirements remain unchanged; no restriction bypass is part of the development method.

See [AI-assisted development](../../../AI-METHODOLOGY.md) and [engineering history](engineering-history-through-612.md).
