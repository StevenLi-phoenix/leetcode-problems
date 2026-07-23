// @leetcode id=1309 questionId=1434 slug=decrypt-string-from-alphabet-to-integer-mapping lang=cpp site=leetcode.com title="Decrypt String from Alphabet to Integer Mapping"
class Solution {
public:
    string freqAlphabets(string s) {
        string result;
        int n = s.size();
        int i = n - 1;
        while (i >= 0) {
            if (s[i] == '#') {
                int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                result += ('a' + num - 1);
                i -= 3;
            } else {
                int num = s[i] - '0';
                result += ('a' + num - 1);
                i -= 1;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
