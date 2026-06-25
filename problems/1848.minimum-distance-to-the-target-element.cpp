// @leetcode id=1848 questionId=1975 slug=minimum-distance-to-the-target-element lang=cpp site=leetcode.com title="Minimum Distance to the Target Element"
class Solution {
    public:
    int getMinDistance(vector<int>& nums, int target, int start) {
    int res = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == target) {
    res = min(res, abs(i - start));
    }
    }
    return res;
    }
    };
