# Integrating Intel documentation and source

The Intel repository retains its upstream Git history. The original ARM implementation is preserved at [arm64-reference](https://github.com/mikorist/xnulinux-x86_64/tree/arm64-reference); the active Intel branches are main and x86_64-port. The [repository history](../../research/2026-11/history/intel-repository-separation.md) records the cleanup. Retained graphics and mixed components are not automatically qualified for Intel.

Review the actual target branch before each integration. Use separate branches or worktrees, preserve original license and attribution notices, select concrete source and test files, review the diff, and verify relevant results. Do not copy private research trees, raw logs, restricted files or generated binaries. Do not overwrite another contributor's work or force-push.

After each development series of 20 significant research checkpoints, integrate independently qualified source, tests and documentation. Hold unresolved components with a specific reason. Public commits are not releases. Tags, releases and upstream pull requests remain separate maintainer decisions. See [publication workflow](publication-workflow.md).
