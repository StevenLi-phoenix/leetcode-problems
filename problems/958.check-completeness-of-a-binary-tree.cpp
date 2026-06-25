// @leetcode id=958 questionId=998 slug=check-completeness-of-a-binary-tree lang=cpp site=leetcode.com title="Check Completeness of a Binary Tree"
/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        bool foundNull = false;
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (!node) {
                foundNull = true;
            } else {
                if (foundNull) {
                    // Found a non-null node after a null node
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return true;
    }
};
