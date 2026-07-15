// @leetcode id=775 questionId=790 slug=global-and-local-inversions lang=cpp site=leetcode.com title="Global and Local Inversions"
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int maxSoFar = -1;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            maxSoFar = max(maxSoFar, nums[i]);
            if (maxSoFar > nums[i + 2]) return false;
        }
        return true;
    }
};
