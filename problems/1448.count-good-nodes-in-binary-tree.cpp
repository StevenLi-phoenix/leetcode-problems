// @leetcode id=1448 questionId=1544 slug=count-good-nodes-in-binary-tree lang=cpp site=leetcode.com title="Count Good Nodes in Binary Tree"
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
    void dfs(TreeNode* node, int maxSoFar, int& count) {
        if (!node) return;
        if (node->val >= maxSoFar) {
            count++;
            maxSoFar = node->val;
        }
        dfs(node->left, maxSoFar, count);
        dfs(node->right, maxSoFar, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, INT_MIN, count);
        return count;
    }
};
