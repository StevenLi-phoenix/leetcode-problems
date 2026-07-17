// @leetcode id=995 questionId=1037 slug=minimum-number-of-k-consecutive-bit-flips lang=cpp site=leetcode.com title="Minimum Number of K Consecutive Bit Flips"
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        int flips = 0, currentFlip = 0;

        for (int i = 0; i < n; i++) {
            currentFlip += diff[i];
            int currentVal = (nums[i] + currentFlip) % 2;
            if (currentVal == 0) {
                if (i + k > n) return -1;
                flips++;
                currentFlip++;
                diff[i + k]--;
            }
        }

        return flips;
    }
};
