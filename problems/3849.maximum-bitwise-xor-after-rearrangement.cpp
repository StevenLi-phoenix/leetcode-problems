// @leetcode id=3849 questionId=4044 slug=maximum-bitwise-xor-after-rearrangement lang=cpp site=leetcode.com title="Maximum Bitwise XOR After Rearrangement"
class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.size();
        int onesT = count(t.begin(), t.end(), '1');
        int zerosT = n - onesT;

        string result(n, '0');
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (onesT > 0) { result[i] = '1'; onesT--; }
                else { result[i] = '0'; zerosT--; }
            } else {
                if (zerosT > 0) { result[i] = '1'; zerosT--; }
                else { result[i] = '0'; onesT--; }
            }
        }
        return result;
    }
};
