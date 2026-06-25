// @leetcode id=589 questionId=775 slug=n-ary-tree-preorder-traversal lang=cpp site=leetcode.com title="N-ary Tree Preorder Traversal"
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
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (!root) return result;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            result.push_back(node->val);
            // Push children in reverse order so leftmost is processed first
            for (int i = node->children.size() - 1; i >= 0; i--) {
                stk.push(node->children[i]);
            }
        }
        return result;
    }
};
