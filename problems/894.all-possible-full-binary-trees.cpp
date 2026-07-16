// @leetcode id=894 questionId=930 slug=all-possible-full-binary-trees lang=cpp site=leetcode.com title="All Possible Full Binary Trees"
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
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> memo;
        return build(n, memo);
    }

private:
    vector<TreeNode*> build(int n, unordered_map<int, vector<TreeNode*>>& memo) {
        if (n % 2 == 0) return {};
        if (n == 1) return {new TreeNode(0)};

        auto it = memo.find(n);
        if (it != memo.end()) return it->second;

        vector<TreeNode*> result;
        for (int left = 1; left < n; left += 2) {
            int right = n - 1 - left;
            vector<TreeNode*> leftTrees = build(left, memo);
            vector<TreeNode*> rightTrees = build(right, memo);
            for (TreeNode* l : leftTrees) {
                for (TreeNode* r : rightTrees) {
                    result.push_back(new TreeNode(0, l, r));
                }
            }
        }
        memo[n] = result;
        return result;
    }
};
