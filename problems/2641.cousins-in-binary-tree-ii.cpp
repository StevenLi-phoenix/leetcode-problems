// @leetcode id=2641 questionId=2677 slug=cousins-in-binary-tree-ii lang=cpp site=leetcode.com title="Cousins in Binary Tree II"
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;
        root->val = 0;
        vector<TreeNode*> level = {root};
        while (!level.empty()) {
            int levelSum = 0;
            for (TreeNode* node : level) {
                if (node->left) levelSum += node->left->val;
                if (node->right) levelSum += node->right->val;
            }

            vector<TreeNode*> nextLevel;
            for (TreeNode* node : level) {
                int siblingSum = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
                if (node->left) {
                    node->left->val = levelSum - siblingSum;
                    nextLevel.push_back(node->left);
                }
                if (node->right) {
                    node->right->val = levelSum - siblingSum;
                    nextLevel.push_back(node->right);
                }
            }
            level = nextLevel;
        }
        return root;
    }
};
