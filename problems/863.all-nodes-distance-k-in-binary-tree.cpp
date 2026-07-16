// @leetcode id=863 questionId=893 slug=all-nodes-distance-k-in-binary-tree lang=cpp site=leetcode.com title="All Nodes Distance K in Binary Tree"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildParentMap(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (!node) return;
        parentMap[node] = parent;
        buildParentMap(node->left, node, parentMap);
        buildParentMap(node->right, node, parentMap);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        buildParentMap(root, nullptr, parentMap);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int dist = 0;

        while (!q.empty()) {
            if (dist == k) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                vector<TreeNode*> neighbors = {node->left, node->right, parentMap[node]};
                for (TreeNode* nb : neighbors) {
                    if (nb && !visited.count(nb)) {
                        visited.insert(nb);
                        q.push(nb);
                    }
                }
            }
            dist++;
        }
        return {};
    }
};
