// @leetcode id=655 questionId=655 slug=print-binary-tree lang=cpp site=leetcode.com title="Print Binary Tree"
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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int rows = height + 1;
        int cols = (1 << (height + 1)) - 1;
        vector<vector<string>> res(rows, vector<string>(cols, ""));
        fill(root, res, 0, 0, cols - 1);
        return res;
    }

private:
    int getHeight(TreeNode* node) {
        if (!node) return -1;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    void fill(TreeNode* node, vector<vector<string>>& res, int row, int left, int right) {
        if (!node) return;
        int mid = left + (right - left) / 2;
        res[row][mid] = to_string(node->val);
        fill(node->left, res, row + 1, left, mid - 1);
        fill(node->right, res, row + 1, mid + 1, right);
    }
};
