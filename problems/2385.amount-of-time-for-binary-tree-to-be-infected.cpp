// @leetcode id=2385 questionId=2461 slug=amount-of-time-for-binary-tree-to-be-infected lang=cpp site=leetcode.com title="Amount of Time for Binary Tree to Be Infected"
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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;

        function<void(TreeNode*, TreeNode*)> build = [&](TreeNode* node, TreeNode* parent) {
            if (!node) return;
            if (parent) {
                adj[node->val].push_back(parent->val);
                adj[parent->val].push_back(node->val);
            }
            build(node->left, node);
            build(node->right, node);
        };
        build(root, nullptr);

        unordered_set<int> visited = {start};
        queue<int> q;
        q.push(start);
        int minutes = -1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.front(); q.pop();
                for (int nb : adj[cur]) {
                    if (visited.count(nb)) continue;
                    visited.insert(nb);
                    q.push(nb);
                }
            }
            minutes++;
        }
        return minutes;
    }
};
