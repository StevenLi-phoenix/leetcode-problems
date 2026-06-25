// @leetcode id=1536 questionId=1658 slug=minimum-swaps-to-arrange-a-binary-grid lang=cpp site=leetcode.com title="Minimum Swaps to Arrange a Binary Grid"
class Solution {
    public:
    int minSwaps(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> trail(n);
    for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) cnt++;
    trail[i] = cnt;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
    int need = n - 1 - i;
    int j = i;
    while (j < n && trail[j] < need) j++;
    if (j == n) return -1;
    while (j > i) {
    swap(trail[j], trail[j - 1]);
    j--;
    ans++;
    }
    }
    return ans;
    }
    };
