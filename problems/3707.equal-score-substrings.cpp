// @leetcode id=3707 questionId=4052 slug=equal-score-substrings lang=cpp site=leetcode.com title="Equal Score Substrings"
class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();
        int total = 0;
        for (char c : s) total += (c - 'a' + 1);
        
        int prefixSum = 0;
        for (int i = 0; i < n - 1; i++) {
            prefixSum += (s[i] - 'a' + 1);
            if (2 * prefixSum == total) return true;
        }
        return false;
    }
};
