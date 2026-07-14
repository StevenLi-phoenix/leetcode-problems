// @leetcode id=2331 questionId=2416 slug=evaluate-boolean-binary-tree lang=cpp site=leetcode.com title="Evaluate Boolean Binary Tree"
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
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right) return root->val == 1;
        bool l = evaluateTree(root->left);
        bool r = evaluateTree(root->right);
        return root->val == 2 ? (l || r) : (l && r);
    }
};
