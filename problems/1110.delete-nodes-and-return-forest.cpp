// @leetcode id=1110 questionId=1207 slug=delete-nodes-and-return-forest lang=cpp site=leetcode.com title="Delete Nodes And Return Forest"
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> delSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        
        function<TreeNode*(TreeNode*, bool)> dfs = [&](TreeNode* node, bool isRoot) -> TreeNode* {
            if (!node) return nullptr;
            bool deleted = delSet.count(node->val);
            if (isRoot && !deleted) result.push_back(node);
            node->left = dfs(node->left, deleted);
            node->right = dfs(node->right, deleted);
            return deleted ? nullptr : node;
        };
        
        dfs(root, true);
        return result;
    }
};
