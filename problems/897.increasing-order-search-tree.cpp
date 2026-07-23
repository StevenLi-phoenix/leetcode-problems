// @leetcode id=897 questionId=933 slug=increasing-order-search-tree lang=cpp site=leetcode.com title="Increasing Order Search Tree"
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
    void inorder(TreeNode* node, vector<int>& values) {
        if (!node) return;
        inorder(node->left, values);
        values.push_back(node->val);
        inorder(node->right, values);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> values;
        inorder(root, values);

        TreeNode dummy(0);
        TreeNode* cur = &dummy;
        for (int v : values) {
            cur->right = new TreeNode(v);
            cur = cur->right;
        }
        return dummy.right;
    }
};
