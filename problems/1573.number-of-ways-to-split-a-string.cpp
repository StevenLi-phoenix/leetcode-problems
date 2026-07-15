// @leetcode id=1573 questionId=1678 slug=number-of-ways-to-split-a-string lang=cpp site=leetcode.com title="Number of Ways to Split a String"
class Solution {
public:
    int numWays(string s) {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        long long total = count(s.begin(), s.end(), '1');

        if (total == 0) {
            long long ways = (long long)(n - 1) * (n - 2) / 2 % MOD;
            return (int)ways;
        }
        if (total % 3 != 0) return 0;

        long long each = total / 3;
        long long cum = 0;
        long long firstLo = -1, firstHi = -1, secondLo = -1, secondHi = -1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1') cum++;
            if (cum == each) {
                if (firstLo == -1) firstLo = i;
                firstHi = i;
            }
            if (cum == 2 * each) {
                if (secondLo == -1) secondLo = i;
                secondHi = i;
            }
        }

        long long waysFirst = firstHi - firstLo + 1;
        long long waysSecond = secondHi - secondLo + 1;
        return (int)((waysFirst * waysSecond) % MOD);
    }
};
