// @leetcode id=472 questionId=472 slug=concatenated-words lang=cpp site=leetcode.com title="Concatenated Words"
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());

        // canBuild(w): can w be split into >=2 pieces each present in dict?
        function<bool(const string&)> canBuild = [&](const string& w) -> bool {
            int n = w.size();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    // Skip the trivial whole-word split (j == 0 && i == n).
                    if (!dp[j]) continue;
                    if (j == 0 && i == n) continue;
                    if (dict.count(w.substr(j, i - j))) { dp[i] = true; break; }
                }
            }
            return dp[n];
        };

        vector<string> ans;
        for (const string& w : words)
            if (!w.empty() && canBuild(w)) ans.push_back(w);
        return ans;
    }
};
