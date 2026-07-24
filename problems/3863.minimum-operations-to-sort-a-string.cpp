// @leetcode id=3863 questionId=4220 slug=minimum-operations-to-sort-a-string lang=cpp site=leetcode.com title="Minimum Operations to Sort a String"
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(), t.end());

        if (s == t) return 0;
        if (n == 2) return -1;

        if (s[0] == t[0] || s[n - 1] == t[n - 1]) return 1;

        char maxChar = t[n - 1];
        char minChar = t[0];
        int maxCount = count(s.begin(), s.end(), maxChar);
        int minCount = count(s.begin(), s.end(), minChar);

        bool uniqueMaxAtFront = (s[0] == maxChar && maxCount == 1);
        bool uniqueMinAtBack = (s[n - 1] == minChar && minCount == 1);

        if (!(uniqueMaxAtFront && uniqueMinAtBack)) return 2;
        return 3;
    }
};
