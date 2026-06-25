// @leetcode id=3213 questionId=3482 slug=construct-string-with-minimum-cost lang=cpp site=leetcode.com title="Construct String with Minimum Cost"
class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int n = target.size();
        
        // Group words by length, keep min cost per word
        unordered_map<string, int> wordCost;
        for (int i = 0; i < (int)words.size(); i++) {
            auto it = wordCost.find(words[i]);
            if (it == wordCost.end())
                wordCost[words[i]] = costs[i];
            else
                it->second = min(it->second, costs[i]);
        }
        
        // Get distinct lengths
        set<int> lenSet;
        for (auto& [w, c] : wordCost)
            lenSet.insert(w.size());
        vector<int> lens(lenSet.begin(), lenSet.end());
        
        const long long MOD1 = 1e9 + 7, BASE1 = 31;
        const long long MOD2 = 1e9 + 9, BASE2 = 37;
        
        int maxLen = lens.empty() ? 0 : lens.back();
        
        // Precompute prefix hashes of target
        vector<long long> h1(n+1,0), h2(n+1,0);
        vector<long long> pw1(n+1,1), pw2(n+1,1);
        for (int i = 0; i < n; i++) {
            h1[i+1] = (h1[i] * BASE1 + target[i]) % MOD1;
            h2[i+1] = (h2[i] * BASE2 + target[i]) % MOD2;
            pw1[i+1] = pw1[i] * BASE1 % MOD1;
            pw2[i+1] = pw2[i] * BASE2 % MOD2;
        }
        
        auto getHash = [&](int l, int r) -> pair<long long,long long> {
            // target[l..r-1]
            long long v1 = (h1[r] - h1[l] * pw1[r-l] % MOD1 + MOD1 * 2) % MOD1;
            long long v2 = (h2[r] - h2[l] * pw2[r-l] % MOD2 + MOD2 * 2) % MOD2;
            return {v1, v2};
        };
        
        // Precompute hash for each word
        unordered_map<long long, int> hashToCost; // combined hash -> min cost
        for (auto& [w, c] : wordCost) {
            long long wh1 = 0, wh2 = 0;
            for (char ch : w) {
                wh1 = (wh1 * BASE1 + ch) % MOD1;
                wh2 = (wh2 * BASE2 + ch) % MOD2;
            }
            long long combined = wh1 * (long long)(1e9+9) + wh2;
            auto it = hashToCost.find(combined);
            if (it == hashToCost.end())
                hashToCost[combined] = c;
            else
                it->second = min(it->second, c);
        }
        
        const int INF = 1e9;
        vector<int> dp(n+1, INF);
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;
            for (int L : lens) {
                if (i + L > n) break;
                auto [v1, v2] = getHash(i, i+L);
                long long combined = v1 * (long long)(1e9+9) + v2;
                auto it = hashToCost.find(combined);
                if (it != hashToCost.end()) {
                    dp[i+L] = min(dp[i+L], dp[i] + it->second);
                }
            }
        }
        
        return dp[n] == INF ? -1 : dp[n];
    }
};
