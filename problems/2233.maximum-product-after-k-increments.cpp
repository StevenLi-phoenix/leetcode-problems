// @leetcode id=2233 questionId=2329 slug=maximum-product-after-k-increments lang=cpp site=leetcode.com title="Maximum Product After K Increments"
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        while (k > 0) {
            long long top = pq.top(); pq.pop();
            pq.push(top + 1);
            k--;
        }
        const long long MOD = 1e9 + 7;
        long long product = 1;
        while (!pq.empty()) {
            product = (product * (pq.top() % MOD)) % MOD;
            pq.pop();
        }
        return (int)product;
    }
};
