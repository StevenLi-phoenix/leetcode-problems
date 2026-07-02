// @leetcode id=2414 questionId=2492 slug=length-of-the-longest-alphabetical-continuous-substring lang=cpp site=leetcode.com title="Length of the Longest Alphabetical Continuous Substring"
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int best = 1, cur = 1;
        for (int i = 1; i < (int)s.size(); i++) {
            if (s[i] == s[i - 1] + 1) cur++;
            else cur = 1;
            best = max(best, cur);
        }
        return best;
    }
};
