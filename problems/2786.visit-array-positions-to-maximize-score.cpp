// @leetcode id=2786 questionId=2893 slug=visit-array-positions-to-maximize-score lang=cpp site=leetcode.com title="Visit Array Positions to Maximize Score"
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long best[2];
        best[0] = best[1] = LLONG_MIN;
        best[nums[0] % 2] = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            int p = nums[i] % 2;
            long long same = (best[p] == LLONG_MIN) ? LLONG_MIN : best[p] + nums[i];
            long long diff = (best[1 - p] == LLONG_MIN) ? LLONG_MIN : best[1 - p] + nums[i] - x;
            best[p] = max(best[p], max(same, diff));
        }

        return max(best[0], best[1]);
    }
};
