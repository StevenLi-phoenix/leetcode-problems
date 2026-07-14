// @leetcode id=1123 questionId=1218 slug=lowest-common-ancestor-of-deepest-leaves lang=cpp site=leetcode.com title="Lowest Common Ancestor of Deepest Leaves"
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
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};
        auto [leftDepth, leftNode] = dfs(node->left);
        auto [rightDepth, rightNode] = dfs(node->right);
        if (leftDepth == rightDepth) return {leftDepth + 1, node};
        return leftDepth > rightDepth ? make_pair(leftDepth + 1, leftNode) : make_pair(rightDepth + 1, rightNode);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};
