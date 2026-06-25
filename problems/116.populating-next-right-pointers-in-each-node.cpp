// @leetcode id=116 questionId=116 slug=populating-next-right-pointers-in-each-node lang=cpp site=leetcode.com title="Populating Next Right Pointers in Each Node"
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* leftmost = root;
        while (leftmost->left) {
            Node* curr = leftmost;
            while (curr) {
                // Connect left child to right child
                curr->left->next = curr->right;
                // Connect right child to next node's left child
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};
