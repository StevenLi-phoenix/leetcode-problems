// @leetcode id=2418 questionId=2502 slug=sort-the-people lang=cpp site=leetcode.com title="Sort the People"
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return heights[a] > heights[b];
        });

        vector<string> result(n);
        for (int i = 0; i < n; i++) result[i] = names[idx[i]];
        return result;
    }
};
