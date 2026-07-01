// @leetcode id=165 questionId=165 slug=compare-version-numbers lang=cpp site=leetcode.com title="Compare Version Numbers"
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n = version1.size(), m = version2.size();
        while (i < n || j < m) {
            long long a = 0, b = 0;
            while (i < n && version1[i] != '.') a = a * 10 + (version1[i++] - '0');
            while (j < m && version2[j] != '.') b = b * 10 + (version2[j++] - '0');
            if (a != b) return a < b ? -1 : 1;
            i++; j++;
        }
        return 0;
    }
};
