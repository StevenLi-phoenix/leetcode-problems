// @leetcode id=2006 questionId=2116 slug=count-number-of-pairs-with-absolute-difference-k lang=cpp site=leetcode.com title="Count Number of Pairs With Absolute Difference K"
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count[101] = {0};
        int result = 0;
        for (int x : nums) {
            if (x - k >= 1) result += count[x - k];
            if (x + k <= 100) result += count[x + k];
            count[x]++;
        }
        return result;
    }
};
