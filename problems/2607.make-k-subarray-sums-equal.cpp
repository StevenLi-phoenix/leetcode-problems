// @leetcode id=2607 questionId=2670 slug=make-k-subarray-sums-equal lang=cpp site=leetcode.com title="Make K-Subarray Sums Equal"
class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        int g = gcd(n, k);

        long long ans = 0;
        for (int r = 0; r < g; ++r) {
            vector<int> group;
            for (int i = r; i < n; i += g) group.push_back(arr[i]);
            sort(group.begin(), group.end());
            int median = group[group.size() / 2];
            for (int v : group) ans += abs((long long)v - median);
        }
        return ans;
    }
};
