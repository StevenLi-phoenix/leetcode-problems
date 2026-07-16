// @leetcode id=845 questionId=875 slug=longest-mountain-in-array lang=cpp site=leetcode.com title="Longest Mountain in Array"
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;
        vector<int> up(n, 0), down(n, 0);
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) up[i] = up[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) down[i] = down[i + 1] + 1;
        }
        int best = 0;
        for (int i = 0; i < n; i++) {
            if (up[i] > 0 && down[i] > 0) {
                best = max(best, up[i] + down[i] + 1);
            }
        }
        return best;
    }
};
