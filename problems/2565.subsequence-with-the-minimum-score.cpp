// @leetcode id=2565 questionId=2701 slug=subsequence-with-the-minimum-score lang=cpp site=leetcode.com title="Subsequence With the Minimum Score"
class Solution {
public:
    int minimumScore(string s, string t) {
        int n = s.size(), m = t.size();
        const int INF = n + 1;

        // need[l] = minimum length of a prefix of s that matches t[0:l] as a
        // subsequence (INF if t[0:l] can't be matched at all).
        vector<int> need(m + 1);
        need[0] = 0;
        {
            int si = 0;
            for (int l = 1; l <= m; l++) {
                while (si < n && s[si] != t[l - 1]) si++;
                if (si == n) { need[l] = INF; continue; }
                si++;
                need[l] = si;
            }
        }

        // needSuf[r] = minimum length of a suffix of s that matches t[r:m] as
        // a subsequence (INF if not matchable).
        vector<int> needSuf(m + 1);
        needSuf[m] = 0;
        {
            int sj = n - 1;
            for (int r = m - 1; r >= 0; r--) {
                while (sj >= 0 && s[sj] != t[r]) sj--;
                if (sj < 0) { needSuf[r] = INF; continue; }
                needSuf[r] = n - sj;
                sj--;
            }
        }

        int ans = m; // removing everything is always valid
        int r = 0;
        for (int l = 0; l <= m; l++) {
            if (need[l] >= INF) break;
            if (r < l) r = l;
            while (r <= m && (needSuf[r] >= INF || need[l] + needSuf[r] > n)) r++;
            if (r <= m) ans = min(ans, r - l);
        }
        return ans;
    }
};
