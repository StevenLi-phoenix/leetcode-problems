// @leetcode id=1643 questionId=489 slug=kth-smallest-instructions lang=cpp site=leetcode.com title="Kth Smallest Instructions"
class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int row = destination[0], col = destination[1];
        // Precompute Pascal's triangle up to (row+col) choose anything.
        int total = row + col;
        vector<vector<long long>> C(total + 1, vector<long long>(total + 1, 0));
        for (int i = 0; i <= total; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }

        string ans;
        int h = col, v = row; // remaining H's and V's to place
        long long remaining = k;
        while (h > 0 || v > 0) {
            if (h > 0) {
                // Number of arrangements if we place 'H' now: choose
                // positions for the remaining v's among the remaining slots.
                long long countIfH = C[h - 1 + v][v];
                if (remaining <= countIfH) {
                    ans += 'H';
                    h--;
                    continue;
                }
                remaining -= countIfH;
            }
            ans += 'V';
            v--;
        }
        return ans;
    }
};
