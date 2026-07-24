// @leetcode id=563 questionId=563 slug=binary-tree-tilt lang=cpp site=leetcode.com title="Binary Tree Tilt"
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
    int findTilt(TreeNode* root) {
        int totalTilt = 0;
        dfs(root, totalTilt);
        return totalTilt;
    }

private:
    int dfs(TreeNode* node, int& totalTilt) {
        if (!node) return 0;
        int leftSum = dfs(node->left, totalTilt);
        int rightSum = dfs(node->right, totalTilt);
        totalTilt += abs(leftSum - rightSum);
        return leftSum + rightSum + node->val;
    }
};
