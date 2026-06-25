// @leetcode id=2538 questionId=2627 slug=difference-between-maximum-and-minimum-price-sum lang=cpp site=leetcode.com title="Difference Between Maximum and Minimum Price Sum"
class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // down[v] = max path sum going downward from v (including price[v])
        vector<long long> down(n, 0);
        // DFS1: compute down[]
        function<void(int,int)> dfs1 = [&](int u, int par) {
            down[u] = price[u];
            for (int v : adj[u]) {
                if (v == par) continue;
                dfs1(v, u);
                down[u] = max(down[u], price[u] + down[v]);
            }
        };
        dfs1(0, -1);
        
        // up[v] = max path sum going upward from v (not through v itself, just the path via parent)
        // When we reroot, for node v with parent par:
        //   up[v] = max(up[par] + price[v], max over siblings w != v of (down[w] + price[v]) + price[par])
        // Wait, let me redefine:
        // up[v] = the best path starting from v going upward (including price[v])
        // up[v] = price[v] + max(up[par], best_sibling_down)
        // where best_sibling_down = max(down[w]) for w in children(par), w != v
        
        vector<long long> up(n, 0);
        // For each node, track top-2 down values among children
        // DFS2: compute up[]
        function<void(int,int)> dfs2 = [&](int u, int par) {
            // Gather children's down values
            // For each child v, up[v] = price[v] + (best among up[u] and best_down_sibling)
            
            // Collect children down values
            vector<pair<long long, int>> childDowns;
            for (int v : adj[u]) {
                if (v == par) continue;
                childDowns.push_back({down[v], v});
            }
            
            // Sort to get top-2
            long long best1 = -1, best2 = -1;
            int best1_node = -1;
            for (auto& [d, v] : childDowns) {
                if (d > best1) { best2 = best1; best1 = d; best1_node = v; }
                else if (d > best2) { best2 = d; }
            }
            
            for (int v : adj[u]) {
                if (v == par) continue;
                // Best sibling = best down among other children
                long long bestSib = (v == best1_node) ? best2 : best1;
                // up[v] = price[v] + max(up[u] (going further up), bestSib (going to sibling subtree))
                long long fromUp = up[u]; // already includes price[u] contribution
                long long fromSib = (bestSib >= 0) ? (price[u] + bestSib) : -1;
                up[v] = price[v] + max({fromUp, fromSib, (long long)0});
                // Wait, up[u] includes price[u], so fromUp is already the best path going up through u
                dfs2(v, u);
            }
        };
        up[0] = 0; // root has no upward path, but we'll handle this
        // Actually, let me redefine: up[v] = max path sum starting at v going UP (including price[v])
        // For root: up[root] = price[root]... no.
        // Let me use a cleaner definition:
        // best[v] = max path sum starting at v (either going down or up)
        // Answer = max over all v of best[v] - price[v]
        
        // Actually, let me restart with cleaner re-rooting:
        // dp[v] = max price sum of a path starting at v in its subtree (rooted at 0)
        // For re-rooting: when we consider v as root, the max path = max(dp[v], "best path going through parent")
        
        // Cleaner approach: rerooting DP
        // Let f[v] = max path sum rooted AT v going downward (including v)
        // Initially computed with DFS from root 0
        // Then reroot: g[v] = max path sum from v going upward (through parent)
        // g[root] = price[root]
        // For child c of u: g[c] = price[c] + max(g[u], best other child's f + price[u])
        // Wait this double counts price[u]...
        
        // Let me use proper re-rooting:
        // down[v] = max path starting at v going into its subtree (including v's price)
        // For re-rooting: define top[v] = best "contribution from outside v's subtree"
        // top[root] = 0 (no outside)
        // For child c of v: top[c] = price[c] + max(top[v], max_{sibling s of c} down[s]) + price[v]? No...
        
        // Let me just do it directly and carefully:
        // ans[v] = max path sum starting at v in the fully rerooted tree - price[v]
        // = (max down path from v + max up path from v) - price[v]
        // But paths can only go in one direction from v (not both up and down at once, because we need a PATH)
        // Actually paths starting at v can go either down or up, but once a direction is chosen, they continue in that direction
        // So ans[v] = max(down[v], up_path[v]) - price[v]
        // where up_path[v] = best path starting at v going upward
        
        // down[v] includes price[v]
        // up_path[v] includes price[v]
        // up_path[root] = price[root] (can't go up)
        // up_path[c] for child c of v: price[c] + max(up_path[v] - price[v], best_sibling_down) + price[v]
        //   wait, up_path[v] already includes price[v], so going from c upward through v:
        //   path sum = price[c] + price[v] + (best extension from v going up or to sibling)
        //   = price[c] + max(up_path[v], price[v] + best_sibling_down)
        
        // Let me redefine: extra[v] = best path sum starting at parent(v) NOT going through v's subtree
        // (not including price[v])
        // extra[root] = 0
        // For child c of v: extra[c] = max(extra[v], max_{sibling s} down[s]) + price[v]
        //   where down[s] includes price[s]
        // Then: up_path[c] = price[c] + extra[c]  (extra[c] already includes price[v])
        // And: ans[v] = max(down[v], price[v] + extra[v]) - price[v]
        //             = max(down[v] - price[v], extra[v])
        
        // This is clean! Let me implement:
        vector<long long> extra(n, 0);
        
        function<void(int,int,long long)> dfs3 = [&](int u, int par, long long ex) {
            extra[u] = ex;
            // Collect down values of children
            vector<pair<long long,int>> ch;
            for (int v : adj[u]) {
                if (v == par) continue;
                ch.push_back({down[v], v});
            }
            // top-2 down values
            long long top1 = 0, top2 = 0;
            int top1node = -1;
            for (auto& [d, v] : ch) {
                if (d > top1) { top2 = top1; top1 = d; top1node = v; }
                else if (d > top2) top2 = d;
            }
            for (int v : adj[u]) {
                if (v == par) continue;
                long long bestSib = (v == top1node) ? top2 : top1;
                // extra for child v = max(extra[u], bestSib) + price[u]
                long long newEx = max(ex, bestSib) + price[u];
                dfs3(v, u, newEx);
            }
        };
        
        dfs3(0, -1, 0);
        
        long long ans = 0;
        for (int v = 0; v < n; v++) {
            // ans = max(down[v] - price[v], extra[v])
            ans = max(ans, max(down[v] - price[v], extra[v]));
        }
        return ans;
    }
};
