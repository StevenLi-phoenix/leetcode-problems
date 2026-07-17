// @leetcode id=679 questionId=679 slug=24-game lang=cpp site=leetcode.com title="24 Game"
class Solution {
public:
    const double EPS = 1e-6;

    bool solve(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) return fabs(nums[0] - 24.0) < EPS;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                vector<double> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                double a = nums[i], b = nums[j];
                vector<double> candidates = {a + b, a - b, a * b};
                if (fabs(b) > EPS) candidates.push_back(a / b);

                for (double val : candidates) {
                    next.push_back(val);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};
