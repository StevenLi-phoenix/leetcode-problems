// @leetcode id=3363 questionId=3648 slug=find-the-maximum-number-of-fruits-collected lang=cpp site=leetcode.com title="Find the Maximum Number of Fruits Collected"
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        
        // Child 1: from (0,0) to (n-1,n-1) only via diagonal
        // Only moves: down-right, so path is (0,0),(1,1),...,(n-1,n-1)
        int child1 = 0;
        for (int i = 0; i < n; i++) {
            child1 += fruits[i][i];
        }
        
        // Child 2: from (0,n-1) to (n-1,n-1)
        // At each step, row increases by 1, col can be j-1, j, j+1
        // dp2[i][j] = max fruits collected reaching (i,j) from (0,n-1)
        // Initial: dp2[0][n-1] = fruits[0][n-1]
        // We only need cells where i <= j (to the right of diagonal) to not overlap with child 1
        // Actually child 2 starts top-right and ends at bottom-right
        // Any cell on child 2's path must have j >= i (to stay to the right of or on diagonal)
        // And since child 1 takes the diagonal, we zero out diagonal cells for child 2
        // But wait - they can share (n-1,n-1) - that's counted once
        
        // Actually the key insight: child 2 path must satisfy col >= row (otherwise goes past diagonal)
        // because it starts at (0, n-1) and ends at (n-1, n-1), n >= 2
        // at step i (row=i), col can range from n-1-(i) to n-1 (can only go left or stay)
        // so col >= n-1-i, but since i <= n-1, col >= 0, but col >= i is the key constraint
        
        const int NEG_INF = INT_MIN / 2;
        vector<vector<int>> dp2(n, vector<int>(n, NEG_INF));
        dp2[0][n-1] = fruits[0][n-1];
        
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j++) { // j >= i constraint
                // came from (i-1, j-1), (i-1, j), (i-1, j+1)
                for (int dj : {-1, 0, 1}) {
                    int pj = j + dj;
                    if (pj >= 0 && pj < n && dp2[i-1][pj] != NEG_INF) {
                        int add = (i == j) ? 0 : fruits[i][j]; // diagonal taken by child 1
                        dp2[i][j] = max(dp2[i][j], dp2[i-1][pj] + add);
                    }
                }
            }
        }
        
        // Child 3: from (n-1,0) to (n-1,n-1)
        // At each step, col increases by 1, row can be i-1, i, i+1
        // Must satisfy row >= col (to the right side = below diagonal is... hmm)
        // child 3 starts at bottom-left, so row >= n-1-j initially... 
        // At col=j, row can be from... n-1 to j basically (row >= j constraint? No)
        // Child 3 starts at (n-1, 0). At step k (col=k), row was n-1 and can vary ± 1 per step
        // At col=k, row is in range [n-1-k, n-1+k] capped to [0, n-1]
        // For row >= col: this is below-or-on diagonal (i >= j)
        
        vector<vector<int>> dp3(n, vector<int>(n, NEG_INF));
        dp3[n-1][0] = fruits[n-1][0];
        
        for (int j = 1; j < n; j++) {
            for (int i = j; i < n; i++) { // i >= j constraint (below diagonal)
                // came from (i-1, j-1), (i, j-1), (i+1, j-1)
                for (int di : {-1, 0, 1}) {
                    int pi = i + di;
                    if (pi >= 0 && pi < n && dp3[pi][j-1] != NEG_INF) {
                        int add = (i == j) ? 0 : fruits[i][j]; // diagonal taken by child 1
                        dp3[i][j] = max(dp3[i][j], dp3[pi][j-1] + add);
                    }
                }
            }
        }
        
        int result = child1;
        if (dp2[n-1][n-1] != NEG_INF) result += dp2[n-1][n-1];
        if (dp3[n-1][n-1] != NEG_INF) result += dp3[n-1][n-1];
        
        // (n-1, n-1) is on the diagonal so it was added by child 1
        // dp2 and dp3 both avoid the diagonal cells but should still count (n-1,n-1)
        // Let me reconsider: diagonal is NOT counted in child 2 and 3's dp
        // but (n-1,n-1) IS on the diagonal, so we should add it back for child 2 and child 3
        // Actually they DO count it because each ends there
        // Wait, in dp2 when i==j, add=0, but (n-1,n-1) is also on the diagonal and i==j, so we added 0
        // But (n-1,n-1) is only counted once by child1
        // So dp2 and dp3 should not count (n-1,n-1) since child1 already did
        // The code above already does add=0 when i==j for both dp2 and dp3
        // So result = child1 (includes n-1,n-1) + dp2 (excludes n-1,n-1) + dp3 (excludes n-1,n-1)
        
        return result;
    }
};
