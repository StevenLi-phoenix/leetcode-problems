// @leetcode id=971 questionId=1011 slug=flip-binary-tree-to-match-preorder-traversal lang=cpp site=leetcode.com title="Flip Binary Tree To Match Preorder Traversal"
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int idx = 0;
        vector<int> flipped;
        bool ok = dfs(root, voyage, idx, flipped);
        if (!ok) return {-1};
        return flipped;
    }

private:
    bool dfs(TreeNode* node, vector<int>& voyage, int& idx, vector<int>& flipped) {
        if (!node) return true;
        if (node->val != voyage[idx]) return false;
        idx++;
        if (node->left && idx < (int)voyage.size() && node->left->val != voyage[idx]) {
            flipped.push_back(node->val);
            return dfs(node->right, voyage, idx, flipped) && dfs(node->left, voyage, idx, flipped);
        }
        return dfs(node->left, voyage, idx, flipped) && dfs(node->right, voyage, idx, flipped);
    }
};
