// @leetcode id=260 questionId=260 slug=single-number-iii lang=cpp site=leetcode.com title="Single Number III"
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll = 0;
        for (int n : nums) xorAll ^= n;

        long long diffBit = xorAll & (-xorAll);
        int a = 0, b = 0;
        for (int n : nums) {
            if (n & diffBit) a ^= n;
            else b ^= n;
        }
        return {a, b};
    }
};
