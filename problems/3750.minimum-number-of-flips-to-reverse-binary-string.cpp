// @leetcode id=3750 questionId=4126 slug=minimum-number-of-flips-to-reverse-binary-string lang=cpp site=leetcode.com title="Minimum Number of Flips to Reverse Binary String"
class Solution {
public:
    int minimumFlips(int n) {
        string s;
        for (int t = n; t > 0; t /= 2) s += char('0' + (t & 1));
        reverse(s.begin(), s.end());

        string rev = s;
        reverse(rev.begin(), rev.end());

        int flips = 0;
        for (size_t i = 0; i < s.size(); i++) if (s[i] != rev[i]) flips++;
        return flips;
    }
};
