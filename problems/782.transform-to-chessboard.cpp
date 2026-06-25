// @leetcode id=782 questionId=798 slug=transform-to-chessboard lang=cpp site=leetcode.com title="Transform to Chessboard"
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        
        // Check validity:
        // 1. All rows must be one of two complementary patterns
        // 2. All columns must be one of two complementary patterns
        // XOR any two rows must be all 0s or all 1s
        // i.e., board[i][j] XOR board[0][j] must equal board[i][0] XOR board[0][0]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) != 0)
                    return -1;
            }
        }
        
        // Count row sum and col sum
        int rowSum = 0, colSum = 0, rowMismatch = 0, colMismatch = 0;
        for (int i = 0; i < n; i++) {
            rowSum += board[0][i];
            colSum += board[i][0];
            // Count mismatches: positions where board[i][0] != i%2
            if (board[i][0] != i % 2) rowMismatch++;  // row i in wrong parity
            if (board[0][i] != i % 2) colMismatch++;  // col i in wrong parity
        }
        
        // Check if it's possible: rowSum and colSum must be n/2 or (n+1)/2
        if (rowSum < n/2 || rowSum > (n+1)/2) return -1;
        if (colSum < n/2 || colSum > (n+1)/2) return -1;
        
        int res = 0;
        if (n % 2 == 1) {
            // For odd n, the mismatch count must be even
            if (rowMismatch % 2 == 1) rowMismatch = n - rowMismatch;
            if (colMismatch % 2 == 1) colMismatch = n - colMismatch;
        } else {
            // For even n, take minimum of fixing even/odd positions
            rowMismatch = min(rowMismatch, n - rowMismatch);
            colMismatch = min(colMismatch, n - colMismatch);
        }
        
        return (rowMismatch + colMismatch) / 2;
    }
};
