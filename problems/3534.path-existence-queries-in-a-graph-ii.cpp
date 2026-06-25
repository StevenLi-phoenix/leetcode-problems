// @leetcode id=3534 questionId=3852 slug=path-existence-queries-in-a-graph-ii lang=cpp site=leetcode.com title="Path Existence Queries in a Graph II"
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Sort indices by nums value
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return nums[a] < nums[b]; });
        
        // pos[original_node] = sorted position
        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[idx[i]] = i;
        
        // sv[i] = sorted values
        vector<int> sv(n);
        for (int i = 0; i < n; i++) sv[i] = nums[idx[i]];
        
        // nxt[i] = furthest sorted position reachable from i in one step (going right)
        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            // Binary search: largest j such that sv[j] <= sv[i] + maxDiff
            int lo = i, hi = n - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (sv[mid] - sv[i] <= maxDiff) lo = mid;
                else hi = mid - 1;
            }
            nxt[i] = lo;
        }
        
        // Binary lifting: anc[k][i] = position after 2^k steps from i
        const int LOG = 17;
        vector<vector<int>> anc(LOG, vector<int>(n));
        anc[0] = nxt;
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                anc[k][i] = anc[k-1][anc[k-1][i]];
            }
        }
        
        // Find minimum steps from sorted pos a to b (a <= b)
        auto minSteps = [&](int a, int b) -> int {
            if (a == b) return 0;
            if (a == nxt[a]) return -1; // stuck, can't advance
            
            // Check reachability: advance as much as possible and check if we reach >= b
            int cur = a, steps = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (anc[k][cur] < b) {
                    cur = anc[k][cur];
                    steps += (1 << k);
                }
            }
            // After this loop, cur is the furthest we can get without reaching b
            // One more step
            if (nxt[cur] >= b) {
                steps++;
                return steps;
            }
            return -1; // can't reach b
        };
        
        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) { ans.push_back(0); continue; }
            int a = pos[u], b = pos[v];
            if (a > b) swap(a, b);
            ans.push_back(minSteps(a, b));
        }
        return ans;
    }
};
