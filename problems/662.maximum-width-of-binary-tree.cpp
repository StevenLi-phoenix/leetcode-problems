// @leetcode id=662 questionId=662 slug=maximum-width-of-binary-tree lang=cpp site=leetcode.com title="Maximum Width of Binary Tree"
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        long long best = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int sz = q.size();
            long long first = q.front().second, last = first;
            for (int i = 0; i < sz; i++) {
                auto [node, idx] = q.front();
                q.pop();
                idx -= first;
                last = idx;
                if (node->left) q.push({node->left, idx * 2});
                if (node->right) q.push({node->right, idx * 2 + 1});
            }
            best = max(best, last + 1);
        }
        return (int)best;
    }
};
