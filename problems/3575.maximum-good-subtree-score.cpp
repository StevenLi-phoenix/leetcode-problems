// @leetcode id=3575 questionId=3875 slug=maximum-good-subtree-score lang=cpp site=leetcode.com title="Maximum Good Subtree Score"
class Solution {
public:
    static const long long MOD = 1e9 + 7;

    int digitMask(int v) {
        int mask = 0;
        while (v > 0) {
            int d = v % 10;
            if (mask & (1 << d)) return -1; // repeated digit within the value itself
            mask |= (1 << d);
            v /= 10;
        }
        return mask;
    }

    vector<vector<int>> children;
    vector<int> vals_;
    long long totalScore = 0;

    // Returns a sparse map: mask -> max sum achievable with exactly that used-digit mask.
    unordered_map<int, long long> dfs(int u) {
        unordered_map<int, long long> dp;
        dp[0] = 0;

        for (int c : children[u]) {
            unordered_map<int, long long> childDp = dfs(c);
            unordered_map<int, long long> merged = dp;
            for (auto& [m1, s1] : dp) {
                for (auto& [m2, s2] : childDp) {
                    if (m1 & m2) continue;
                    int nm = m1 | m2;
                    long long ns = s1 + s2;
                    auto it = merged.find(nm);
                    if (it == merged.end() || it->second < ns) merged[nm] = ns;
                }
            }
            dp = merged;
        }

        int selfMask = digitMask(vals_[u]);
        if (selfMask != -1) {
            unordered_map<int, long long> withSelf = dp;
            for (auto& [m, s] : dp) {
                if (m & selfMask) continue;
                int nm = m | selfMask;
                long long ns = s + vals_[u];
                auto it = withSelf.find(nm);
                if (it == withSelf.end() || it->second < ns) withSelf[nm] = ns;
            }
            dp = withSelf;
        }

        long long best = 0;
        for (auto& [m, s] : dp) best = max(best, s);
        totalScore = (totalScore + best % MOD) % MOD;

        return dp;
    }

    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        int n = vals.size();
        vals_ = vals;
        children.assign(n, {});
        for (int i = 1; i < n; i++) children[par[i]].push_back(i);

        totalScore = 0;
        dfs(0);
        return (int)totalScore;
    }
};
