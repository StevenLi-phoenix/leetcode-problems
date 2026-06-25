// @leetcode id=28 questionId=28 slug=find-the-index-of-the-first-occurrence-in-a-string lang=cpp site=leetcode.com title="Find the Index of the First Occurrence in a String"
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        if (m == 0) return 0;
        if (m > n) return -1;
        
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i;
        }
        
        return -1;
    }
};
