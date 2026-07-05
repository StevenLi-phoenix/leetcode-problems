// @leetcode id=1560 questionId=1682 slug=most-visited-sector-in-a-circular-track lang=cpp site=leetcode.com title="Most Visited Sector in  a Circular Track"
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int start = rounds.front(), end = rounds.back();
        vector<int> ans;
        if (start <= end) {
            for (int i = start; i <= end; ++i) ans.push_back(i);
        } else {
            for (int i = 1; i <= end; ++i) ans.push_back(i);
            for (int i = start; i <= n; ++i) ans.push_back(i);
        }
        return ans;
    }
};
