// @leetcode id=3983 questionId=4346 slug=subsequence-after-one-replacement lang=cpp site=leetcode.com title="Subsequence After One Replacement"
class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), nt = t.size();
        const int INF = nt + 1;

        // nextOcc[i][c] = smallest index >= i in t with that char, or nt if none.
        vector<array<int,26>> nextOcc(nt + 1);
        nextOcc[nt].fill(nt);
        for (int i = nt - 1; i >= 0; i--) {
            nextOcc[i] = nextOcc[i + 1];
            nextOcc[i][t[i] - 'a'] = i;
        }
        // prevOcc[i][c] = largest index <= i in t with that char, or -1 if none.
        vector<array<int,26>> prevOcc(max(nt, 1));
        if (nt > 0) {
            prevOcc[0].fill(-1);
            prevOcc[0][t[0] - 'a'] = 0;
            for (int i = 1; i < nt; i++) {
                prevOcc[i] = prevOcc[i - 1];
                prevOcc[i][t[i] - 'a'] = i;
            }
        }

        // prefix[i] = t-index just past the greedy match of s[0..i).
        vector<int> prefix(n + 1);
        prefix[0] = 0;
        for (int i = 0; i < n; i++) {
            if (prefix[i] >= nt) { prefix[i + 1] = INF; continue; }
            int pos = nextOcc[prefix[i]][s[i] - 'a'];
            prefix[i + 1] = (pos == nt) ? INF : pos + 1;
        }
        if (prefix[n] <= nt) return true; // already a subsequence, no replacement needed

        // suffix[i] = t-index of the greedy (rightmost-first) match start for s[i..n).
        vector<int> suffix(n + 1);
        suffix[n] = nt;
        for (int i = n - 1; i >= 0; i--) {
            if (suffix[i + 1] <= 0) { suffix[i] = -1; continue; }
            int pos = prevOcc[suffix[i + 1] - 1][s[i] - 'a'];
            suffix[i] = pos;
        }

        for (int i = 0; i < n; i++) {
            if (prefix[i] > nt) continue;
            if (suffix[i + 1] == -1) continue;
            if (prefix[i] < suffix[i + 1]) return true;
        }
        return false;
    }
};
