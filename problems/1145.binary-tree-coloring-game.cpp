// @leetcode id=1145 questionId=1248 slug=binary-tree-coloring-game lang=cpp site=leetcode.com title="Binary Tree Coloring Game"
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int leftSize = 0, rightSize = 0;
        findAndCount(root, x, leftSize, rightSize);
        int parentSize = n - leftSize - rightSize - 1;
        int half = n / 2;
        return leftSize > half || rightSize > half || parentSize > half;
    }

private:
    int count(TreeNode* node) {
        if (!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }

    bool findAndCount(TreeNode* node, int x, int& leftSize, int& rightSize) {
        if (!node) return false;
        if (node->val == x) {
            leftSize = count(node->left);
            rightSize = count(node->right);
            return true;
        }
        return findAndCount(node->left, x, leftSize, rightSize) ||
               findAndCount(node->right, x, leftSize, rightSize);
    }
};
