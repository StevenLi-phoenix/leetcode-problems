// @leetcode id=1923 questionId=2051 slug=longest-common-subpath lang=cpp site=leetcode.com title="Longest Common Subpath"
class Solution {
public:
    // Binary search + Rolling hash
    // Check if there's a common subpath of length len in all paths
    bool check(int len, int n, vector<vector<int>>& paths) {
        const long long MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
        const long long BASE1 = n + 1, BASE2 = n + 2;
        
        // Compute power
        long long pw1 = 1, pw2 = 1;
        for (int i = 0; i < len; i++) {
            pw1 = pw1 * BASE1 % MOD1;
            pw2 = pw2 * BASE2 % MOD2;
        }
        
        unordered_set<long long> common;
        bool first = true;
        
        for (auto& path : paths) {
            int m = path.size();
            if (m < len) return false;
            
            unordered_set<long long> cur;
            long long h1 = 0, h2 = 0;
            
            for (int i = 0; i < len; i++) {
                h1 = (h1 * BASE1 + path[i] + 1) % MOD1;
                h2 = (h2 * BASE2 + path[i] + 1) % MOD2;
            }
            cur.insert(h1 * MOD2 + h2);
            
            for (int i = len; i < m; i++) {
                h1 = (h1 * BASE1 + path[i] + 1 - pw1 * (path[i - len] + 1) % MOD1 + MOD1 * 2) % MOD1;
                h2 = (h2 * BASE2 + path[i] + 1 - pw2 * (path[i - len] + 1) % MOD2 + MOD2 * 2) % MOD2;
                cur.insert(h1 * MOD2 + h2);
            }
            
            if (first) {
                common = cur;
                first = false;
            } else {
                unordered_set<long long> newCommon;
                for (auto& x : cur) {
                    if (common.count(x)) newCommon.insert(x);
                }
                common = newCommon;
            }
            
            if (common.empty()) return false;
        }
        
        return !common.empty();
    }
    
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int lo = 0, hi = INT_MAX;
        for (auto& p : paths) hi = min(hi, (int)p.size());
        
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (check(mid, n, paths)) lo = mid;
            else hi = mid - 1;
        }
        
        return lo;
    }
};
