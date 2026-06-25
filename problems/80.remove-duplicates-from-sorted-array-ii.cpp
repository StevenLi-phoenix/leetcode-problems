// @leetcode id=80 questionId=80 slug=remove-duplicates-from-sorted-array-ii lang=cpp site=leetcode.com title="Remove Duplicates from Sorted Array II"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int num : nums) {
            if (k < 2 || nums[k-2] != num) {
                nums[k++] = num;
            }
        }
        return k;
    }
};
