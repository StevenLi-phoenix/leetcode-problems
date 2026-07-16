// @leetcode id=848 questionId=878 slug=shifting-letters lang=cpp site=leetcode.com title="Shifting Letters"
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        long long suffix = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffix = (suffix + shifts[i]) % 26;
            int c = (s[i] - 'a' + suffix) % 26;
            s[i] = 'a' + c;
        }
        return s;
    }
};
