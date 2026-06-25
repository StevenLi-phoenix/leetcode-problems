// @leetcode id=2733 questionId=2836 slug=neither-minimum-nor-maximum lang=cpp site=leetcode.com title="Neither Minimum nor Maximum"
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        for (int x : nums) {
            if (x != mn && x != mx) return x;
        }
        return -1;
    }
};
