// @leetcode id=3700 questionId=3964 slug=number-of-zigzag-arrays-ii lang=cpp site=leetcode.com title="Number of ZigZag Arrays II"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;
typedef vector<vector<ll>> Matrix;

Matrix multiply(const Matrix& A, const Matrix& B) {
    int sz = A.size();
    Matrix C(sz, vector<ll>(sz, 0));
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix matpow(Matrix A, ll p) {
    int sz = A.size();
    Matrix result(sz, vector<ll>(sz, 0));
    for (int i = 0; i < sz; i++) result[i][i] = 1;
    
    while (p > 0) {
        if (p & 1) result = multiply(result, A);
        A = multiply(A, A);
        p >>= 1;
    }
    return result;
}

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        
        if (n == 1) return m;
        if (n == 2) return (ll)m * (m - 1) % MOD;
        
        // Build transition matrix
        // States: 0..m-1 for "next compare = down" (came up to value l+i)
        //         m..2m-1 for "next compare = up" (came down to value l+i)
        
        Matrix T(2 * m, vector<ll>(2 * m, 0));
        
        // From state i (came up to value l+i, next must go down)
        for (int i = 0; i < m; i++) {
            // Can go to any value < l+i, which are indices 0..i-1
            for (int j = 0; j < i; j++) {
                T[m + j][i] = 1;  // state i -> state m+j (go down to l+j)
            }
        }
        
        // From state m+i (came down to value l+i, next must go up)
        for (int i = 0; i < m; i++) {
            // Can go to any value > l+i, which are indices i+1..m-1
            for (int j = i + 1; j < m; j++) {
                T[j][m + i] = 1;  // state m+i -> state j (go up to l+j)
            }
        }
        
        // Initial state: after choosing first two elements
        // If first < second: came up (state should be in 0..m-1)
        // If first > second: came down (state should be in m..2m-1)
        
        vector<ll> initial(2 * m, 0);
        
        // For all pairs (first, second) where first != second
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i != j) {
                    if (i < j) {
                        // first = l+i, second = l+j with i < j (going up)
                        // State should be j (came up to value l+j)
                        initial[j]++;
                    } else {
                        // first = l+i, second = l+j with i > j (going down)
                        // State should be m+j (came down to value l+j)
                        initial[m + j]++;
                    }
                }
            }
        }
        
        // Apply transition matrix n-2 times
        Matrix T_pow = matpow(T, n - 2);
        
        ll result = 0;
        for (int i = 0; i < 2 * m; i++) {
            for (int j = 0; j < 2 * m; j++) {
                result = (result + initial[j] * T_pow[i][j]) % MOD;
            }
        }
        
        return result;
    }
};
