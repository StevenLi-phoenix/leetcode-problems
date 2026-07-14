// @leetcode id=2923 questionId=3188 slug=find-champion-i lang=cpp site=leetcode.com title="Find Champion I"
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            bool champion = true;
            for (int j = 0; j < n; j++) {
                if (i != j && grid[j][i] == 1) { champion = false; break; }
            }
            if (champion) return i;
        }
        return -1;
    }
};
