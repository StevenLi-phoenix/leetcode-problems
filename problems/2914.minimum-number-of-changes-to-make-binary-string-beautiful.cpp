// @leetcode id=2914 questionId=3174 slug=minimum-number-of-changes-to-make-binary-string-beautiful lang=cpp site=leetcode.com title="Minimum Number of Changes to Make Binary String Beautiful"
class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        for (int i = 0; i < (int)s.size(); i += 2) {
            if (s[i] != s[i + 1]) changes++;
        }
        return changes;
    }
};
