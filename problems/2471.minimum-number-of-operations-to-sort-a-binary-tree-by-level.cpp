// @leetcode id=2471 questionId=2558 slug=minimum-number-of-operations-to-sort-a-binary-tree-by-level lang=cpp site=leetcode.com title="Minimum Number of Operations to Sort a Binary Tree by Level"
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
    int minimumOperations(TreeNode* root) {
        int totalOps = 0;
        vector<TreeNode*> level = {root};
        while (!level.empty()) {
            vector<int> vals;
            for (TreeNode* node : level) vals.push_back(node->val);
            totalOps += minSwaps(vals);

            vector<TreeNode*> next;
            for (TreeNode* node : level) {
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            level = next;
        }
        return totalOps;
    }

private:
    int minSwaps(vector<int>& vals) {
        int n = vals.size();
        vector<int> sorted = vals;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) pos[vals[i]] = i;

        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || vals[i] == sorted[i]) continue;
            int cycleLen = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = pos[sorted[j]];
                cycleLen++;
            }
            swaps += cycleLen - 1;
        }
        return swaps;
    }
};
