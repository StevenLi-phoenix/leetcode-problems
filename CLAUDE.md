# CLAUDE.md — leetcode-problems

This repo holds my LeetCode solutions, driven by the **leetcode-cli** tool (source at `~/Codes/leetcode-cli`; the `leetcode` / `leetcode-cli` commands are on PATH via `~/.local/bin`).

## Conventions

- **Default language is C++ (`cpp`).** Write new solutions in C++ unless I ask otherwise.
- **File layout:** `problems/{id}.{slug}.{ext}` — a flat `problems/` directory, e.g. `problems/1.two-sum.cpp`. Do not nest by difficulty/category.
- **Metadata header:** every solution's first line is a comment like
  `// @leetcode id=1 questionId=1 slug=two-sum lang=cpp site=leetcode.com title="Two Sum"`.
  It lets `leetcode test`/`submit` resolve the problem. **Keep it on line 1; never edit or remove it,** and don't rename files by hand (use `leetcode pick`).

## Workflow

```bash
leetcode show <id>      # read the problem (use the frontend number or slug)
leetcode pick <id>      # scaffold problems/<id>.<slug>.cpp (writes the header + starter)
#   …implement in the file…
leetcode test <id>      # run example cases against the judge
leetcode submit <id>    # submit; expect "Accepted"
```

- `test`/`submit` take an id, a slug, or a file path. By id they find the file via the CLI's manifest or the conventional path above.
- Use `leetcode test <id> -c '<input>'` for a custom case (input lines, `\n`-separated).
- `leetcode list`, `leetcode daily`, `leetcode random`, `leetcode hint <id>` help with discovery.

## Browsing & discovery

```bash
leetcode list -d medium -t dynamic-programming
leetcode list --status unsolved -d hard   # filter by solve status
leetcode random --status unsolved         # random unsolved problem
leetcode random --status unsolved -d hard # random unsolved hard
leetcode daily
leetcode timer <id>    # interview-style countdown
```

## Versioning

Plain git — commit solutions as they're solved. `leetcode snapshot save/diff/restore <id>` keeps local in-CLI versions for quick rollbacks while iterating.

A **pre-commit hook** (`scripts/gen-solved.py`) auto-regenerates `README.md` with the solved-problems table on every commit.

## Rules for working here

- **Never put credentials in this repo.** The session cookie lives in the CLI's own config (`leetcode login`), not here. Don't read or echo it.
- Don't refactor the CLI from this repo — that's a separate project at `~/Codes/leetcode-cli`.
- Commit solutions with plain git as they're solved. Keep commits scoped to one problem where practical.
- If a problem has no C++ snippet (e.g. database/premium problems), `pick` will list the available languages — pick an appropriate one and note it.
