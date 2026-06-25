// @leetcode id=16 questionId=16 slug=3sum-closest lang=cpp site=leetcode.com title="3Sum Closest"
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                // Update closest sum if current sum is closer to target
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }
                
                // If sum equals target, we found the best possible
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return closestSum;
    }
};
