// @leetcode id=455 questionId=455 slug=assign-cookies lang=cpp site=leetcode.com title="Assign Cookies"
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        while (i < (int)g.size() && j < (int)s.size()) {
            if (s[j] >= g[i]) i++;
            j++;
        }
        return i;
    }
};
