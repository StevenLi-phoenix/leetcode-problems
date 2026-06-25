// @leetcode id=3254 questionId=3522 slug=find-the-power-of-k-size-subarrays-i lang=cpp site=leetcode.com title="Find the Power of K-Size Subarrays I"
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        
        for (int i = 0; i <= n - k; i++) {
            bool isConsecutiveAscending = true;
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j-1] + 1) {
                    isConsecutiveAscending = false;
                    break;
                }
            }
            if (isConsecutiveAscending) {
                result.push_back(nums[i + k - 1]);
            } else {
                result.push_back(-1);
            }
        }
        
        return result;
    }
};
