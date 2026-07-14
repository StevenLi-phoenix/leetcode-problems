// @leetcode id=1750 questionId=1850 slug=minimum-length-of-string-after-deleting-similar-ends lang=cpp site=leetcode.com title="Minimum Length of String After Deleting Similar Ends"
class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j && s[i] == s[j]) {
            char c = s[i];
            while (i <= j && s[i] == c) i++;
            while (j >= i && s[j] == c) j--;
        }
        return j - i + 1;
    }
};
