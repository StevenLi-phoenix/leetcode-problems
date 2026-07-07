// @leetcode id=3825 questionId=4032 slug=longest-strictly-increasing-subsequence-with-non-zero-bitwise-and lang=cpp site=leetcode.com title="Longest Strictly Increasing Subsequence With Non-Zero Bitwise AND"
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int best = 0;
        // non-zero AND <=> some bit is set in every chosen element;
        // try each bit, run LIS on the filtered subsequence
        for (int bit = 0; bit < 30; ++bit) {
            vector<int> tails;
            for (int v : nums) {
                if (!(v & (1 << bit))) continue;
                auto it = lower_bound(tails.begin(), tails.end(), v);
                if (it == tails.end()) tails.push_back(v);
                else *it = v;
            }
            best = max(best, (int)tails.size());
        }
        return best;
    }
};
