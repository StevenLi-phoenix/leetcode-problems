// @leetcode id=1447 questionId=1543 slug=simplified-fractions lang=cpp site=leetcode.com title="Simplified Fractions"
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int d = 2; d <= n; ++d) {
            for (int num = 1; num < d; ++num) {
                if (gcd(num, d) == 1) {
                    ans.push_back(to_string(num) + "/" + to_string(d));
                }
            }
        }
        return ans;
    }
};
