// @leetcode id=3513 questionId=3824 slug=number-of-unique-xor-triplets-i lang=cpp site=leetcode.com title="Number of Unique XOR Triplets I"
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;

        int p = 1;
        while (p <= n) p <<= 1;
        return p;
    }
};
