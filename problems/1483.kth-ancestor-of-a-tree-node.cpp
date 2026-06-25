// @leetcode id=1483 questionId=1296 slug=kth-ancestor-of-a-tree-node lang=cpp site=leetcode.com title="Kth Ancestor of a Tree Node"
class TreeAncestor {
public:
    // Binary lifting: up[i][j] = 2^j-th ancestor of node i
    vector<vector<int>> up;
    int LOG = 16; // 2^16 = 65536 > 50000
    
    TreeAncestor(int n, vector<int>& parent) {
        up.assign(n, vector<int>(LOG, -1));
        // up[i][0] = direct parent
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }
        // Fill table: up[i][j] = up[up[i][j-1]][j-1]
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[i][j-1] != -1) {
                    up[i][j] = up[up[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            if ((k >> j) & 1) {
                node = up[node][j];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
