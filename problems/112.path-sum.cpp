// @leetcode id=112 questionId=112 slug=path-sum lang=cpp site=leetcode.com title="Path Sum"
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right) {
            return root->val == targetSum;
        }
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
