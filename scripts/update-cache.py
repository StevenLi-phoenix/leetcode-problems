#!/usr/bin/env python3
"""Refresh scripts/difficulty.csv from LeetCode (run manually, not in pre-commit)."""
import re
import subprocess
from pathlib import Path

OUT = Path(__file__).parent / "difficulty.csv"
ansi = re.compile(r'\x1B\[[0-9;]*m')
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
OUT.write_text("\n".join(f"{fid},{diff}" for fid, diff in rows) + "\n")
print(f"Updated {OUT} ({len(rows)} entries)")
