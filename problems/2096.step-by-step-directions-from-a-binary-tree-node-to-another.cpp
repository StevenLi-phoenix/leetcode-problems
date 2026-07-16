// @leetcode id=2096 questionId=2217 slug=step-by-step-directions-from-a-binary-tree-node-to-another lang=cpp site=leetcode.com title="Step-By-Step Directions From a Binary Tree Node to Another"
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
    bool findPath(TreeNode* node, int val, string& path) {
        if (!node) return false;
        if (node->val == val) return true;
        path.push_back('L');
        if (findPath(node->left, val, path)) return true;
        path.pop_back();
        path.push_back('R');
        if (findPath(node->right, val, path)) return true;
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        int i = 0;
        while (i < (int)startPath.size() && i < (int)destPath.size() && startPath[i] == destPath[i]) {
            i++;
        }

        string result(startPath.size() - i, 'U');
        result += destPath.substr(i);
        return result;
    }
};
