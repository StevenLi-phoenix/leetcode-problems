// @leetcode id=239 questionId=239 slug=sliding-window-maximum lang=cpp site=leetcode.com title="Sliding Window Maximum"
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // indices, values decreasing
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (dq.front() <= i - k) dq.pop_front();
            if (i >= k - 1) result.push_back(nums[dq.front()]);
        }
        return result;
    }
};
