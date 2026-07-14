// @leetcode id=2354 questionId=2430 slug=number-of-excellent-pairs lang=cpp site=leetcode.com title="Number of Excellent Pairs"
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> distinct(nums.begin(), nums.end());
        vector<int> bits;
        for (int v : distinct) bits.push_back(__builtin_popcount(v));
        sort(bits.begin(), bits.end());

        int n = bits.size();
        long long total = 0;
        for (int b : bits) {
            int need = k - b;
            int idx = lower_bound(bits.begin(), bits.end(), need) - bits.begin();
            total += (n - idx);
        }
        return total;
    }
};
