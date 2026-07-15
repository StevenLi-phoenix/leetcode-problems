// @leetcode id=2730 questionId=2786 slug=find-the-longest-semi-repetitive-substring lang=cpp site=leetcode.com title="Find the Longest Semi-Repetitive Substring"
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        int left = 0, pairs = 0, best = 1;
        for (int right = 1; right < n; right++) {
            if (s[right] == s[right - 1]) pairs++;
            while (pairs > 1) {
                if (s[left] == s[left + 1]) pairs--;
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
