// @leetcode id=98 questionId=98 slug=validate-binary-search-tree lang=cpp site=leetcode.com title="Validate Binary Search Tree"
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
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool validate(TreeNode* node, long long lo, long long hi) {
        if (!node) return true;
        if (node->val <= lo || node->val >= hi) return false;
        return validate(node->left, lo, node->val) && validate(node->right, node->val, hi);
    }
};
