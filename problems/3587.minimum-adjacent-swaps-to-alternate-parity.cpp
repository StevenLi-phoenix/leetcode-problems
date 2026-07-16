// @leetcode id=3587 questionId=3904 slug=minimum-adjacent-swaps-to-alternate-parity lang=cpp site=leetcode.com title="Minimum Adjacent Swaps to Alternate Parity"
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> oddPositions;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) oddPositions.push_back(i);
        }
        int countOdd = oddPositions.size();
        int countEven = n - countOdd;
        if (abs(countOdd - countEven) > 1) return -1;

        long long best = LLONG_MAX;

        // pattern: odd numbers at indices 0,2,4,... (start with odd)
        int neededOddStart = (n + 1) / 2;
        if (countOdd == neededOddStart) {
            long long cost = 0;
            for (int k = 0; k < countOdd; k++) {
                cost += llabs(oddPositions[k] - (2 * k));
            }
            best = min(best, cost);
        }

        // pattern: odd numbers at indices 1,3,5,... (start with even)
        int neededOddEnd = n / 2;
        if (countOdd == neededOddEnd) {
            long long cost = 0;
            for (int k = 0; k < countOdd; k++) {
                cost += llabs(oddPositions[k] - (2 * k + 1));
            }
            best = min(best, cost);
        }

        return best == LLONG_MAX ? -1 : (int)best;
    }
};
