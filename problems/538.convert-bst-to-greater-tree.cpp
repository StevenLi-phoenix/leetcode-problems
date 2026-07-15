// @leetcode id=538 questionId=538 slug=convert-bst-to-greater-tree lang=cpp site=leetcode.com title="Convert BST to Greater Tree"
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
    int sum = 0;

    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->right);
        sum += node->val;
        node->val = sum;
        dfs(node->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};
