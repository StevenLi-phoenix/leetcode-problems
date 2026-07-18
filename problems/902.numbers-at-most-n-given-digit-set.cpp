// @leetcode id=902 questionId=938 slug=numbers-at-most-n-given-digit-set lang=cpp site=leetcode.com title="Numbers At Most N Given Digit Set"
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int L = s.size();
        int d = digits.size();

        int ans = 0;
        for (int len = 1; len < L; len++) {
            int p = 1;
            for (int i = 0; i < len; i++) p *= d;
            ans += p;
        }

        for (int i = 0; i < L; i++) {
            bool matched = false;
            for (const string& dig : digits) {
                if (dig[0] < s[i]) {
                    int p = 1;
                    for (int j = i + 1; j < L; j++) p *= d;
                    ans += p;
                } else if (dig[0] == s[i]) {
                    matched = true;
                }
            }
            if (!matched) return ans;
        }

        return ans + 1;
    }
};
