// @leetcode id=1654 questionId=1757 slug=minimum-jumps-to-reach-home lang=cpp site=leetcode.com title="Minimum Jumps to Reach Home"
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> forbidSet(forbidden.begin(), forbidden.end());
        
        // BFS: state = (position, canGoBack)
        // canGoBack = 1 if last jump was forward, 0 if backward
        int maxPos = max(x, *max_element(forbidden.begin(), forbidden.end())) + a + b;
        
        // visited[pos][canGoBack]
        vector<vector<bool>> visited(maxPos + 1, vector<bool>(2, false));
        
        queue<pair<int,int>> q; // (pos, canGoBack: 1=yes, 0=no)
        q.push({0, 1});
        visited[0][1] = true;
        int steps = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [pos, canBack] = q.front();
                q.pop();
                
                if (pos == x) return steps;
                
                // Jump forward
                int nf = pos + a;
                if (nf <= maxPos && !forbidSet.count(nf) && !visited[nf][1]) {
                    visited[nf][1] = true;
                    q.push({nf, 1});
                }
                
                // Jump backward (only if canBack)
                if (canBack) {
                    int nb = pos - b;
                    if (nb >= 0 && !forbidSet.count(nb) && !visited[nb][0]) {
                        visited[nb][0] = true;
                        q.push({nb, 0});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};
