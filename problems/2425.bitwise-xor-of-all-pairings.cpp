// @leetcode id=2425 questionId=2533 slug=bitwise-xor-of-all-pairings lang=cpp site=leetcode.com title="Bitwise XOR of All Pairings"
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        if (nums2.size() % 2 == 1) {
            for (int n : nums1) result ^= n;
        }
        if (nums1.size() % 2 == 1) {
            for (int n : nums2) result ^= n;
        }
        return result;
    }
};
