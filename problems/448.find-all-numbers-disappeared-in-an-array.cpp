// @leetcode id=448 questionId=448 slug=find-all-numbers-disappeared-in-an-array lang=cpp site=leetcode.com title="Find All Numbers Disappeared in an Array"
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        // Mark visited positions by negating the value at index (num-1)
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }
        
        // Collect indices where value is still positive (missing numbers)
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};
