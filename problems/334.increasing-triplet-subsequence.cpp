// @leetcode id=334 questionId=334 slug=increasing-triplet-subsequence lang=cpp site=leetcode.com title="Increasing Triplet Subsequence"
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long first = LLONG_MAX, second = LLONG_MAX;
        for (int x : nums) {
            if (x <= first) first = x;
            else if (x <= second) second = x;
            else return true;
        }
        return false;
    }
};
