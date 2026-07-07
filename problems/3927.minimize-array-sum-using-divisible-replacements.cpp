// @leetcode id=3927 questionId=4301 slug=minimize-array-sum-using-divisible-replacements lang=cpp site=leetcode.com title="Minimize Array Sum Using Divisible Replacements"
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> present(maxVal + 1, false);
        for (int v : nums) present[v] = true;

        vector<int> root(maxVal + 1, -1);
        for (int v = 1; v <= maxVal; ++v) {
            if (!present[v]) continue;
            if (root[v] == -1) root[v] = v;
            for (long long m = (long long)v * 2; m <= maxVal; m += v) {
                if (present[m] && root[m] == -1) {
                    root[m] = root[v];
                }
            }
        }

        long long total = 0;
        for (int v : nums) total += root[v];
        return total;
    }
};
