// @leetcode id=1878 questionId=1990 slug=get-biggest-three-rhombus-sums-in-a-grid lang=cpp site=leetcode.com title="Get Biggest Three Rhombus Sums in a Grid"
class Solution {
    public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    set<int> top;
    for (int r = 0; r < m; r++) {
    for (int c = 0; c < n; c++) {
    top.insert(grid[r][c]);
    if ((int)top.size() > 3) top.erase(top.begin());
    int maxs = min({r, m-1-r, c, n-1-c});
    for (int s = 1; s <= maxs; s++) {
    int sum = 0;
    for (int i = 0; i < s; i++) {
    sum += grid[r-s+i][c+i];
    sum += grid[r+i][c+s-i];
    sum += grid[r+s-i][c-i];
    sum += grid[r-i][c-s+i];
    }
    top.insert(sum);
    if ((int)top.size() > 3) top.erase(top.begin());
    }
    }
    }
    return vector<int>(top.rbegin(), top.rend());
    }
    };
