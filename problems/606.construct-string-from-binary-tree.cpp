// @leetcode id=606 questionId=606 slug=construct-string-from-binary-tree lang=cpp site=leetcode.com title="Construct String from Binary Tree"
class Solution {
public:
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string result = to_string(root->val);
        if (!root->left && !root->right) return result;
        result += "(" + tree2str(root->left) + ")";
        if (root->right) {
            result += "(" + tree2str(root->right) + ")";
        }
        return result;
    }
};
