// @leetcode id=1373 questionId=1475 slug=maximum-sum-bst-in-binary-tree lang=cpp site=leetcode.com title="Maximum Sum BST in Binary Tree"
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
    int maxSumBST(TreeNode* root) {
        int ans = 0;

        function<tuple<bool, int, int, long long>(TreeNode*)> dfs = [&](TreeNode* node) -> tuple<bool, int, int, long long> {
            if (!node) return {true, INT_MAX, INT_MIN, 0};

            auto [left_valid, left_min, left_max, left_sum] = dfs(node->left);
            auto [right_valid, right_min, right_max, right_sum] = dfs(node->right);

            if (left_valid && right_valid && node->val > left_max && node->val < right_min) {
                long long sum = left_sum + right_sum + node->val;
                ans = max(ans, (int)sum);
                return {true, min(node->val, left_min), max(node->val, right_max), sum};
            }

            return {false, 0, 0, 0};
        };

        dfs(root);
        return ans;
    }
};
