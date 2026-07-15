// @leetcode id=3319 questionId=3509 slug=k-th-largest-perfect-subtree-size-in-binary-tree lang=cpp site=leetcode.com title="K-th Largest Perfect Subtree Size in Binary Tree"
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
    vector<int> sizes;

    // returns height if perfect, -1 otherwise
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int lh = dfs(node->left);
        int rh = dfs(node->right);
        if (lh == -1 || rh == -1 || lh != rh) return -1;
        int height = lh + 1;
        sizes.push_back((1 << height) - 1);
        return height;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        if ((int)sizes.size() < k) return -1;
        sort(sizes.begin(), sizes.end(), greater<int>());
        return sizes[k - 1];
    }
};
