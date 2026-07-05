// @leetcode id=3404 questionId=3699 slug=count-special-subsequences lang=cpp site=leetcode.com title="Count Special Subsequences"
class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, long long> pairCounts;
        long long ans = 0;

        auto keyOf = [](int a, int b) {
            int g = gcd(a, b);
            return (a / g) * 1001 + (b / g);
        };

        for (int r = 0; r < n; ++r) {
            int qNew = r - 2;
            if (qNew >= 0) {
                for (int p = 0; p <= qNew - 2; ++p) {
                    pairCounts[keyOf(nums[p], nums[qNew])]++;
                }
            }
            for (int s = r + 2; s < n; ++s) {
                auto it = pairCounts.find(keyOf(nums[s], nums[r]));
                if (it != pairCounts.end()) ans += it->second;
            }
        }
        return ans;
    }
};
