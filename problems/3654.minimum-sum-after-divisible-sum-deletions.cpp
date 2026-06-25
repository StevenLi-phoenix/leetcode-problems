// @leetcode id=3654 questionId=3966 slug=minimum-sum-after-divisible-sum-deletions lang=cpp site=leetcode.com title="Minimum Sum After Divisible Sum Deletions"
class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long total = 0;
        for (int x : nums) total += x;
        
        // prefix[i] = sum of first i elements
        // dp[i] = max sum we can delete from first i elements
        // dp[i] = max(dp[i-1], prefix[i] - prefix[j] + dp[j])
        //       where prefix[j] % k == prefix[i] % k
        // = max(dp[i-1], prefix[i] + maxVal[prefix[i]%k])
        //   where maxVal[r] = max(dp[j] - prefix[j]) for prefix[j]%k == r
        
        vector<long long> maxVal(k, LLONG_MIN/2);
        // j=0: prefix[0]=0, dp[0]=0 => maxVal[0] = 0 - 0 = 0
        maxVal[0] = 0;
        
        long long dp = 0; // dp[i-1]
        long long prefix = 0;
        
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            long long r = prefix % k;
            
            // try extending a previous segment
            long long candidate = LLONG_MIN/2;
            if (maxVal[r] != LLONG_MIN/2) {
                candidate = prefix + maxVal[r];
            }
            
            dp = max(dp, candidate);
            
            // update maxVal for current position
            // dp[i] - prefix[i+1]: we can start a new segment after position i
            maxVal[r] = max(maxVal[r], dp - prefix);
        }
        
        return total - dp;
    }
};
