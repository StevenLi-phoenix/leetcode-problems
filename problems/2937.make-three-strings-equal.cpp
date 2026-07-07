// @leetcode id=2937 questionId=3207 slug=make-three-strings-equal lang=cpp site=leetcode.com title="Make Three Strings Equal"
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int minLen = min({s1.size(), s2.size(), s3.size()});
        int p = 0;
        while (p < minLen && s1[p] == s2[p] && s2[p] == s3[p]) ++p;

        if (p == 0) return -1;
        return (int)(s1.size() + s2.size() + s3.size()) - 3 * p;
    }
};
