// @leetcode id=3997 questionId=4358 slug=count-dominant-nodes-in-a-binary-tree lang=cpp site=leetcode.com title="Count Dominant Nodes in a Binary Tree"
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
    int count = 0;

    int dfs(TreeNode* node) {
        int best = node->val;
        if (node->left) best = max(best, dfs(node->left));
        if (node->right) best = max(best, dfs(node->right));
        if (best == node->val) count++;
        return best;
    }

    int countDominantNodes(TreeNode* root) {
        count = 0;
        dfs(root);
        return count;
    }
};
