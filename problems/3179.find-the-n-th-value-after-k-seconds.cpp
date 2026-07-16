// @leetcode id=3179 questionId=3422 slug=find-the-n-th-value-after-k-seconds lang=cpp site=leetcode.com title="Find the N-th Value After K Seconds"
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const long long MOD = 1e9 + 7;
        vector<long long> a(n, 1);
        for (int s = 0; s < k; s++) {
            for (int i = 1; i < n; i++) {
                a[i] = (a[i] + a[i - 1]) % MOD;
            }
        }
        return (int)a[n - 1];
    }
};
