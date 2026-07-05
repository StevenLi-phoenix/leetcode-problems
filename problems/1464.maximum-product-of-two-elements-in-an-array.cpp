// @leetcode id=1464 questionId=1574 slug=maximum-product-of-two-elements-in-an-array lang=cpp site=leetcode.com title="Maximum Product of Two Elements in an Array"
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 0, second = 0;
        for (int x : nums) {
            if (x > first) { second = first; first = x; }
            else if (x > second) second = x;
        }
        return (first - 1) * (second - 1);
    }
};
