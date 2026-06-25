// @leetcode id=2600 questionId=2715 slug=k-items-with-the-maximum-sum lang=cpp site=leetcode.com title="K Items With the Maximum Sum"
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = 0;

        int take_ones = min(k, numOnes);
        sum += take_ones;
        k -= take_ones;

        int take_zeros = min(k, numZeros);
        k -= take_zeros;

        int take_neg_ones = min(k, numNegOnes);
        sum -= take_neg_ones;

        return sum;
    }
};
