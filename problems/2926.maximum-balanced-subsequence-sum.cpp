// @leetcode id=2926 questionId=3184 slug=maximum-balanced-subsequence-sum lang=cpp site=leetcode.com title="Maximum Balanced Subsequence Sum"
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> val(n);
        for (int i = 0; i < n; i++) val[i] = nums[i] - i;
        
        vector<int> sorted_val = val;
        sort(sorted_val.begin(), sorted_val.end());
        sorted_val.erase(unique(sorted_val.begin(), sorted_val.end()), sorted_val.end());
        int m = sorted_val.size();
        
        auto getIdx = [&](int v) {
            return (int)(lower_bound(sorted_val.begin(), sorted_val.end(), v) - sorted_val.begin()) + 1;
        };
        
        vector<long long> bit(m + 2, LLONG_MIN / 2);
        
        auto update = [&](int i, long long v) {
            for (; i <= m; i += i & (-i))
                bit[i] = max(bit[i], v);
        };
        
        auto query = [&](int i) -> long long {
            long long res = LLONG_MIN / 2;
            for (; i > 0; i -= i & (-i))
                res = max(res, bit[i]);
            return res;
        };
        
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            int idx = getIdx(val[i]);
            long long best_prev = query(idx);
            long long dp_i = nums[i] + max(0LL, best_prev);
            ans = max(ans, dp_i);
            update(idx, dp_i);
        }
        
        return ans;
    }
};
