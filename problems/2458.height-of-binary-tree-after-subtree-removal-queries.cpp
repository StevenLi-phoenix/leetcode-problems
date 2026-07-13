// @leetcode id=2458 questionId=2545 slug=height-of-binary-tree-after-subtree-removal-queries lang=cpp site=leetcode.com title="Height of Binary Tree After Subtree Removal Queries"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // depth[v] + height[v] = the deepest leaf depth reachable via v.
        // Any root-to-leaf path passes through exactly one node per depth
        // level, so removing v's subtree only removes v's own contribution
        // at level depth[v]; every alternative path is captured by some
        // OTHER node at that same level (whether a sibling, or a node
        // through a different ancestor branch). So per level we only need
        // the top-2 (depth+height) values, keyed by value only (ties are
        // handled correctly since a tie keeps top2 == top1).
        unordered_map<int, int> depth, height;
        vector<TreeNode*> order;

        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});
        while (!bfs.empty()) {
            auto [node, d] = bfs.front(); bfs.pop();
            depth[node->val] = d;
            order.push_back(node);
            if (node->left) bfs.push({node->left, d + 1});
            if (node->right) bfs.push({node->right, d + 1});
        }

        for (int i = (int)order.size() - 1; i >= 0; i--) {
            TreeNode* node = order[i];
            int h = 0;
            if (node->left) h = max(h, 1 + height[node->left->val]);
            if (node->right) h = max(h, 1 + height[node->right->val]);
            height[node->val] = h;
        }

        unordered_map<int, pair<int,int>> topTwoAtDepth; // depth -> (top1, top2)
        for (TreeNode* node : order) {
            int d = depth[node->val];
            int val = d + height[node->val];
            auto& [top1, top2] = topTwoAtDepth[d];
            if (val >= top1) { top2 = top1; top1 = val; }
            else if (val > top2) { top2 = val; }
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
            int q = queries[i];
            int d = depth[q];
            int val = d + height[q];
            auto& [top1, top2] = topTwoAtDepth[d];
            int candidate = (val == top1) ? top2 : top1;
            ans[i] = max(candidate, d - 1);
        }
        return ans;
    }
};
