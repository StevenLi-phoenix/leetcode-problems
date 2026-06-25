// @leetcode id=3548 questionId=3850 slug=equal-sum-grid-partition-ii lang=cpp site=leetcode.com title="Equal Sum Grid Partition II"
class Solution {
    public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    long long total = 0;
    for (auto& row : grid) for (int v : row) total += v;
    // horizontal cuts
    {
    unordered_map<int,int> topF, botF;
    for (auto& row : grid) for (int v : row) botF[v]++;
    long long topS = 0;
    for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < n; j++) {
    topF[grid[i][j]]++;
    botF[grid[i][j]]--;
    if (botF[grid[i][j]] == 0) botF.erase(grid[i][j]);
    }
    topS += accumulate(grid[i].begin(), grid[i].end(), 0LL);
    long long botS = total - topS;
    if (topS == botS) return true;
    long long need = 0;
    bool inTop = false;
    if (topS > botS) { need = topS - botS; inTop = true; }
    else { need = botS - topS; inTop = false; }
    if (need <= 0 || need > 1e5) continue;
    int nv = (int)need;
    if (inTop) {
    int rt = i + 1;
    if (rt >= 2 && n >= 2) {
    if (topF.count(nv)) return true;
    } else if (rt == 1 && n >= 2) {
    if (grid[0][0] == nv || grid[0][n-1] == nv) return true;
    } else if (n == 1 && rt >= 2) {
    if (grid[0][0] == nv || grid[i][0] == nv) return true;
    }
    } else {
    int rb = m - i - 1;
    if (rb >= 2 && n >= 2) {
    if (botF.count(nv)) return true;
    } else if (rb == 1 && n >= 2) {
    if (grid[m-1][0] == nv || grid[m-1][n-1] == nv) return true;
    } else if (n == 1 && rb >= 2) {
    if (grid[i+1][0] == nv || grid[m-1][0] == nv) return true;
    }
    }
    }
    }
    // vertical cuts
    {
    unordered_map<int,int> leftF, rightF;
    for (auto& row : grid) for (int v : row) rightF[v]++;
    long long leftS = 0;
    vector<long long> colSum(n, 0);
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) colSum[j] += grid[i][j];
    for (int j = 0; j < n - 1; j++) {
    for (int i = 0; i < m; i++) {
    leftF[grid[i][j]]++;
    rightF[grid[i][j]]--;
    if (rightF[grid[i][j]] == 0) rightF.erase(grid[i][j]);
    }
    leftS += colSum[j];
    long long rightS = total - leftS;
    if (leftS == rightS) return true;
    long long need = 0;
    bool inLeft = false;
    if (leftS > rightS) { need = leftS - rightS; inLeft = true; }
    else { need = rightS - leftS; inLeft = false; }
    if (need <= 0 || need > 1e5) continue;
    int nv = (int)need;
    if (inLeft) {
    int cl = j + 1;
    if (cl >= 2 && m >= 2) {
    if (leftF.count(nv)) return true;
    } else if (cl == 1 && m >= 2) {
    if (grid[0][0] == nv || grid[m-1][0] == nv) return true;
    } else if (m == 1 && cl >= 2) {
    if (grid[0][0] == nv || grid[0][j] == nv) return true;
    }
    } else {
    int cr = n - j - 1;
    if (cr >= 2 && m >= 2) {
    if (rightF.count(nv)) return true;
    } else if (cr == 1 && m >= 2) {
    if (grid[0][n-1] == nv || grid[m-1][n-1] == nv) return true;
    } else if (m == 1 && cr >= 2) {
    if (grid[0][j+1] == nv || grid[0][n-1] == nv) return true;
    }
    }
    }
    }
    return false;
    }
    };
