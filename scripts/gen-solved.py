#!/usr/bin/env python3
"""Regenerate README.md with solved-problems table from local problems/ + leetcode list."""
import os
import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).parent.parent
PROBLEMS = ROOT / "problems"
OUT = ROOT / "README.md"

hdr_pat = re.compile(r'id=(\d+).*?slug=([\w-]+).*?lang=(\w+).*?site=([\w.]+).*?title="([^"]+)"')
ansi = re.compile(r'\x1B\[[0-9;]*m')
list_pat = re.compile(r'^[✔✖]\s+(\d+)\s+(Easy|Medium|Hard)\s+')

# 1. Parse local files
local: dict[int, dict] = {}
for fname in os.listdir(PROBLEMS):
    first = (PROBLEMS / fname).open().readline().strip()
    m = hdr_pat.search(first)
    if m:
        fid, slug, lang, site, title = m.groups()
        local[int(fid)] = dict(id=fid, slug=slug, lang=lang, site=site,
                               title=title, file=fname)

# 2. Fetch difficulty for all solved problems in one call (CLI paginates internally)
diff_map: dict[int, str] = {}
result = subprocess.run(
    ["leetcode", "list", "--status", "solved", "-n", "5000"],
    capture_output=True, text=True,
)
for line in result.stdout.splitlines():
    clean = ansi.sub("", line)
    lm = list_pat.match(clean)
    if lm:
        diff_map[int(lm.group(1))] = lm.group(2)

BADGE = {"Easy": "🟢 Easy", "Medium": "🟡 Medium", "Hard": "🔴 Hard"}
LANG = {"cpp": "C++", "py": "Python", "java": "Java", "ts": "TypeScript",
        "go": "Go", "rs": "Rust", "kt": "Kotlin"}

easy   = sum(1 for fid in local if diff_map.get(fid) == "Easy")
medium = sum(1 for fid in local if diff_map.get(fid) == "Medium")
hard   = sum(1 for fid in local if diff_map.get(fid) == "Hard")

lines = [
    "# leetcode-problems\n",
    "My LeetCode solutions, managed with [leetcode-cli](https://github.com/StevenLi-phoenix/leetcode-cli).\n",
    f"**{len(local)} solved** — 🟢 {easy} Easy · 🟡 {medium} Medium · 🔴 {hard} Hard\n",
    "| # | Title | Difficulty | Lang |",
    "|---|-------|------------|------|",
]
for fid in sorted(local):
    info = local[fid]
    url = f"https://{info['site']}/problems/{info['slug']}/"
    diff = BADGE.get(diff_map.get(fid, ""), "—")
    lang = LANG.get(info["lang"], info["lang"].upper())
    lines.append(
        f"| [{info['id']}]({url}) "
        f"| [{info['title']}](problems/{info['file']}) "
        f"| {diff} | {lang} |"
    )

OUT.write_text("\n".join(lines) + "\n")
print(f"Written {OUT} ({len(local)} problems)")
