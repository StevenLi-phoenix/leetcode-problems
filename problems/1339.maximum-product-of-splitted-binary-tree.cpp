// @leetcode id=1339 questionId=1465 slug=maximum-product-of-splitted-binary-tree lang=cpp site=leetcode.com title="Maximum Product of Splitted Binary Tree"
class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    long long treeSum(TreeNode* node) {
        if (!node) return 0LL;
        return (long long)node->val + treeSum(node->left) + treeSum(node->right);
    }

    long long dfs(TreeNode* node, long long total, long long& best) {
        if (!node) return 0LL;
        long long left = dfs(node->left, total, best);
        long long right = dfs(node->right, total, best);
        long long s = (long long)node->val + left + right;

        best = max(best, s * (total - s));
        return s;
    }

    int maxProduct(TreeNode* root) {
        long long total = treeSum(root);
        long long best = 0;
        dfs(root, total, best);
        return (int)(best % MOD);
    }
};
