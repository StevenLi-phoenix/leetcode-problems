// @leetcode id=1530 questionId=1653 slug=number-of-good-leaf-nodes-pairs lang=cpp site=leetcode.com title="Number of Good Leaf Nodes Pairs"
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
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }

private:
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node) return {};
        if (!node->left && !node->right) return {1};

        vector<int> left = dfs(node->left, distance, count);
        vector<int> right = dfs(node->right, distance, count);

        for (int a : left) {
            for (int b : right) {
                if (a + b <= distance) count++;
            }
        }

        vector<int> result;
        for (int a : left) if (a + 1 <= distance) result.push_back(a + 1);
        for (int b : right) if (b + 1 <= distance) result.push_back(b + 1);
        return result;
    }
};
