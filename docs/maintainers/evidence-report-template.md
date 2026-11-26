# Reproduction report template

## Identity

| Field | Value |
| --- | --- |
| Date | |
| Project commit | |
| XNU revision | |
| Configuration | |
| Compiler, assembler, linker | |
| Host OS and kernel | |
| Physical CPU or emulated model | |
| Execution scope | |
| Relevant prior checkpoint | |

## Question and acceptance criteria

Define an observable result and the stopping boundary before conducting the test.

## Inputs

Record source origins, immutable revisions, fixture provenance, artifact sizes and SHA-256 values. Do not include restricted material or secret data.

## Reproduction

List exact commands, dependencies, build flags and expected output. Identify unavailable inputs explicitly.

## Observations

Record exit status, actual guest or host behavior, verifier assertions, negative cases and exceptions. Distinguish a successful diagnostic capture from successful execution.

## Conclusion

State what the test demonstrates, what it does not demonstrate, and the next unresolved question.

## Review

Record the reviewer, review scope and references. Public evidence must be sanitized; do not attach unfiltered sensitive traces.
