// @leetcode id=110 questionId=110 slug=balanced-binary-tree lang=cpp site=leetcode.com title="Balanced Binary Tree"
class Solution {
    public:
    int height(TreeNode* node) {
    if (!node) return 0;
    int l = height(node->left);
    if (l == -1) return -1;
    int r = height(node->right);
    if (r == -1) return -1;
    if (abs(l - r) > 1) return -1;
    return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
    return height(root) != -1;
    }
    };
