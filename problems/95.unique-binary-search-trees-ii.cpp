// @leetcode id=95 questionId=95 slug=unique-binary-search-trees-ii lang=cpp site=leetcode.com title="Unique Binary Search Trees II"
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
    vector<TreeNode*> build(int lo, int hi) {
        vector<TreeNode*> result;
        if (lo > hi) {
            result.push_back(nullptr);
            return result;
        }
        for (int root = lo; root <= hi; root++) {
            vector<TreeNode*> lefts = build(lo, root - 1);
            vector<TreeNode*> rights = build(root + 1, hi);
            for (TreeNode* l : lefts) {
                for (TreeNode* r : rights) {
                    TreeNode* node = new TreeNode(root);
                    node->left = l;
                    node->right = r;
                    result.push_back(node);
                }
            }
        }
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};
