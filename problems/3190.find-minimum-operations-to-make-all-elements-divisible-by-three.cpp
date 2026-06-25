// @leetcode id=3190 questionId=3476 slug=find-minimum-operations-to-make-all-elements-divisible-by-three lang=cpp site=leetcode.com title="Find Minimum Operations to Make All Elements Divisible by Three"
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for (int x : nums) {
            int r = x % 3;
            ops += min(r, 3 - r);
        }
        return ops;
    }
};
