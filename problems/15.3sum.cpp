// @leetcode id=15 questionId=15 slug=3sum lang=cpp site=leetcode.com title="3Sum"
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Iterate through each element as the first element of triplet
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for first element
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            // If current number is positive, no triplet can sum to 0
            if (nums[i] > 0) break;
            
            // Use two pointers to find remaining two numbers
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicate values for second element
                    while (left < right && nums[left] == nums[left+1]) left++;
                    // Skip duplicate values for third element
                    while (left < right && nums[right] == nums[right-1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};
