// @leetcode id=105 questionId=105 slug=construct-binary-tree-from-preorder-and-inorder-traversal lang=cpp site=leetcode.com title="Construct Binary Tree from Preorder and Inorder Traversal"
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < (int)inorder.size(); i++) inorderIndex[inorder[i]] = i;

        int preIdx = 0;
        function<TreeNode*(int, int)> build = [&](int inLo, int inHi) -> TreeNode* {
            if (inLo > inHi) return nullptr;
            int rootVal = preorder[preIdx++];
            TreeNode* root = new TreeNode(rootVal);
            int mid = inorderIndex[rootVal];
            root->left = build(inLo, mid - 1);
            root->right = build(mid + 1, inHi);
            return root;
        };
        return build(0, (int)inorder.size() - 1);
    }
};
