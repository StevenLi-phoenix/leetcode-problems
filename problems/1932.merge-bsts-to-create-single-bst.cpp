// @leetcode id=1932 questionId=2060 slug=merge-bsts-to-create-single-bst lang=cpp site=leetcode.com title="Merge BSTs to Create Single BST"
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
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> rootMap;
        unordered_map<int, int> childCount;
        int totalNodes = 0;

        for (auto t : trees) {
            rootMap[t->val] = t;
            totalNodes++;
            if (t->left) { childCount[t->left->val]++; totalNodes++; }
            if (t->right) { childCount[t->right->val]++; totalNodes++; }
        }

        for (auto& p : childCount) {
            if (p.second > 1) return nullptr;
        }

        TreeNode* candidate = nullptr;
        for (auto t : trees) {
            if (childCount.find(t->val) == childCount.end()) {
                if (candidate != nullptr) return nullptr;
                candidate = t;
            }
        }
        if (!candidate) return nullptr;

        int count = 0;
        function<bool(TreeNode*, long long, long long)> dfs = [&](TreeNode* node, long long lo, long long hi) -> bool {
            if (!node) return true;
            if (node->val <= lo || node->val >= hi) return false;
            count++;

            if (!node->left && !node->right) {
                auto it = rootMap.find(node->val);
                if (it != rootMap.end() && it->second != node) {
                    TreeNode* sub = it->second;
                    node->left = sub->left;
                    node->right = sub->right;
                    rootMap.erase(it);
                }
            }

            return dfs(node->left, lo, node->val) && dfs(node->right, node->val, hi);
        };

        int expectedCount = totalNodes - ((int)trees.size() - 1);
        if (!dfs(candidate, LLONG_MIN, LLONG_MAX) || count != expectedCount) return nullptr;
        return candidate;
    }
};
