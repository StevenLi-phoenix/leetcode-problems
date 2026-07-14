// @leetcode id=2924 questionId=3189 slug=find-champion-ii lang=cpp site=leetcode.com title="Find Champion II"
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto& e : edges) indegree[e[1]]++;

        int champion = -1, count = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) { champion = i; count++; }
        }
        return count == 1 ? champion : -1;
    }
};
