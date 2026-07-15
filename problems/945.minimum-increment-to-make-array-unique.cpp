// @leetcode id=945 questionId=982 slug=minimum-increment-to-make-array-unique lang=cpp site=leetcode.com title="Minimum Increment to Make Array Unique"
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long moves = 0;
        int nextFree = 0;
        for (int v : nums) {
            int target = max(v, nextFree);
            moves += target - v;
            nextFree = target + 1;
        }
        return (int)moves;
    }
};
