# Integrating x86_64 documentation and source

The x86_64 repository retains its upstream Git history. The original ARM implementation is preserved at [arm64-reference](https://github.com/mikorist/xnulinux-x86_64/tree/arm64-reference); the active x86_64 branches are main and x86_64-port. The [repository history](../../research/2026-11/history/intel-repository-separation.md) records the cleanup. Retained graphics and mixed components are not automatically qualified for either CPU vendor.

Review the actual target branch before each integration. Use separate branches or worktrees, preserve original license and attribution notices, select concrete source and test files, review the diff, and verify relevant results. Do not copy private research trees, raw logs, restricted files or generated binaries. Do not overwrite another contributor's work or force-push.

Every 20 significant research checkpoints, review independently qualified source and tests. Publish reviewed chronological outcomes separately as they become available, including failed or incomplete results, and reconcile the [current state](../../PROJECT-STATE.json) and status documents. Hold unresolved components with a specific reason. Public commits are not releases. Tags, releases and upstream pull requests remain separate maintainer decisions. See [publication workflow](publication-workflow.md).
