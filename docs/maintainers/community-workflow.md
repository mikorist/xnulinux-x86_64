# Community collaboration

The x86_64 port is developed in a fork of AFK-surf/xnulinux. Participation in the fork does not imply endorsement or maintenance by the original project.

## Discussions

Use English for public technical discussion. Keep each issue focused on an observable problem, a documented result or a concrete research question. The existing upstream [x86_64 discussion](https://github.com/AFK-surf/xnulinux/issues/10) is historical project context, not a substitute for issue tracking in the fork.

## Sharing progress

A useful milestone update contains:

- The source and project revisions.
- The tested execution scope.
- What actually succeeded.
- What failed or is still blocked.
- A link to the reviewed public report.

Avoid repeating a stream of intermediate diagnostic images in upstream discussions. Preserve useful failures in the research journal.

## Coordinating work

Identify the owner of each task and use separate worktrees for concurrent changes. Notify the maintainer before work crosses shared ABI, build, license or architecture boundaries. Prefer independent verification before integrating a significant result.

The maintainer decides when a change is ready for the fork and when a self-contained contribution is appropriate for upstream.
