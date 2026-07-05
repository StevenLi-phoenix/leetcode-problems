// @leetcode id=827 questionId=854 slug=making-a-large-island lang=cpp site=leetcode.com title="Making A Large Island"
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> id(n, vector<int>(n, 0));
        unordered_map<int, int> areaOf;
        int nextId = 2;
        int best = 0;

        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && id[i][j] == 0) {
                    int area = 0;
                    vector<pair<int,int>> stack = {{i,j}};
                    id[i][j] = nextId;
                    while (!stack.empty()) {
                        auto [x, y] = stack.back();
                        stack.pop_back();
                        ++area;
                        for (auto& d : dirs) {
                            int nx = x + d.first, ny = y + d.second;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1 && id[nx][ny] == 0) {
                                id[nx][ny] = nextId;
                                stack.push_back({nx, ny});
                            }
                        }
                    }
                    areaOf[nextId] = area;
                    best = max(best, area);
                    ++nextId;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighborIds;
                    for (auto& d : dirs) {
                        int nx = i + d.first, ny = j + d.second;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && id[nx][ny] != 0) {
                            neighborIds.insert(id[nx][ny]);
                        }
                    }
                    int total = 1;
                    for (int nid : neighborIds) total += areaOf[nid];
                    best = max(best, total);
                }
            }
        }

        return best;
    }
};
