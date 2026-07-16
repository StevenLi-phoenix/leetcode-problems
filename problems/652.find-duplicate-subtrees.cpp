// @leetcode id=652 questionId=652 slug=find-duplicate-subtrees lang=cpp site=leetcode.com title="Find Duplicate Subtrees"
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> count;
        vector<TreeNode*> result;
        serialize(root, count, result);
        return result;
    }

private:
    string serialize(TreeNode* node, unordered_map<string, int>& count, vector<TreeNode*>& result) {
        if (!node) return "#";
        string s = to_string(node->val) + "," + serialize(node->left, count, result) + "," + serialize(node->right, count, result);
        count[s]++;
        if (count[s] == 2) result.push_back(node);
        return s;
    }
};
