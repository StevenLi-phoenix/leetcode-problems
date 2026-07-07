# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/).

## [Unreleased]

### Added
- Solved and committed 59 problems on 2026-07-06 via the recurring solve loop (README now lists 1077 problems). Batch 1 (补欠款 sequential batch, ~12:38–13:11): 2311, 3745, 2831, 1838, 953, 2251, 2500, 853, 520, 1931, 2558, 312, 46, 3275, 1799, 3342, 1359, 872, 2356 (MySQL), 1006, 3110, 972, 3397, 1577, 2441, 2968. Batch 2 (15-min cron loop, ~13:20–21:20): 3373, 1023, 975, 1302, 3210, 3685, 3421 (MySQL), 1397, 1080, 3915, 282, 3791, 2829, 726, 2611, 385, 214, 1760, 3903, 394, 207, 2712, 707, 3679, 2073, 2368, 2191, 1413, 2164, 3241, 204, 2707, 117, 1114 (concurrency), 1527 (MySQL), 747, 950. Notable: 1397 数位DP+KMP自动机, 3915 值域线段树+延迟插入, 3241 re-rooting DP, 1931 列状态DP, 312 区间DP, 975 单调栈, 2968 中位数滑窗.
  Files: problems/*.cpp, problems/*.sql, README.md

### Fixed
- 3791 first submission hit Memory Limit Exceeded with nested `vector<vector<vector<>>>` memo; flattened to a single 1-D array with manual indexing and resubmitted successfully.
  Files: problems/3791.number-of-balanced-integers-in-a-range.cpp

### Changed
- Replaced the stale once-daily cron loop (artifact of the earlier false Cloudflare-block backoff) with a fresh 15-minute session cron "finish one leetcode problem"; also re-authenticated the leetcode-cli session after a genuine session expiry mid-loop (cookies passed via shell substitution, never read into context).
  Files: (session state only — no repo files)

### Known issues / deferred
- 3235 (Check if the Rectangle Corner Is Reachable) remains unsolved as an untracked file: circle-circle DSU merge outside the rectangle needs true lens-vs-rectangle intersection testing.
- 3848 (Check Digitorial Permutation) remains an untracked stub.
  Files: problems/3235.check-if-the-rectangle-corner-is-reachable.cpp, problems/3848.check-digitorial-permutation.cpp
