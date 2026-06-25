// @leetcode id=3333 questionId=3618 slug=find-the-original-typed-string-ii lang=cpp site=leetcode.com title="Find the Original Typed String II"
class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int MOD = 1e9 + 7;
        
        // Count groups of consecutive same characters
        vector<int> groups;
        int i = 0;
        while (i < (int)word.size()) {
            int j = i;
            while (j < (int)word.size() && word[j] == word[i]) j++;
            groups.push_back(j - i);
            i = j;
        }
        
        int m = groups.size();
        
        // Total number of possible original strings (without length constraint)
        long long total = 1;
        for (int g : groups) total = total * g % MOD;
        
        // If minimum possible length (1 per group) >= k, answer is total
        if (m >= k) return total;
        
        // DP: count strings of length < k
        // dp[j] = number of ways to have sum exactly j from groups chosen so far
        // Each group i contributes ci in [1, groups[i]]
        // We only care about sums 0..k-1
        
        vector<long long> dp(k, 0);
        dp[0] = 1;
        
        for (int g : groups) {
            // New dp: for each sum s, adding value v in [1, g]
            // Use prefix sums for efficiency
            vector<long long> ndp(k, 0);
            // prefix sum of dp
            vector<long long> prefix(k + 1, 0);
            for (int s = 0; s < k; s++) prefix[s + 1] = (prefix[s] + dp[s]) % MOD;
            
            for (int s = 0; s < k; s++) {
                // We want sum s: came from s - v where v in [1, g]
                // so prev sum in [s-g, s-1], clamped to [0, k-1]
                int lo = max(0, s - g);
                int hi = s - 1;
                if (hi < 0) continue;
                hi = min(hi, k - 1);
                if (lo > hi) continue;
                ndp[s] = (prefix[hi + 1] - prefix[lo] + MOD) % MOD;
            }
            dp = ndp;
        }
        
        // Count strings with length < k (sum from 0 to k-1 of dp)
        long long bad = 0;
        for (int s = 0; s < k; s++) bad = (bad + dp[s]) % MOD;
        
        return (total - bad + MOD) % MOD;
    }
};
