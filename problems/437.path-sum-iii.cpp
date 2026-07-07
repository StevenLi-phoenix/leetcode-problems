// @leetcode id=437 questionId=437 slug=path-sum-iii lang=cpp site=leetcode.com title="Path Sum III"
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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixCount;
        prefixCount[0] = 1;
        return dfs(root, 0, targetSum, prefixCount);
    }

private:
    int dfs(TreeNode* node, long long curSum, int target,
            unordered_map<long long, int>& prefixCount) {
        if (!node) return 0;

        curSum += node->val;
        int count = 0;
        auto it = prefixCount.find(curSum - target);
        if (it != prefixCount.end()) count = it->second;

        ++prefixCount[curSum];
        count += dfs(node->left, curSum, target, prefixCount);
        count += dfs(node->right, curSum, target, prefixCount);
        --prefixCount[curSum];

        return count;
    }
};
