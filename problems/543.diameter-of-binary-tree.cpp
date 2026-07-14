// @leetcode id=543 questionId=543 slug=diameter-of-binary-tree lang=cpp site=leetcode.com title="Diameter of Binary Tree"
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
    int diameterOfBinaryTree(TreeNode* root) {
        int best = 0;
        function<int(TreeNode*)> depth = [&](TreeNode* node) -> int {
            if (!node) return 0;
            int l = depth(node->left);
            int r = depth(node->right);
            best = max(best, l + r);
            return max(l, r) + 1;
        };
        depth(root);
        return best;
    }
};
