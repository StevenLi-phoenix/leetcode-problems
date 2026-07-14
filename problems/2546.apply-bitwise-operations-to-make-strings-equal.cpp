// @leetcode id=2546 questionId=2632 slug=apply-bitwise-operations-to-make-strings-equal lang=cpp site=leetcode.com title="Apply Bitwise Operations to Make Strings Equal"
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        bool sHasOne = s.find('1') != string::npos;
        bool tHasOne = target.find('1') != string::npos;
        return sHasOne == tHasOne;
    }
};
