// @leetcode id=3003 questionId=3233 slug=maximize-the-number-of-partitions-after-operations lang=cpp site=leetcode.com title="Maximize the Number of Partitions After Operations"
class Solution {
public:
    unordered_map<long long, int> memo;
    int n, k;
    string s;
    
    int dp(int i, int mask, int changed) {
        if (i == n) {
            return (mask > 0) ? 1 : 0;
        }
        
        long long key = ((long long)i << 28) | ((long long)mask << 1) | changed;
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;
        
        int best = 0;
        
        // Option 1: Keep s[i] as is
        {
            int bit = 1 << (s[i] - 'a');
            int new_mask = mask | bit;
            int val;
            if (__builtin_popcount(new_mask) > k) {
                // Close current partition, start new one
                val = 1 + dp(i + 1, bit, changed);
            } else {
                val = dp(i + 1, new_mask, changed);
            }
            best = max(best, val);
        }
        
        // Option 2: Change s[i] to some other character (if !changed)
        if (!changed) {
            for (int c = 0; c < 26; c++) {
                if (c == s[i] - 'a') continue; // skip keeping (already done above)
                int bit = 1 << c;
                int new_mask = mask | bit;
                int val;
                if (__builtin_popcount(new_mask) > k) {
                    val = 1 + dp(i + 1, bit, 1);
                } else {
                    val = dp(i + 1, new_mask, 1);
                }
                best = max(best, val);
            }
        }
        
        return memo[key] = best;
    }
    
    int maxPartitionsAfterOperations(string s, int k) {
        this->s = s;
        this->n = s.size();
        this->k = k;
        memo.clear();
        return dp(0, 0, 0);
    }
};
