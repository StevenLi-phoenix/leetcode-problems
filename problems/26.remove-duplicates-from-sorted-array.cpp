// @leetcode id=26 questionId=26 slug=remove-duplicates-from-sorted-array lang=cpp site=leetcode.com title="Remove Duplicates from Sorted Array"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int k = 1; // first element is always unique
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
};
