// @leetcode id=2901 questionId=3142 slug=longest-unequal-adjacent-groups-subsequence-ii lang=cpp site=leetcode.com title="Longest Unequal Adjacent Groups Subsequence II"
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1), parent(n, -1);
        int best = 0;

        auto hamming1 = [](const string& a, const string& b) {
            if (a.size() != b.size()) return false;
            int diff = 0;
            for (size_t i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) diff++;
                if (diff > 1) return false;
            }
            return diff == 1;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[j] != groups[i] && hamming1(words[j], words[i]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > dp[best]) best = i;
        }

        vector<string> ans;
        for (int i = best; i != -1; i = parent[i]) {
            ans.push_back(words[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
