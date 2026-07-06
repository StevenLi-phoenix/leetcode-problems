// @leetcode id=1080 questionId=1157 slug=insufficient-nodes-in-root-to-leaf-paths lang=cpp site=leetcode.com title="Insufficient Nodes in Root to Leaf Paths"
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return prune(root, 0, limit);
    }

private:
    TreeNode* prune(TreeNode* node, long long sumSoFar, int limit) {
        if (!node) return nullptr;
        sumSoFar += node->val;

        if (!node->left && !node->right) {
            return sumSoFar < limit ? nullptr : node;
        }

        node->left = prune(node->left, sumSoFar, limit);
        node->right = prune(node->right, sumSoFar, limit);

        if (!node->left && !node->right) return nullptr;
        return node;
    }
};
