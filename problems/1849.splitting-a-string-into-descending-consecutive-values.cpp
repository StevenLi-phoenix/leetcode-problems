// @leetcode id=1849 questionId=1976 slug=splitting-a-string-into-descending-consecutive-values lang=cpp site=leetcode.com title="Splitting a String Into Descending Consecutive Values"
class Solution {
public:
    bool backtrack(const string& s, int start, unsigned long long prev, bool hasPrev, int count) {
        if (start == (int)s.size()) return hasPrev && count >= 2;
        for (int len = 1; start + len <= (int)s.size(); len++) {
            string sub = s.substr(start, len);
            if (sub.size() > 19) break;
            unsigned long long val = stoull(sub);
            if (!hasPrev || val + 1 == prev) {
                if (backtrack(s, start + len, val, true, count + 1)) return true;
            }
        }
        return false;
    }

    bool splitString(string s) {
        return backtrack(s, 0, 0, false, 0);
    }
};
