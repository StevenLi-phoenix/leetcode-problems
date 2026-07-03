// @leetcode id=1305 questionId=1427 slug=all-elements-in-two-binary-search-trees lang=cpp site=leetcode.com title="All Elements in Two Binary Search Trees"
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        inorder(root1, a);
        inorder(root2, b);

        vector<int> result;
        result.reserve(a.size() + b.size());
        int i = 0, j = 0;
        while (i < (int)a.size() && j < (int)b.size()) {
            if (a[i] <= b[j]) result.push_back(a[i++]);
            else result.push_back(b[j++]);
        }
        while (i < (int)a.size()) result.push_back(a[i++]);
        while (j < (int)b.size()) result.push_back(b[j++]);
        return result;
    }

private:
    void inorder(TreeNode* node, vector<int>& out) {
        if (!node) return;
        inorder(node->left, out);
        out.push_back(node->val);
        inorder(node->right, out);
    }
};
