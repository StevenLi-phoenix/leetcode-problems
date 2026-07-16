// @leetcode id=106 questionId=106 slug=construct-binary-tree-from-inorder-and-postorder-traversal lang=cpp site=leetcode.com title="Construct Binary Tree from Inorder and Postorder Traversal"
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
    unordered_map<int, int> inorderIndex;
    int postIdx;

    TreeNode* build(vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inorderIndex[rootVal];

        root->right = build(postorder, mid + 1, inEnd);
        root->left = build(postorder, inStart, mid - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < (int)inorder.size(); i++) inorderIndex[inorder[i]] = i;
        postIdx = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1);
    }
};
