// @leetcode id=2124 questionId=2243 slug=check-if-all-as-appears-before-all-bs lang=cpp site=leetcode.com title="Check if All A's Appears Before All B's"
class Solution {
public:
    bool checkString(string s) {
        return s.find("ba") == string::npos;
    }
};
