// @leetcode id=482 questionId=482 slug=license-key-formatting lang=cpp site=leetcode.com title="License Key Formatting"
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string chars;
        for (char c : s) {
            if (c != '-') chars += toupper(c);
        }

        int n = chars.size();
        int firstGroupLen = n % k == 0 ? k : n % k;

        string result;
        int i = 0;
        while (i < n) {
            if (!result.empty()) result += '-';
            int len = (i == 0) ? firstGroupLen : k;
            result += chars.substr(i, len);
            i += len;
        }
        return result;
    }
};
