// @leetcode id=429 questionId=764 slug=n-ary-tree-level-order-traversal lang=cpp site=leetcode.com title="N-ary Tree Level Order Traversal"
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            for (int i = 0; i < sz; i++) {
                Node* node = q.front(); q.pop();
                level.push_back(node->val);
                for (Node* child : node->children) q.push(child);
            }
            result.push_back(level);
        }
        return result;
    }
};
