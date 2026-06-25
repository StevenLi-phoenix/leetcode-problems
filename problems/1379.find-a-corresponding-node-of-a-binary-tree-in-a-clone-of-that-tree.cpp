// @leetcode id=1379 questionId=1498 slug=find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree lang=cpp site=leetcode.com title="Find a Corresponding Node of a Binary Tree in a Clone of That Tree"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original) return nullptr;
        if (original == target) return cloned;

        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if (left) return left;

        return getTargetCopy(original->right, cloned->right, target);
    }
};
