// @leetcode id=3644 questionId=3950 slug=maximum-k-to-sort-a-permutation lang=cpp site=leetcode.com title="Maximum K to Sort a Permutation"
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != i) {
                k = (k == -1) ? (nums[i] & i) : (k & (nums[i] & i));
            }
        }
        return k == -1 ? 0 : k;
    }
};
