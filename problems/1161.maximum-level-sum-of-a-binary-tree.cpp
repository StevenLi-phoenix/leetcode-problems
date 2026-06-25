// @leetcode id=1161 questionId=1116 slug=maximum-level-sum-of-a-binary-tree lang=cpp site=leetcode.com title="Maximum Level Sum of a Binary Tree"
#include <queue>
#include <climits>
using namespace std;

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        long long bestSum = LLONG_MIN;
        int bestLevel = 1;
        int level = 1;

        while (!q.empty()) {
            int sz = (int)q.size();
            long long sum = 0;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); 
                q.pop();

                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (sum > bestSum) {
                bestSum = sum;
                bestLevel = level;
            }

            level++;
        }

        return bestLevel;
    }
};
