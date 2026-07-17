// @leetcode id=1028 questionId=1093 slug=recover-a-tree-from-preorder-traversal lang=cpp site=leetcode.com title="Recover a Tree From Preorder Traversal"
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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> stack;
        int i = 0, n = traversal.size();

        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') { depth++; i++; }

            int val = 0;
            while (i < n && isdigit(traversal[i])) { val = val * 10 + (traversal[i] - '0'); i++; }

            TreeNode* node = new TreeNode(val);
            while ((int)stack.size() > depth) stack.pop_back();

            if (!stack.empty()) {
                if (!stack.back()->left) stack.back()->left = node;
                else stack.back()->right = node;
            }

            stack.push_back(node);
        }

        return stack.empty() ? nullptr : stack[0];
    }
};
