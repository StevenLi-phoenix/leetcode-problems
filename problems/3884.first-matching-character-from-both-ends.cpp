// @leetcode id=3884 questionId=4264 slug=first-matching-character-from-both-ends lang=cpp site=leetcode.com title="First Matching Character From Both Ends"
class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == s[n - i - 1]) return i;
        }
        return -1;
    }
};
