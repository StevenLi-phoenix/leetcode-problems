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

# ── 1. Fetch ALL problems from LeetCode ──────────────────────────────────────
ansi    = re.compile(r'\x1B\[[0-9;]*m')
row_pat = re.compile(r'^\W*(\d+)\s+(Easy|Medium|Hard)\s+')

result = subprocess.run(
    ["leetcode", "list", "-n", "5000"],
    capture_output=True, text=True,
)
diff_map: dict[int, str] = {}
for line in result.stdout.splitlines():
    m = row_pat.match(ansi.sub("", line))
    if m:
        diff_map[int(m.group(1))] = m.group(2)

# ── 2. Build flat char array indexed by problem ID ────────────────────────────
code = {"Easy": "E", "Medium": "M", "Hard": "H"}
max_id = max(diff_map)
entries = ["0"] * (max_id + 1)   # index 0 unused
for fid, diff in diff_map.items():
    entries[fid] = f"'{code[diff]}'"

table = "".join(f"    {e},\n" for e in entries)

# ── 3. Splice new table into gen-readme.cpp ───────────────────────────────────
src = CPP.read_text()
pattern = r'(// ── difficulty table[^\n]*\n// clang-format off\nstatic const char DIFF\[\] = \{)\n.*?(// clang-format on)'
if not re.search(pattern, src, re.DOTALL):
    print("ERROR: could not find DIFF[] table in gen-readme.cpp", file=sys.stderr)
    sys.exit(1)
new_src = re.sub(
    pattern,
    lambda m: m.group(1) + "\n" + table + "};\n" + m.group(2),
    src,
    count=1,
    flags=re.DOTALL,
)

CPP.write_text(new_src)
print(f"Updated gen-readme.cpp (max id {max_id}, {len(diff_map)} entries)")

# ── 4. Recompile ─────────────────────────────────────────────────────────────
subprocess.run(
    ["c++", "-std=c++17", "-O2", "-Wall", "-o", str(SCRIPTS / "gen-readme"), str(CPP)],
    check=True,
)
print("Recompiled gen-readme")
