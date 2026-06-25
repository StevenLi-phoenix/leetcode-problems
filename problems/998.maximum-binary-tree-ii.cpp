// @leetcode id=998 questionId=1040 slug=maximum-binary-tree-ii lang=cpp site=leetcode.com title="Maximum Binary Tree II"
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        // val is appended to the end of the original array
        // If val > root->val, val is the new maximum, so it becomes new root
        // with the old tree as its left child (all old elements come before val)
        if (!root || val > root->val) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        // val < root->val, so val is in the right part (after root in original array)
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};
