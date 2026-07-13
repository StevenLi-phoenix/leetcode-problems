// @leetcode id=987 questionId=1029 slug=vertical-order-traversal-of-a-binary-tree lang=cpp site=leetcode.com title="Vertical Order Traversal of a Binary Tree"
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<array<int, 3>> nodes; // {col, row, val}
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});
        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();
            nodes.push_back({col, row, node->val});
            if (node->left) q.push({node->left, row + 1, col - 1});
            if (node->right) q.push({node->right, row + 1, col + 1});
        }

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> result;
        int i = 0, n = nodes.size();
        while (i < n) {
            int j = i;
            vector<int> col;
            while (j < n && nodes[j][0] == nodes[i][0]) {
                col.push_back(nodes[j][2]);
                j++;
            }
            result.push_back(col);
            i = j;
        }
        return result;
    }
};
