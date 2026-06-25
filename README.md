# leetcode-problems

My LeetCode solutions, managed with [leetcode-cli](https://github.com/StevenLi-phoenix/leetcode-cli) (lives at `~/Codes/leetcode-cli`).

## Layout

```
problems/{id}.{slug}.{ext}
```

e.g. `problems/1.two-sum.cpp`. The first line of every file is a metadata header comment:

```cpp
// @leetcode id=1 questionId=1 slug=two-sum lang=cpp site=leetcode.com title="Two Sum"
```

That header is how `leetcode test`/`leetcode submit` recover the problem — **keep it on line 1** and don't rename files by hand.

## Workflow

The CLI is configured to use this directory as its workdir (`leetcode config workdir`), with **C++** as the default language. From anywhere:

```bash
leetcode show 1            # read the statement
leetcode pick 1            # generate problems/1.two-sum.cpp here
# …solve it in your editor…
leetcode test 1            # run the example cases
leetcode submit 1          # submit to the judge
```

Browse and discover:

```bash
leetcode list -d medium -t dynamic-programming
leetcode daily
leetcode random -d easy
leetcode timer 1           # interview-style countdown
```

## Versioning

Plain git — commit solutions as you go. `leetcode snapshot save/diff/restore <id>` also keeps local in-CLI versions if you want quick rollbacks while iterating.

## Notes

- Credentials are **not** stored here — they live in the CLI's own config (`leetcode login`).
- Premium-only and database problems may lack a C++ snippet; `pick` will list the available languages.
