// @leetcode id=3723 questionId=4084 slug=maximize-sum-of-squares-of-digits lang=cpp site=leetcode.com title="Maximize Sum of Squares of Digits"
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        long long maxSum = (long long)num * 9;
        if (sum > maxSum) return "";

        int nines = sum / 9;
        int remainder = sum % 9;
        int extra = remainder > 0 ? 1 : 0;
        int zeros = num - nines - extra;

        string result;
        result.append(nines, '9');
        if (extra) result.push_back('0' + remainder);
        result.append(zeros, '0');
        return result;
    }
};
