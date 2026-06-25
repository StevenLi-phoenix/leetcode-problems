// @leetcode id=1653 questionId=1756 slug=minimum-deletions-to-make-string-balanced lang=cpp site=leetcode.com title="Minimum Deletions to Make String Balanced"
class Solution {
    public:
    int minimumDeletions(string s) {
    int b_count = 0, dp = 0;
    for (char c : s) {
    if (c == 'b') b_count++;
    else dp = min(dp + 1, b_count);
    }
    return dp;
    }
    };
