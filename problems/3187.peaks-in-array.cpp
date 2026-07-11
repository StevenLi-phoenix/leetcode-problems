// @leetcode id=3187 questionId=3438 slug=peaks-in-array lang=cpp site=leetcode.com title="Peaks in Array"
class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> bit(n + 1, 0);
        auto update = [&](int i, int delta) {
            for (i++; i <= n; i += i & (-i)) bit[i] += delta;
        };
        auto prefixSum = [&](int i) {
            int res = 0;
            for (i++; i > 0; i -= i & (-i)) res += bit[i];
            return res;
        };

        vector<char> isPeak(n, 0);
        auto peakAt = [&](int i) {
            return i > 0 && i < n - 1 && nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
        };
        auto setPeak = [&](int i) {
            bool p = peakAt(i);
            if (p != (bool)isPeak[i]) {
                update(i, p ? 1 : -1);
                isPeak[i] = p;
            }
        };
        for (int i = 1; i < n - 1; i++) setPeak(i);

        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int l = q[1], r = q[2];
                if (r - l < 2) ans.push_back(0);
                else ans.push_back(prefixSum(r - 1) - prefixSum(l));
            } else {
                int idx = q[1], val = q[2];
                nums[idx] = val;
                for (int i = idx - 1; i <= idx + 1; i++)
                    if (i > 0 && i < n - 1) setPeak(i);
            }
        }
        return ans;
    }
};
