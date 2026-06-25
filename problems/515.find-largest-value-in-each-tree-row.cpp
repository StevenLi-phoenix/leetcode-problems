// @leetcode id=515 questionId=515 slug=find-largest-value-in-each-tree-row lang=cpp site=leetcode.com title="Find Largest Value in Each Tree Row"
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int maxVal = INT_MIN;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                maxVal = max(maxVal, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(maxVal);
        }
        return result;
    }
};
