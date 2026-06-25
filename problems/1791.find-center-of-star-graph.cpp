// @leetcode id=1791 questionId=1916 slug=find-center-of-star-graph lang=cpp site=leetcode.com title="Find Center of Star Graph"
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }
        return edges[0][1];
    }
};
