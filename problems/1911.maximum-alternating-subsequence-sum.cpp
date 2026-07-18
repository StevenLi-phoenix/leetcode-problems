// @leetcode id=1911 questionId=2022 slug=maximum-alternating-subsequence-sum lang=cpp site=leetcode.com title="Maximum Alternating Subsequence Sum"
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sumEven = 0, sumOdd = 0;
        for (int val : nums) {
            long long newEven = max(sumEven, sumOdd + val);
            long long newOdd = max(sumOdd, sumEven - val);
            sumEven = newEven;
            sumOdd = newOdd;
        }
        return sumEven;
    }
};
