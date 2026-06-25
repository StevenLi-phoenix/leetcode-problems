// @leetcode id=3300 questionId=3606 slug=minimum-element-after-replacement-with-digit-sum lang=cpp site=leetcode.com title="Minimum Element After Replacement With Digit Sum"
class Solution {
public:
    int minElement(vector<int>& nums) {
        int minVal = INT_MAX;
        for (int n : nums) {
            int s = 0;
            while (n > 0) {
                s += n % 10;
                n /= 10;
            }
            minVal = min(minVal, s);
        }
        return minVal;
    }
};
