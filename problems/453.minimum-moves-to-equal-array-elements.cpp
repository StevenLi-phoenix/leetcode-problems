// @leetcode id=453 questionId=453 slug=minimum-moves-to-equal-array-elements lang=cpp site=leetcode.com title="Minimum Moves to Equal Array Elements"
class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int minVal = nums[0];
        for (int v : nums) {
            sum += v;
            minVal = min(minVal, v);
        }
        return (int)(sum - (long long)minVal * nums.size());
    }
};
