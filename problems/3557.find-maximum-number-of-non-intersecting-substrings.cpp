// @leetcode id=3557 questionId=3857 slug=find-maximum-number-of-non-intersecting-substrings lang=cpp site=leetcode.com title="Find Maximum Number of Non Intersecting Substrings"
class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        vector<vector<int>> positions(26);
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i];
            int c = word[i] - 'a';
            // Find the most recent prior occurrence of the same letter that
            // still leaves a gap of at least 4 (length >= 4 substring);
            // using the closest valid start (not the earliest) leaves the
            // most room for future intervals without ever hurting dp[start].
            auto& occ = positions[c];
            auto it = upper_bound(occ.begin(), occ.end(), i - 3);
            if (it != occ.begin()) {
                int s = *prev(it);
                dp[i + 1] = max(dp[i + 1], dp[s] + 1);
            }
            occ.push_back(i);
        }
        return dp[n];
    }
};
