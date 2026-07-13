// @leetcode id=2265 questionId=2347 slug=count-nodes-equal-to-average-of-subtree lang=cpp site=leetcode.com title="Count Nodes Equal to Average of Subtree"
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
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        function<pair<int,int>(TreeNode*)> dfs = [&](TreeNode* node) -> pair<int,int> {
            if (!node) return {0, 0};
            auto [leftSum, leftCnt] = dfs(node->left);
            auto [rightSum, rightCnt] = dfs(node->right);
            int sum = leftSum + rightSum + node->val;
            int cnt = leftCnt + rightCnt + 1;
            if (sum / cnt == node->val) count++;
            return {sum, cnt};
        };
        dfs(root);
        return count;
    }
};
