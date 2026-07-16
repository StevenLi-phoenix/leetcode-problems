// @leetcode id=889 questionId=925 slug=construct-binary-tree-from-preorder-and-postorder-traversal lang=cpp site=leetcode.com title="Construct Binary Tree from Preorder and Postorder Traversal"
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
    TreeNode* build(vector<int>& pre, int preStart, int preEnd,
                    vector<int>& post, int postStart, int postEnd,
                    unordered_map<int, int>& postIndex) {
        if (preStart > preEnd) return nullptr;
        TreeNode* root = new TreeNode(pre[preStart]);
        if (preStart == preEnd) return root;

        int leftRootVal = pre[preStart + 1];
        int leftRootPostIdx = postIndex[leftRootVal];
        int leftSize = leftRootPostIdx - postStart + 1;

        root->left = build(pre, preStart + 1, preStart + leftSize,
                            post, postStart, leftRootPostIdx, postIndex);
        root->right = build(pre, preStart + leftSize + 1, preEnd,
                             post, leftRootPostIdx + 1, postEnd - 1, postIndex);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postIndex;
        for (int i = 0; i < (int)postorder.size(); i++) postIndex[postorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, postIndex);
    }
};
