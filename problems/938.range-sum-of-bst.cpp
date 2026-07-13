// @leetcode id=938 questionId=975 slug=range-sum-of-bst lang=cpp site=leetcode.com title="Range Sum of BST"
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        long long sum = 0;
        stack<TreeNode*> st;
        if (root) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (!node) continue;
            if (node->val >= low && node->val <= high) sum += node->val;
            if (node->val > low) st.push(node->left);
            if (node->val < high) st.push(node->right);
        }
        return (int)sum;
    }
};
