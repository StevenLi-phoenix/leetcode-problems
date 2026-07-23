// @leetcode id=3982 questionId=4356 slug=sum-of-integers-with-maximum-digit-range lang=cpp site=leetcode.com title="Sum of Integers with Maximum Digit Range"
class Solution {
public:
    int digitRange(int x) {
        int mn = 9, mx = 0;
        while (x > 0) {
            int d = x % 10;
            mn = min(mn, d);
            mx = max(mx, d);
            x /= 10;
        }
        return mx - mn;
    }

    int maxDigitRange(vector<int>& nums) {
        int best = -1;
        for (int x : nums) best = max(best, digitRange(x));

        long long sum = 0;
        for (int x : nums) {
            if (digitRange(x) == best) sum += x;
        }
        return (int)sum;
    }
};
