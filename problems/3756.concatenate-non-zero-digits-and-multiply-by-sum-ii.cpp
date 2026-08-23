// @leetcode id=3756 questionId=4136 slug=concatenate-non-zero-digits-and-multiply-by-sum-ii lang=cpp site=leetcode.com title="Concatenate Non-Zero Digits and Multiply by Sum II"
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007LL;
        int m = s.size();
        vector<long long> P(m+1, 0), digitSum(m+1, 0);
        vector<int> cnt(m+1, 0);
        for (int i = 1; i <= m; i++) {
            int d = s[i-1] - '0';
            cnt[i] = cnt[i-1] + (d != 0 ? 1 : 0);
            digitSum[i] = digitSum[i-1] + d;
            if (d != 0) {
                P[i] = (P[i-1] * 10 + d) % MOD;
            } else {
                P[i] = P[i-1];
            }
        }
        vector<long long> pow10(m+1);
        pow10[0] = 1;
        for (int i = 1; i <= m; i++) pow10[i] = (pow10[i-1] * 10) % MOD;

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int k = cnt[r+1] - cnt[l];
            long long V = ( (P[r+1] - P[l] * pow10[k]) % MOD + MOD) % MOD;
            long long sum = digitSum[r+1] - digitSum[l];
            long long res = (V * (sum % MOD)) % MOD;
            ans.push_back((int)res);
        }
        return ans;
    }
};
