// @leetcode id=2090 questionId=2211 slug=k-radius-subarray-averages lang=cpp site=leetcode.com title="K Radius Subarray Averages"
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, -1);
        if ((long long)2 * k + 1 > n) return result;

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        long long windowSize = 2LL * k + 1;
        for (int i = k; i + k < n; i++) {
            long long sum = prefix[i + k + 1] - prefix[i - k];
            result[i] = (int)(sum / windowSize);
        }
        return result;
    }
};
