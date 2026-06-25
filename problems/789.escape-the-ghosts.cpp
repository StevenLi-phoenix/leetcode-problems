// @leetcode id=789 questionId=805 slug=escape-the-ghosts lang=cpp site=leetcode.com title="Escape The Ghosts"
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int myDist = abs(target[0]) + abs(target[1]);

        for (auto& ghost : ghosts) {
            int ghostDist = abs(target[0] - ghost[0]) + abs(target[1] - ghost[1]);
            if (ghostDist <= myDist) {
                return false;
            }
        }

        return true;
    }
};
