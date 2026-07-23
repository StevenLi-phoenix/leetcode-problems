// @leetcode id=1684 questionId=1786 slug=count-the-number-of-consistent-strings lang=cpp site=leetcode.com title="Count the Number of Consistent Strings"
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for (char c : allowed) mask |= (1 << (c - 'a'));

        int count = 0;
        for (const string& w : words) {
            bool ok = true;
            for (char c : w) {
                if (!(mask & (1 << (c - 'a')))) { ok = false; break; }
            }
            if (ok) count++;
        }
        return count;
    }
};
