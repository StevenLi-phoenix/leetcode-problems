// @leetcode id=530 questionId=530 slug=minimum-absolute-difference-in-bst lang=cpp site=leetcode.com title="Minimum Absolute Difference in BST"
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
    int prev = -1;
    int best = INT_MAX;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (prev != -1) best = min(best, node->val - prev);
        prev = node->val;
        inorder(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return best;
    }
};
