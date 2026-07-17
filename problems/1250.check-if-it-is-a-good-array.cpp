// @leetcode id=1250 questionId=1372 slug=check-if-it-is-a-good-array lang=cpp site=leetcode.com title="Check If It Is a Good Array"
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for (int x : nums) {
            g = std::__gcd(g, x);
            if (g == 1) return true;
        }
        return g == 1;
    }
};
