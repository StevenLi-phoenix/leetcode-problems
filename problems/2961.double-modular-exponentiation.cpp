// @leetcode id=2961 questionId=3234 slug=double-modular-exponentiation lang=cpp site=leetcode.com title="Double Modular Exponentiation"
class Solution {
public:
    long long power(long long base, long long exp, long long mod) {
        base %= mod;
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> res;
        for (int i = 0; i < (int)variables.size(); i++) {
            long long a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3];
            long long step1 = power(a, b, 10);
            long long step2 = power(step1, c, m);
            if (step2 == target) res.push_back(i);
        }
        return res;
    }
};
