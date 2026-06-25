// @leetcode id=1822 questionId=1950 slug=sign-of-the-product-of-an-array lang=cpp site=leetcode.com title="Sign of the Product of an Array"
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (int num : nums) {
            if (num == 0) return 0;
            if (num < 0) sign = -sign;
        }
        return sign;
    }
};
