// @leetcode id=1680 questionId=1800 slug=concatenation-of-consecutive-binary-numbers lang=cpp site=leetcode.com title="Concatenation of Consecutive Binary Numbers"
class Solution {
    public:
    int concatenatedBinary(int n) {
    long long result = 0;
    const int MOD = 1e9 + 7;
    int bits = 0;
    for (int i = 1; i <= n; i++) {
    if ((i & (i - 1)) == 0) bits++;
    result = ((result << bits) % MOD + i) % MOD;
    }
    return result;
    }
    };
