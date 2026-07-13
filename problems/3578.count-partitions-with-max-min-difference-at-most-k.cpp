// @leetcode id=3578 questionId=3835 slug=count-partitions-with-max-min-difference-at-most-k lang=cpp site=leetcode.com title="Count Partitions With Max-Min Difference at Most K"
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const long long MOD = 1'000'000'007;
        int n = nums.size();
        vector<long long> dp(n + 1, 0), prefixSum(n + 2, 0);
        dp[0] = 1;
        prefixSum[1] = 1; // prefixSum[t] = dp[0]+...+dp[t-1]

        deque<int> maxDq, minDq; // store nums-indices, decreasing/increasing
        int lo = 0;

        for (int i = 1; i <= n; i++) {
            int r = i - 1;
            while (!maxDq.empty() && nums[maxDq.back()] <= nums[r]) maxDq.pop_back();
            maxDq.push_back(r);
            while (!minDq.empty() && nums[minDq.back()] >= nums[r]) minDq.pop_back();
            minDq.push_back(r);

            while (nums[maxDq.front()] - nums[minDq.front()] > k) {
                lo++;
                if (maxDq.front() < lo) maxDq.pop_front();
                if (minDq.front() < lo) minDq.pop_front();
            }

            dp[i] = ((prefixSum[i] - prefixSum[lo]) % MOD + MOD) % MOD;
            prefixSum[i + 1] = (prefixSum[i] + dp[i]) % MOD;
        }
        return (int)dp[n];
    }
};
