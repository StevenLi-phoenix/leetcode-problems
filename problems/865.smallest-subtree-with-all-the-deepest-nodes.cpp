// @leetcode id=865 questionId=896 slug=smallest-subtree-with-all-the-deepest-nodes lang=cpp site=leetcode.com title="Smallest Subtree with all the Deepest Nodes"
class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};

        auto L = dfs(node->left);
        auto R = dfs(node->right);

        if (L.first == R.first) {
            return {L.first + 1, node};
        } else if (L.first > R.first) {
            return {L.first + 1, L.second};
        } else {
            return {R.first + 1, R.second};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
