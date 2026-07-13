// @leetcode id=2476 questionId=2567 slug=closest-nodes-queries-in-a-binary-search-tree lang=cpp site=leetcode.com title="Closest Nodes Queries in a Binary Search Tree"
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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> sortedVals;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            sortedVals.push_back(cur->val);
            cur = cur->right;
        }

        vector<vector<int>> result;
        for (int q : queries) {
            auto it = lower_bound(sortedVals.begin(), sortedVals.end(), q);
            int maxVal = (it != sortedVals.end()) ? *it : -1;
            int minVal;
            if (it != sortedVals.end() && *it == q) {
                minVal = q;
            } else if (it == sortedVals.begin()) {
                minVal = -1;
            } else {
                minVal = *prev(it);
            }
            result.push_back({minVal, maxVal});
        }
        return result;
    }
};
