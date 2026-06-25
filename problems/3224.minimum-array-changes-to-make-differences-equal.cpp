// @leetcode id=3224 questionId=3498 slug=minimum-array-changes-to-make-differences-equal lang=cpp site=leetcode.com title="Minimum Array Changes to Make Differences Equal"
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n / 2;
        
        // For each pair (nums[i], nums[n-i-1]):
        // lo = min, hi = max, diff = hi - lo, maxReach = max(hi, k-lo)
        
        // cnt[d] = count of pairs with diff = d
        // reach[r] = count of pairs with maxReach = r
        vector<int> cnt(k + 1, 0);
        vector<int> reach(k + 1, 0);
        
        for (int i = 0; i < m; i++) {
            int a = nums[i], b = nums[n - 1 - i];
            int lo = min(a, b), hi = max(a, b);
            int diff = hi - lo;
            int maxReach = max(hi, k - lo);
            
            if (diff <= k) cnt[diff]++;
            if (maxReach <= k) reach[maxReach]++;
        }
        
        // prefix sum: pairsWithReachLessThan[X] = count of pairs with maxReach < X
        // = sum of reach[0..X-1]
        // We need this for "pairs_2[X]"
        vector<int> prefixReach(k + 2, 0);
        for (int i = 0; i <= k; i++) {
            prefixReach[i + 1] = prefixReach[i] + reach[i];
        }
        // pairs with maxReach < X = prefixReach[X]
        // But maxReach = max(hi, k-lo) >= max(0, k-k=0) = 0
        // and maxReach <= max(k, k) = k
        
        int ans = m; // worst case: all pairs need 1 change
        for (int X = 0; X <= k; X++) {
            // Changes = m - cnt[X] + pairs_2[X]
            // pairs_2[X] = count of pairs with maxReach < X
            int pairs0 = (X <= k) ? cnt[X] : 0;
            int pairs2 = prefixReach[X]; // pairs with maxReach < X, need 2 changes
            int changes = m - pairs0 + pairs2;
            ans = min(ans, changes);
        }
        
        return ans;
    }
};
