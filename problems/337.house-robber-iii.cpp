// @leetcode id=337 questionId=337 slug=house-robber-iii lang=cpp site=leetcode.com title="House Robber III"
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
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto [lRob, lSkip] = dfs(node->left);
        auto [rRob, rSkip] = dfs(node->right);
        int robThis = node->val + lSkip + rSkip;
        int skipThis = max(lRob, lSkip) + max(rRob, rSkip);
        return {robThis, skipThis};
    }

    int rob(TreeNode* root) {
        auto [robRoot, skipRoot] = dfs(root);
        return max(robRoot, skipRoot);
    }
};
