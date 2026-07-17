// @leetcode id=129 questionId=129 slug=sum-root-to-leaf-numbers lang=cpp site=leetcode.com title="Sum Root to Leaf Numbers"
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
    void dfs(TreeNode* node, int current, int& total) {
        if (!node) return;
        current = current * 10 + node->val;
        if (!node->left && !node->right) {
            total += current;
            return;
        }
        dfs(node->left, current, total);
        dfs(node->right, current, total);
    }

    int sumNumbers(TreeNode* root) {
        int total = 0;
        dfs(root, 0, total);
        return total;
    }
};
