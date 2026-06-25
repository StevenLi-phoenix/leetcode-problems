// @leetcode id=993 questionId=1035 slug=cousins-in-binary-tree lang=cpp site=leetcode.com title="Cousins in Binary Tree"
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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, pair<int, TreeNode*>> info; // value -> (depth, parent)

        function<void(TreeNode*, int, TreeNode*)> dfs = [&](TreeNode* node, int depth, TreeNode* parent) {
            if (!node) return;
            info[node->val] = {depth, parent};
            dfs(node->left, depth + 1, node);
            dfs(node->right, depth + 1, node);
        };

        dfs(root, 0, nullptr);

        auto [depth_x, parent_x] = info[x];
        auto [depth_y, parent_y] = info[y];

        return depth_x == depth_y && parent_x != parent_y;
    }
};
