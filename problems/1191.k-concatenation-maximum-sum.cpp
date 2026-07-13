// @leetcode id=1191 questionId=1299 slug=k-concatenation-maximum-sum lang=cpp site=leetcode.com title="K-Concatenation Maximum Sum"
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const long long MOD = 1'000'000'007;

        auto kadane = [](const vector<int>& a) {
            long long best = 0, cur = 0;
            for (int x : a) {
                cur = max(0LL, cur) + x;
                best = max(best, cur);
            }
            return best;
        };

        long long total = 0;
        for (int x : arr) total += x;

        if (k == 1) return (int)(kadane(arr) % MOD);

        vector<int> doubled = arr;
        doubled.insert(doubled.end(), arr.begin(), arr.end());
        long long best = kadane(doubled);
        if (total > 0) best += (long long)(k - 2) * total;

        return (int)(best % MOD);
    }
};
