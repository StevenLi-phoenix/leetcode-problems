// @leetcode id=1008 questionId=1050 slug=construct-binary-search-tree-from-preorder-traversal lang=cpp site=leetcode.com title="Construct Binary Search Tree from Preorder Traversal"
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
    TreeNode* build(vector<int>& preorder, int& idx, int bound) {
        if (idx == (int)preorder.size() || preorder[idx] > bound) return nullptr;
        TreeNode* node = new TreeNode(preorder[idx++]);
        node->left = build(preorder, idx, node->val);
        node->right = build(preorder, idx, bound);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return build(preorder, idx, INT_MAX);
    }
};
