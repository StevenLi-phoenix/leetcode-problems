// @leetcode id=508 questionId=508 slug=most-frequent-subtree-sum lang=cpp site=leetcode.com title="Most Frequent Subtree Sum"
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        dfs(root, freq, maxFreq);

        vector<int> result;
        for (auto& [sum, cnt] : freq) {
            if (cnt == maxFreq) result.push_back(sum);
        }
        return result;
    }

private:
    int dfs(TreeNode* node, unordered_map<int, int>& freq, int& maxFreq) {
        if (!node) return 0;
        int sum = node->val + dfs(node->left, freq, maxFreq) + dfs(node->right, freq, maxFreq);
        int cnt = ++freq[sum];
        maxFreq = max(maxFreq, cnt);
        return sum;
    }
};
