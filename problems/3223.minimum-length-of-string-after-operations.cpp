// @leetcode id=3223 questionId=3455 slug=minimum-length-of-string-after-operations lang=cpp site=leetcode.com title="Minimum Length of String After Operations"
class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int total = 0;
        for (int f : freq) {
            if (f == 0) continue;
            total += (f % 2 == 0) ? 2 : 1;
        }
        return total;
    }
};
