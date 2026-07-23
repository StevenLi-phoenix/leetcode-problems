// @leetcode id=671 questionId=671 slug=second-minimum-node-in-a-binary-tree lang=cpp site=leetcode.com title="Second Minimum Node In a Binary Tree"
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
    void dfs(TreeNode* node, int rootVal, long long& result) {
        if (!node) return;
        if (node->val > rootVal) {
            result = min(result, (long long)node->val);
            return;
        }
        dfs(node->left, rootVal, result);
        dfs(node->right, rootVal, result);
    }

    int findSecondMinimumValue(TreeNode* root) {
        long long result = LLONG_MAX;
        dfs(root, root->val, result);
        return result == LLONG_MAX ? -1 : (int)result;
    }
};
