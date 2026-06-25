// @leetcode id=830 questionId=857 slug=positions-of-large-groups lang=cpp site=leetcode.com title="Positions of Large Groups"
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        int n = s.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            if (j - i >= 3) {
                result.push_back({i, j - 1});
            }
            i = j;
        }
        return result;
    }
};
