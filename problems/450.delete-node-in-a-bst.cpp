// @leetcode id=450 questionId=450 slug=delete-node-in-a-bst lang=cpp site=leetcode.com title="Delete Node in a BST"
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Iterative to avoid recursion-depth issues on a skewed tree with
        // up to 1e4 nodes.
        TreeNode* parent = nullptr;
        TreeNode* node = root;
        while (node && node->val != key) {
            parent = node;
            node = (key < node->val) ? node->left : node->right;
        }
        if (!node) return root;

        auto attach = [&](TreeNode* p, TreeNode* oldChild, TreeNode* newChild) {
            if (!p) return newChild; // deleting the root
            if (p->left == oldChild) p->left = newChild;
            else p->right = newChild;
            return root;
        };

        if (node->left && node->right) {
            TreeNode* succParent = node;
            TreeNode* succ = node->right;
            while (succ->left) {
                succParent = succ;
                succ = succ->left;
            }
            node->val = succ->val;
            root = attach(succParent, succ, succ->right);
        } else {
            TreeNode* child = node->left ? node->left : node->right;
            root = attach(parent, node, child);
        }
        return root;
    }
};
