// @leetcode id=3210 questionId=3468 slug=find-the-encrypted-string lang=cpp site=leetcode.com title="Find the Encrypted String"
class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string result(n, ' ');
        for (int i = 0; i < n; ++i) {
            result[i] = s[(i + k) % n];
        }
        return result;
    }
};
