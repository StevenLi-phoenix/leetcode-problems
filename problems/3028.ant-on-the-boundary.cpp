// @leetcode id=3028 questionId=3311 slug=ant-on-the-boundary lang=cpp site=leetcode.com title="Ant on the Boundary"
class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int sum = 0, count = 0;
        for (int x : nums) {
            sum += x;
            if (sum == 0) count++;
        }
        return count;
    }
};
