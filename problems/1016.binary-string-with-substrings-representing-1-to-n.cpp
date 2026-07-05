// @leetcode id=1016 questionId=1065 slug=binary-string-with-substrings-representing-1-to-n lang=cpp site=leetcode.com title="Binary String With Substrings Representing 1 To N"
class Solution {
public:
    bool queryString(string s, int n) {
        long long len = s.size();

        // s has at most len*(len+1)/2 distinct substrings, so if n exceeds that,
        // there simply aren't enough distinct substrings for every k in [1, n].
        if ((long long)n > len * (len + 1) / 2) return false;

        for (long long k = 1; k <= n; ++k) {
            string bin;
            long long v = k;
            while (v > 0) {
                bin += char('0' + (v & 1));
                v >>= 1;
            }
            reverse(bin.begin(), bin.end());
            if (s.find(bin) == string::npos) return false;
        }
        return true;
    }
};
