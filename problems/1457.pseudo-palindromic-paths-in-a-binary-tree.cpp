// @leetcode id=1457 questionId=1568 slug=pseudo-palindromic-paths-in-a-binary-tree lang=cpp site=leetcode.com title="Pseudo-Palindromic Paths in a Binary Tree"
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

    void dfs(TreeNode* node, int mask) {
        if (!node) return;
        mask ^= (1 << node->val);
        if (!node->left && !node->right) {
            if ((mask & (mask - 1)) == 0) count++;
            return;
        }
        dfs(node->left, mask);
        dfs(node->right, mask);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root, 0);
        return count;
    }
};
