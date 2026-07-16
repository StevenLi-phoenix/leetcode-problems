// @leetcode id=1026 questionId=1092 slug=maximum-difference-between-node-and-ancestor lang=cpp site=leetcode.com title="Maximum Difference Between Node and Ancestor"
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
    int best = 0;

    void dfs(TreeNode* node, int mn, int mx) {
        if (!node) return;
        best = max(best, max(abs(node->val - mn), abs(node->val - mx)));
        mn = min(mn, node->val);
        mx = max(mx, node->val);
        dfs(node->left, mn, mx);
        dfs(node->right, mn, mx);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return best;
    }
};
