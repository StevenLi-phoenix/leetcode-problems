// @leetcode id=979 questionId=1021 slug=distribute-coins-in-binary-tree lang=cpp site=leetcode.com title="Distribute Coins in Binary Tree"
class Solution {
public:
    int ans = 0;
    
    // Returns net flow through the edge connecting node to its parent
    // Positive = coins flowing up, negative = coins flowing down
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        ans += abs(left) + abs(right);
        // Net flow up from this node: (val - 1) + left + right
        // (val - 1): this node has val coins, needs 1, so val-1 flows up
        return node->val - 1 + left + right;
    }
    
    int distributeCoins(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
