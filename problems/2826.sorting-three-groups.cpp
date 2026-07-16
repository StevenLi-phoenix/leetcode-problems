// @leetcode id=2826 questionId=2904 slug=sorting-three-groups lang=cpp site=leetcode.com title="Sorting Three Groups"
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int dp1 = 0, dp2 = 0, dp3 = 0;
        for (int x : nums) {
            int ndp1 = dp1 + (x == 1 ? 0 : 1);
            int ndp2 = min(dp1, dp2) + (x == 2 ? 0 : 1);
            int ndp3 = min({dp1, dp2, dp3}) + (x == 3 ? 0 : 1);
            dp1 = ndp1; dp2 = ndp2; dp3 = ndp3;
        }
        return min({dp1, dp2, dp3});
    }
};
