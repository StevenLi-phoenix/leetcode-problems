// @leetcode id=2415 questionId=2493 slug=reverse-odd-levels-of-binary-tree lang=cpp site=leetcode.com title="Reverse Odd Levels of Binary Tree"
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;
        vector<TreeNode*> level = {root};
        int depth = 0;
        while (!level.empty()) {
            if (depth % 2 == 1) {
                int lo = 0, hi = (int)level.size() - 1;
                while (lo < hi) {
                    swap(level[lo]->val, level[hi]->val);
                    lo++;
                    hi--;
                }
            }
            vector<TreeNode*> next;
            for (TreeNode* node : level) {
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            level = next;
            depth++;
        }
        return root;
    }
};
