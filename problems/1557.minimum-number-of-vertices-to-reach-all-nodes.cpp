// @leetcode id=1557 questionId=1661 slug=minimum-number-of-vertices-to-reach-all-nodes lang=cpp site=leetcode.com title="Minimum Number of Vertices to Reach All Nodes"
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> hasIncoming(n, false);
        for (auto& e : edges) hasIncoming[e[1]] = true;

        vector<int> result;
        for (int i = 0; i < n; i++) if (!hasIncoming[i]) result.push_back(i);
        return result;
    }
};
