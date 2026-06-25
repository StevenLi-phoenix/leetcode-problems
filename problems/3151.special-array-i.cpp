// @leetcode id=3151 questionId=3429 slug=special-array-i lang=cpp site=leetcode.com title="Special Array I"
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 0; i + 1 < (int)nums.size(); i++) {
            if ((nums[i] % 2) == (nums[i+1] % 2)) {
                return false;
            }
        }
        return true;
    }
};
