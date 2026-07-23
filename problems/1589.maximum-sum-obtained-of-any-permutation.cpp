// @leetcode id=1589 questionId=1695 slug=maximum-sum-obtained-of-any-permutation lang=cpp site=leetcode.com title="Maximum Sum Obtained of Any Permutation"
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> diff(n + 1, 0);

        for (auto& r : requests) {
            diff[r[0]]++;
            diff[r[1] + 1]--;
        }

        vector<long long> count(n);
        long long running = 0;
        for (int i = 0; i < n; i++) {
            running += diff[i];
            count[i] = running;
        }

        sort(count.begin(), count.end());
        sort(nums.begin(), nums.end());

        long long total = 0;
        for (int i = 0; i < n; i++) {
            total = (total + (long long)nums[i] * count[i]) % MOD;
        }

        return (int)total;
    }
};
