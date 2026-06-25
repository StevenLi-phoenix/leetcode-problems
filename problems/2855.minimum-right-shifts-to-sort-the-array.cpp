// @leetcode id=2855 questionId=3045 slug=minimum-right-shifts-to-sort-the-array lang=cpp site=leetcode.com title="Minimum Right Shifts to Sort the Array"
class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int descentPos = -1;
        int descentCount = 0;
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                descentCount++;
                descentPos = i;
            }
        }
        
        if (descentCount == 0) return 0;
        if (descentCount == 1 && nums[n - 1] < nums[0]) {
            return n - descentPos - 1;
        }
        return -1;
    }
};
