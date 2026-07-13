// @leetcode id=1038 questionId=1114 slug=binary-search-tree-to-greater-sum-tree lang=cpp site=leetcode.com title="Binary Search Tree to Greater Sum Tree"
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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;
            dfs(node->right);
            sum += node->val;
            node->val = sum;
            dfs(node->left);
        };
        dfs(root);
        return root;
    }
};
