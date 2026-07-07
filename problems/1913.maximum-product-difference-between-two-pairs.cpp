// @leetcode id=1913 questionId=2042 slug=maximum-product-difference-between-two-pairs lang=cpp site=leetcode.com title="Maximum Product Difference Between Two Pairs"
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = 0, max2 = 0;           // two largest
        int min1 = INT_MAX, min2 = INT_MAX; // two smallest

        for (int v : nums) {
            if (v > max1) {
                max2 = max1;
                max1 = v;
            } else if (v > max2) {
                max2 = v;
            }

            if (v < min1) {
                min2 = min1;
                min1 = v;
            } else if (v < min2) {
                min2 = v;
            }
        }
        return max1 * max2 - min1 * min2;
    }
};
