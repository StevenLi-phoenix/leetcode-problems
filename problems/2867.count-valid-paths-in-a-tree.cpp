// @leetcode id=2867 questionId=3112 slug=count-valid-paths-in-a-tree lang=cpp site=leetcode.com title="Count Valid Paths in a Tree"
class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        // Sieve of Eratosthenes
        vector<bool> isComposite(n + 1, false);
        isComposite[0] = isComposite[1] = true;
        for (int i = 2; i * i <= n; i++) {
            if (!isComposite[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isComposite[j] = true;
                }
            }
        }
        auto isPrime = [&](int x) { return !isComposite[x]; };
        
        // Build adjacency list
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // Union-Find for non-prime nodes
        vector<int> parent(n + 1), sz(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        
        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        };
        
        // Unite non-prime neighbors
        for (int u = 1; u <= n; u++) {
            if (!isPrime(u)) {
                for (int v : adj[u]) {
                    if (!isPrime(v)) {
                        unite(u, v);
                    }
                }
            }
        }
        
        long long ans = 0;
        
        // For each prime node, count paths passing through it
        for (int p = 2; p <= n; p++) {
            if (!isPrime(p)) continue;
            
            // Count sizes of non-prime components adjacent to p
            // Each non-prime component adjacent to p can form paths through p
            long long total = 0; // total non-prime nodes accessible through p so far
            
            for (int v : adj[p]) {
                if (!isPrime(v)) {
                    int root = find(v);
                    long long compSize = sz[root];
                    // Paths from this component to p: compSize
                    ans += compSize;
                    // Paths between this component and previous components through p
                    ans += total * compSize;
                    total += compSize;
                }
            }
        }
        
        return ans;
    }
};
