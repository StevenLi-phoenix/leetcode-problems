// @leetcode id=3201 questionId=3490 slug=find-the-maximum-length-of-valid-subsequence-i lang=cpp site=leetcode.com title="Find the Maximum Length of Valid Subsequence I"
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int count0 = 0, count1 = 0;
        for (int x : nums) {
            if (x % 2 == 0) count0++;
            else count1++;
        }
        int sameMax = max(count0, count1);

        int prev = -1, altLen = 0;
        for (int x : nums) {
            int p = x % 2;
            if (p != prev) {
                altLen++;
                prev = p;
            }
        }

        return max(sameMax, altLen);
    }
};
