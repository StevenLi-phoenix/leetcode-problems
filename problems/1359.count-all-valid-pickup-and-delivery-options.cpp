// @leetcode id=1359 questionId=1461 slug=count-all-valid-pickup-and-delivery-options lang=cpp site=leetcode.com title="Count All Valid Pickup and Delivery Options"
class Solution {
public:
    int countOrders(int n) {
        const long long MOD = 1e9 + 7;
        long long ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans = (ans * (2LL * i - 1) % MOD) * i % MOD;
        }
        return (int)ans;
    }
};
