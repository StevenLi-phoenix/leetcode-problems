// @leetcode id=257 questionId=257 slug=binary-tree-paths lang=cpp site=leetcode.com title="Binary Tree Paths"
class Solution {
public:
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;
        path += to_string(node->val);
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }
        path += "->";
        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};
