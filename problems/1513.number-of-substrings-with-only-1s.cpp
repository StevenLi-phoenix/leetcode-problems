// @leetcode id=1513 questionId=1636 slug=number-of-substrings-with-only-1s lang=cpp site=leetcode.com title="Number of Substrings With Only 1s"
class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        long long count = 0;
        for (char c : s) {
            if (c == '1') {
                count++;
                ans = (ans + count) % MOD;
            } else {
                count = 0;
            }
        }
        return ans;
    }
};
