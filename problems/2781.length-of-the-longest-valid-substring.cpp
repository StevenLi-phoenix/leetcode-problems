// @leetcode id=2781 questionId=2884 slug=length-of-the-longest-valid-substring lang=cpp site=leetcode.com title="Length of the Longest Valid Substring"
class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> bad(forbidden.begin(), forbidden.end());
        int n = word.size();
        int left = 0;
        int best = 0;

        for (int right = 0; right < n; right++) {
            int maxLen = min(10, right - left + 1);
            for (int len = 1; len <= maxLen; len++) {
                string sub = word.substr(right - len + 1, len);
                if (bad.count(sub)) {
                    left = max(left, right - len + 2);
                    break;
                }
            }
            best = max(best, right - left + 1);
        }

        return best;
    }
};
