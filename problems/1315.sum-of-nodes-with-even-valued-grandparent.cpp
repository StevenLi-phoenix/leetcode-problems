// @leetcode id=1315 questionId=1243 slug=sum-of-nodes-with-even-valued-grandparent lang=cpp site=leetcode.com title="Sum of Nodes with Even-Valued Grandparent"
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
    void dfs(TreeNode* node, int parentVal, int grandparentVal, int& sum) {
        if (!node) return;
        if (grandparentVal % 2 == 0) sum += node->val;
        dfs(node->left, node->val, parentVal, sum);
        dfs(node->right, node->val, parentVal, sum);
    }

    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        dfs(root, 1, 1, sum);
        return sum;
    }
};
