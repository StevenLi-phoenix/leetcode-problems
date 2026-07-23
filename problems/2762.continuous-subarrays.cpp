// @leetcode id=2762 questionId=2868 slug=continuous-subarrays lang=cpp site=leetcode.com title="Continuous Subarrays"
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        deque<int> maxDq, minDq; // store indices
        long long total = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            while (!maxDq.empty() && nums[maxDq.back()] <= nums[right]) maxDq.pop_back();
            maxDq.push_back(right);
            while (!minDq.empty() && nums[minDq.back()] >= nums[right]) minDq.pop_back();
            minDq.push_back(right);

            while (nums[maxDq.front()] - nums[minDq.front()] > 2) {
                if (maxDq.front() == left) maxDq.pop_front();
                if (minDq.front() == left) minDq.pop_front();
                left++;
            }

            total += (right - left + 1);
        }

        return total;
    }
};
