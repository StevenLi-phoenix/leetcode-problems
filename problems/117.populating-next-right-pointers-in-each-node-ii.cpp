// @leetcode id=117 questionId=117 slug=populating-next-right-pointers-in-each-node-ii lang=cpp site=leetcode.com title="Populating Next Right Pointers in Each Node II"
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
        Node* levelStart = root;

        while (levelStart) {
            Node dummy;
            Node* tail = &dummy;

            for (Node* cur = levelStart; cur; cur = cur->next) {
                if (cur->left) {
                    tail->next = cur->left;
                    tail = tail->next;
                }
                if (cur->right) {
                    tail->next = cur->right;
                    tail = tail->next;
                }
            }

            levelStart = dummy.next;
        }
        return root;
    }
};
