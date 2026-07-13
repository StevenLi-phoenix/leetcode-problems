// @leetcode id=1576 questionId=1698 slug=replace-all-s-to-avoid-consecutive-repeating-characters lang=cpp site=leetcode.com title="Replace All ?'s to Avoid Consecutive Repeating Characters"
class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') continue;
            for (char c = 'a'; c <= 'c'; c++) {
                if ((i > 0 && s[i - 1] == c) || (i < n - 1 && s[i + 1] == c)) continue;
                s[i] = c;
                break;
            }
        }
        return s;
    }
};
