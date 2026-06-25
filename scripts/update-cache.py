#!/usr/bin/env python3
"""
Refresh difficulty data embedded in gen-readme.cpp, then recompile.

Usage: python3 scripts/update-cache.py   (or: make update-cache)
"""
import re
import subprocess
import sys
from pathlib import Path

SCRIPTS = Path(__file__).parent
CPP     = SCRIPTS / "gen-readme.cpp"

# ── 1. Fetch solved list from LeetCode ───────────────────────────────────────
ansi    = re.compile(r'\x1B\[[0-9;]*m')
row_pat = re.compile(r'^[✔✖]\s+(\d+)\s+(Easy|Medium|Hard)\s+')

result = subprocess.run(
    ["leetcode", "list", "--status", "solved", "-n", "5000"],
    capture_output=True, text=True,
)
rows: list[tuple[int, str]] = []
for line in result.stdout.splitlines():
    m = row_pat.match(ansi.sub("", line))
    if m:
        rows.append((int(m.group(1)), m.group(2)))
rows.sort()

code = {"Easy": "E", "Medium": "M", "Hard": "H"}
table_lines = [f"    {{{fid}, '{code[diff]}'}},\n" for fid, diff in rows]
table = "".join(table_lines)

# ── 2. Splice new table into gen-readme.cpp ───────────────────────────────────
src = CPP.read_text()
new_src = re.sub(
    r'(// ── difficulty table.*?static const struct \{[^}]+\} DIFF\[\] = \{)\n.*?(\};)',
    lambda m: m.group(1) + "\n" + table + m.group(2),
    src,
    count=1,
    flags=re.DOTALL,
)
if new_src == src:
    print("ERROR: could not find DIFF[] table in gen-readme.cpp", file=sys.stderr)
    sys.exit(1)

CPP.write_text(new_src)
print(f"Updated gen-readme.cpp ({len(rows)} difficulty entries)")

# ── 3. Recompile ─────────────────────────────────────────────────────────────
subprocess.run(
    ["c++", "-std=c++17", "-O2", "-Wall", "-o", str(SCRIPTS / "gen-readme"), str(CPP)],
    check=True,
)
print("Recompiled gen-readme")
