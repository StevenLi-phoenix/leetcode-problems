// @leetcode id=3090 questionId=3349 slug=maximum-length-substring-with-two-occurrences lang=cpp site=leetcode.com title="Maximum Length Substring With Two Occurrences"
class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> count(26, 0);
        int left = 0, best = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            count[s[right] - 'a']++;
            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
