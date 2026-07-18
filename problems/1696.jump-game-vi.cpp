// @leetcode id=1696 questionId=1814 slug=jump-game-vi lang=cpp site=leetcode.com title="Jump Game VI"
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n);
        dp[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);

        for (int i = 1; i < n; i++) {
            while (!dq.empty() && dq.front() < i - k) dq.pop_front();
            dp[i] = dp[dq.front()] + nums[i];
            while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
            dq.push_back(i);
        }

        return (int)dp[n - 1];
    }
};
