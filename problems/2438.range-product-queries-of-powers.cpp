// @leetcode id=2438 questionId=2529 slug=range-product-queries-of-powers lang=cpp site=leetcode.com title="Range Product Queries of Powers"
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // Extract powers of 2
        vector<int> powers;
        for (int i = 0; i < 30; i++) {
            if (n & (1 << i)) {
                powers.push_back(i);
            }
        }
        
        vector<int> ans;
        for (auto& q : queries) {
            int left = q[0], right = q[1];
            long long prod = 1;
            for (int i = left; i <= right; i++) {
                prod = prod * power(2, powers[i], MOD) % MOD;
            }
            ans.push_back(prod);
        }
        return ans;
    }
};
