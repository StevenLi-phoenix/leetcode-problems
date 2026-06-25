// @leetcode id=1372 questionId=1474 slug=longest-zigzag-path-in-a-binary-tree lang=cpp site=leetcode.com title="Longest ZigZag Path in a Binary Tree"
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
    int ans = 0;
    
    // returns {leftZigZag, rightZigZag}
    // leftZigZag: longest zigzag ending at this node going left direction
    // rightZigZag: longest zigzag ending at this node going right direction
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {-1, -1};
        auto [ll, lr] = dfs(node->left);
        auto [rl, rr] = dfs(node->right);
        // If we go left from parent, we use lr+1 (previous was right, now left)
        // If we go right from parent, we use rl+1 (previous was left, now right)
        int goLeft = lr + 1;   // came from right, going left
        int goRight = rl + 1;  // came from left, going right
        ans = max(ans, max(goLeft, goRight));
        return {goLeft, goRight};
    }
    
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
