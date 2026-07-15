// @leetcode id=687 questionId=687 slug=longest-univalue-path lang=cpp site=leetcode.com title="Longest Univalue Path"
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
    int best = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;
        int leftLen = dfs(node->left);
        int rightLen = dfs(node->right);
        int leftArm = (node->left && node->left->val == node->val) ? leftLen + 1 : 0;
        int rightArm = (node->right && node->right->val == node->val) ? rightLen + 1 : 0;
        best = max(best, leftArm + rightArm);
        return max(leftArm, rightArm);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return best;
    }
};
