// @leetcode id=1048 questionId=1129 slug=longest-string-chain lang=cpp site=leetcode.com title="Longest String Chain"
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int ans = 1;
        for (const string& w : words) {
            int best = 1;
            for (int i = 0; i < (int)w.size(); i++) {
                string pred = w.substr(0, i) + w.substr(i + 1);
                auto it = dp.find(pred);
                if (it != dp.end()) best = max(best, it->second + 1);
            }
            dp[w] = best;
            ans = max(ans, best);
        }
        return ans;
    }
};
