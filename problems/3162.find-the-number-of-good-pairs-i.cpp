// @leetcode id=3162 questionId=3446 slug=find-the-number-of-good-pairs-i lang=cpp site=leetcode.com title="Find the Number of Good Pairs I"
class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int count = 0;
        for (int a : nums1) {
            for (int b : nums2) {
                if (a % (b * k) == 0) count++;
            }
        }
        return count;
    }
};
