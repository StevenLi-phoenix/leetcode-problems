// @leetcode id=1888 questionId=2017 slug=minimum-number-of-flips-to-make-the-binary-string-alternating lang=cpp site=leetcode.com title="Minimum Number of Flips to Make the Binary String Alternating"
class Solution {
    public:
    int minFlips(string s) {
    int n = s.size();
    string ss = s + s;
    int diff0 = 0, diff1 = 0;
    int ans = n;
    for (int i = 0; i < (int)ss.size(); i++) {
    int c = ss[i] - '0';
    if (c != i % 2) diff0++;
    if (c != (i + 1) % 2) diff1++;
    if (i >= n) {
    int old = ss[i - n] - '0';
    if (old != (i - n) % 2) diff0--;
    if (old != (i - n + 1) % 2) diff1--;
    }
    if (i >= n - 1) ans = min(ans, min(diff0, diff1));
    }
    return ans;
    }
    };
