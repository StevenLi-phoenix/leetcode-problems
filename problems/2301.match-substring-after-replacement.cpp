// @leetcode id=2301 questionId=2393 slug=match-substring-after-replacement lang=cpp site=leetcode.com title="Match Substring After Replacement"
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        bool canBecome[128][128] = {false};
        for (int c = 0; c < 128; c++) canBecome[c][c] = true;
        for (auto& m : mappings) canBecome[(int)m[0]][(int)m[1]] = true;

        int n = s.size(), m = sub.size();
        for (int start = 0; start + m <= n; start++) {
            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (!canBecome[(int)sub[j]][(int)s[start + j]]) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }

        return false;
    }
};
