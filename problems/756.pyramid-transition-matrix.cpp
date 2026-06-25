// @leetcode id=756 questionId=757 slug=pyramid-transition-matrix lang=cpp site=leetcode.com title="Pyramid Transition Matrix"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // key: pair (a,b) encoded to 0..35, value: bitmask of possible tops (6 bits for A..F)
    int trans[36];
    unordered_map<string, bool> memo;

    bool dfs(const string& row) {
        if (row.size() == 1) return true;
        if (auto it = memo.find(row); it != memo.end()) return it->second;

        int n = (int)row.size();
        string nextRow(n - 1, '?');

        function<bool(int)> build = [&](int i) -> bool {
            if (i == n - 1) {
                return dfs(nextRow);
            }
            int a = row[i] - 'A';
            int b = row[i + 1] - 'A';
            int key = a * 6 + b;
            int mask = trans[key];
            if (mask == 0) return false;

            for (int t = 0; t < 6; t++) {
                if (mask & (1 << t)) {
                    nextRow[i] = char('A' + t);
                    if (build(i + 1)) return true;
                }
            }
            return false;
        };

        bool ok = build(0);
        memo[row] = ok;
        return ok;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        memset(trans, 0, sizeof(trans));
        memo.clear();

        for (const string& s : allowed) {
            int a = s[0] - 'A';
            int b = s[1] - 'A';
            int c = s[2] - 'A';
            trans[a * 6 + b] |= (1 << c);
        }

        return dfs(bottom);
    }
};
