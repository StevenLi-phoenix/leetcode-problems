// @leetcode id=3699 questionId=3962 slug=number-of-zigzag-arrays-i lang=cpp site=leetcode.com title="Number of ZigZag Arrays I"
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;
        
        // up[v]   = ways ending at value index v, next must go UP (current is local min)
        // down[v] = ways ending at value index v, next must go DOWN (current is local max)
        // Base: length=1, both dirs valid
        vector<long long> up(m, 1), down(m, 1);
        vector<long long> new_up(m), new_down(m);
        vector<long long> prefix(m + 1), suffix(m + 1);
        
        if (n == 1) return m % MOD;
        
        for (int step = 1; step < n; step++) {
            // new_down[y] = sum of up[x] for x < y  (went up: x -> y, y > x)
            // prefix sum of up
            prefix[0] = 0;
            for (int v = 0; v < m; v++)
                prefix[v + 1] = (prefix[v] + up[v]) % MOD;
            for (int y = 0; y < m; y++)
                new_down[y] = prefix[y]; // sum up[0..y-1]
            
            // new_up[y] = sum of down[x] for x > y  (went down: x -> y, y < x)
            // suffix sum of down
            suffix[m] = 0;
            for (int v = m - 1; v >= 0; v--)
                suffix[v] = (suffix[v + 1] + down[v]) % MOD;
            for (int y = 0; y < m; y++)
                new_up[y] = suffix[y + 1]; // sum down[y+1..m-1]
            
            swap(up, new_up);
            swap(down, new_down);
        }
        
        long long ans = 0;
        for (int v = 0; v < m; v++)
            ans = (ans + up[v] + down[v]) % MOD;
        
        return (int)ans;
    }
};
