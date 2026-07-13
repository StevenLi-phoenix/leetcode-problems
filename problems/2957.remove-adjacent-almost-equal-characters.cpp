// @leetcode id=2957 questionId=3230 slug=remove-adjacent-almost-equal-characters lang=cpp site=leetcode.com title="Remove Adjacent Almost-Equal Characters"
class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n = word.size();
        const int INF = INT_MAX / 2;
        vector<int> prevDp(26, 0); // dp[i-1][p]: base case, no prior letter constraint

        for (int i = 0; i < n; i++) {
            vector<int> curDp(26, INF);
            int orig = word[i] - 'a';
            for (int c = 0; c < 26; c++) {
                int cost = (c == orig) ? 0 : 1;
                int best = INF;
                for (int p = 0; p < 26; p++) {
                    if (i > 0 && abs(c - p) <= 1) continue; // almost-equal to previous, invalid
                    best = min(best, prevDp[p]);
                }
                curDp[c] = cost + best;
            }
            prevDp = move(curDp);
        }

        return *min_element(prevDp.begin(), prevDp.end());
    }
};
