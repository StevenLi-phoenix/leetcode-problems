// @leetcode id=791 questionId=807 slug=custom-sort-string lang=cpp site=leetcode.com title="Custom Sort String"
class Solution {
public:
    string customSortString(string order, string s) {
        int rank[26];
        fill(rank, rank + 26, 26); // chars not in order sort after everything
        for (int i = 0; i < (int)order.size(); i++) rank[order[i] - 'a'] = i;

        sort(s.begin(), s.end(), [&](char a, char b) {
            return rank[a - 'a'] < rank[b - 'a'];
        });
        return s;
    }
};
