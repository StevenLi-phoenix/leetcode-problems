// @leetcode id=3835 questionId=4211 slug=count-subarrays-with-cost-less-than-or-equal-to-k lang=cpp site=leetcode.com title="Count Subarrays With Cost Less Than or Equal to K"
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        deque<int> maxDq, minDq; // indices
        int l = 0;
        
        for (int r = 0; r < n; r++) {
            // Maintain decreasing deque for max
            while (!maxDq.empty() && nums[maxDq.back()] <= nums[r])
                maxDq.pop_back();
            maxDq.push_back(r);
            
            // Maintain increasing deque for min
            while (!minDq.empty() && nums[minDq.back()] >= nums[r])
                minDq.pop_back();
            minDq.push_back(r);
            
            // Shrink window from left if cost > k
            while (l <= r) {
                long long curMax = nums[maxDq.front()];
                long long curMin = nums[minDq.front()];
                long long len = r - l + 1;
                if ((curMax - curMin) * len > k) {
                    l++;
                    if (maxDq.front() < l) maxDq.pop_front();
                    if (minDq.front() < l) minDq.pop_front();
                } else {
                    break;
                }
            }
            
            // All subarrays ending at r starting from l to r are valid
            ans += (r - l + 1);
        }
        
        return ans;
    }
};
