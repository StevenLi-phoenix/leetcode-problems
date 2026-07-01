// @leetcode id=3697 questionId=4039 slug=compute-decimal-representation lang=cpp site=leetcode.com title="Compute Decimal Representation"
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> res;
        long long place = 1;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) res.push_back(digit * place);
            n /= 10;
            place *= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
