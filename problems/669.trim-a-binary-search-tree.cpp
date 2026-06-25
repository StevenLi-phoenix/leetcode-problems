// @leetcode id=669 questionId=669 slug=trim-a-binary-search-tree lang=cpp site=leetcode.com title="Trim a Binary Search Tree"
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;
        
        if (root->val < low) {
            // Entire left subtree is out of range; trim right subtree
            return trimBST(root->right, low, high);
        }
        if (root->val > high) {
            // Entire right subtree is out of range; trim left subtree
            return trimBST(root->left, low, high);
        }
        
        // root->val is in [low, high]
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
