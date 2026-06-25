// @leetcode id=968 questionId=1008 slug=binary-tree-cameras lang=cpp site=leetcode.com title="Binary Tree Cameras"
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
    int cameras;
    
    // Returns:
    // 0 - not covered
    // 1 - has camera
    // 2 - covered (by child camera)
    int dfs(TreeNode* node) {
        if (!node) return 2; // null nodes are considered covered
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        // If any child is not covered, must place camera here
        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        }
        
        // If any child has a camera, this node is covered
        if (left == 1 || right == 1) {
            return 2;
        }
        
        // Both children are covered (by their children), this node is not covered
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        cameras = 0;
        // If root is not covered, we need a camera there
        if (dfs(root) == 0) cameras++;
        return cameras;
    }
};
