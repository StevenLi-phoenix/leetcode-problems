// @leetcode id=3251 questionId=3536 slug=find-the-count-of-monotonic-pairs-ii lang=cpp site=leetcode.com title="Find the Count of Monotonic Pairs II"
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        
        // Compute c[i] = nums[i] - prefix_d where prefix_d = sum of max(0, nums[j]-nums[j-1]) for j=1..i
        // dp[v] = number of ways to have arr1[i] = v (after subtracting prefix_d)
        // But let's work with arr1[i] directly
        
        // dp[v] = number of sequences arr1[0..i] where arr1[i] = v
        // Initialize: arr1[0] can be 0..nums[0]
        vector<long long> dp(maxVal + 1, 0);
        for (int v = 0; v <= nums[0]; v++) dp[v] = 1;
        
        for (int i = 1; i < n; i++) {
            // arr1[i] >= arr1[i-1], arr1[i] >= arr1[i-1] + max(0, nums[i]-nums[i-1])
            // arr1[i] in [0, nums[i]]
            // For each new value v, dp_new[v] = sum of dp[u] for u <= v - max(0, nums[i]-nums[i-1])
            // (since arr1[i] = v means arr1[i-1] <= v - diff)
            
            int diff = max(0, nums[i] - nums[i-1]);
            
            // Build prefix sum of dp
            vector<long long> prefix(maxVal + 2, 0);
            for (int v = 0; v <= maxVal; v++) {
                prefix[v + 1] = (prefix[v] + dp[v]) % MOD;
            }
            
            vector<long long> dp_new(maxVal + 1, 0);
            for (int v = 0; v <= nums[i]; v++) {
                // arr1[i-1] <= v - diff → arr1[i-1] in [0, v-diff]
                int maxPrev = v - diff;
                if (maxPrev < 0) continue;
                dp_new[v] = prefix[min(maxPrev + 1, (int)prefix.size() - 1)];
            }
            dp = dp_new;
        }
        
        long long ans = 0;
        for (int v = 0; v <= maxVal; v++) ans = (ans + dp[v]) % MOD;
        return ans;
    }
};
