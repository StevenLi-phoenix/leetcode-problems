// @leetcode id=2815 questionId=2902 slug=max-pair-sum-in-an-array lang=cpp site=leetcode.com title="Max Pair Sum in an Array"
class Solution {
public:
    int maxDigit(int x) {
        int best = 0;
        while (x > 0) {
            best = max(best, x % 10);
            x /= 10;
        }
        return best;
    }

    int maxSum(vector<int>& nums) {
        int best[10] = {0};
        int second[10] = {0};

        for (int x : nums) {
            int d = maxDigit(x);
            if (x > best[d]) {
                second[d] = best[d];
                best[d] = x;
            } else if (x > second[d]) {
                second[d] = x;
            }
        }

        int result = -1;
        for (int d = 0; d < 10; d++) {
            if (second[d] > 0) result = max(result, best[d] + second[d]);
        }
        return result;
    }
};
