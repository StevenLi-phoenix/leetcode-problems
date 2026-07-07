// @leetcode id=3352 questionId=3631 slug=count-k-reducible-numbers-less-than-n lang=cpp site=leetcode.com title="Count K-Reducible Numbers Less Than N"
class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        const long long MOD = 1e9 + 7;
        int L = s.size();

        // steps[c] = operations to reduce c to 1
        vector<int> steps(L + 1, 0);
        for (int c = 2; c <= L; ++c) {
            steps[c] = steps[__builtin_popcount(c)] + 1;
        }

        // popcount c (>=1) is good if a number with that popcount reduces
        // within k ops: 1 op to reach c, then steps[c] more.
        vector<bool> good(L + 1, false);
        for (int c = 1; c <= L; ++c) {
            good[c] = (1 + steps[c] <= k);
        }

        vector<vector<long long>> C(L + 1, vector<long long>(L + 1, 0));
        for (int i = 0; i <= L; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        // count numbers < n with popcount == c, summed over good c
        long long ans = 0;
        int onesSoFar = 0;
        for (int i = 0; i < L; ++i) {
            if (s[i] == '1') {
                int remaining = L - i - 1;
                for (int extra = 0; extra <= remaining; ++extra) {
                    int c = onesSoFar + extra;
                    if (c >= 1 && c <= L && good[c]) {
                        ans = (ans + C[remaining][extra]) % MOD;
                    }
                }
                ++onesSoFar;
            }
        }

        // exclude x = 0 case is implicit (c >= 1); numbers equal to n excluded by construction
        return (int)ans;
    }
};
