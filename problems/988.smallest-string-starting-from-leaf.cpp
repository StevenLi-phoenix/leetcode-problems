// @leetcode id=988 questionId=1030 slug=smallest-string-starting-from-leaf lang=cpp site=leetcode.com title="Smallest String Starting From Leaf"
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
    string result = "";
    
    void dfs(TreeNode* node, string path) {
        if (!node) return;
        path = (char)('a' + node->val) + path;  // prepend current char
        
        if (!node->left && !node->right) {
            // leaf node
            if (result.empty() || path < result) {
                result = path;
            }
            return;
        }
        
        dfs(node->left, path);
        dfs(node->right, path);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return result;
    }
};
