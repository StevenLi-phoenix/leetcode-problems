// @leetcode id=1425 questionId=1286 slug=constrained-subsequence-sum lang=cpp site=leetcode.com title="Constrained Subsequence Sum"
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq; // stores indices in decreasing order of dp value
        int result = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            // Remove elements outside window of size k
            while (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }
            
            // dp[i] = nums[i] + max(0, max dp in window)
            dp[i] = nums[i];
            if (!dq.empty() && dp[dq.front()] > 0) {
                dp[i] += dp[dq.front()];
            }
            
            result = max(result, dp[i]);
            
            // Maintain decreasing deque
            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        return result;
    }
};
