// @leetcode id=3389 questionId=3638 slug=minimum-operations-to-make-character-frequencies-equal lang=cpp site=leetcode.com title="Minimum Operations to Make Character Frequencies Equal"
class Solution {
public:
    int makeStringGood(string s) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        int maxc = 0;
        for (int v : cnt) maxc = max(maxc, v);

        // Per-unit cost to retarget a letter's occurrences to frequency t:
        // adjacent-letter shifts ('a'->'b') cost 1 (cheaper than delete+insert=2),
        // so DP left-to-right over letters, tracking whether each is set to 0 or t,
        // subtracting the savings from matching one letter's excess to the next's shortfall.
        int ans = s.size();
        for (int t = 0; t <= maxc; t++) {
            int dp0 = cnt[0];
            int dp1 = abs(cnt[0] - t);
            for (int i = 1; i < 26; i++) {
                int c0 = cnt[i];
                int c1 = abs(cnt[i] - t);
                int excessPrev0 = cnt[i - 1];
                int excessPrevT = max(cnt[i - 1] - t, 0);
                int shortfallCurT = max(t - cnt[i], 0);

                int newdp0 = min(dp0 + c0, dp1 + c0);
                int newdp1 = min(dp0 + c1 - min(excessPrev0, shortfallCurT),
                                  dp1 + c1 - min(excessPrevT, shortfallCurT));
                dp0 = newdp0;
                dp1 = newdp1;
            }
            ans = min({ans, dp0, dp1});
        }
        return ans;
    }
};
