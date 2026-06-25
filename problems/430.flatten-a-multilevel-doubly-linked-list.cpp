// @leetcode id=430 questionId=766 slug=flatten-a-multilevel-doubly-linked-list lang=cpp site=leetcode.com title="Flatten a Multilevel Doubly Linked List"
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* child = curr->child;
                Node* nextNode = curr->next;
                
                // Connect curr to child
                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;
                
                // Find tail of child list
                Node* tail = child;
                while (tail->next) tail = tail->next;
                
                // Connect tail to nextNode
                tail->next = nextNode;
                if (nextNode) nextNode->prev = tail;
            }
            curr = curr->next;
        }
        
        return head;
    }
};
