// @leetcode id=138 questionId=138 slug=copy-list-with-random-pointer lang=cpp site=leetcode.com title="Copy List with Random Pointer"
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> mapping;
        for (Node* cur = head; cur; cur = cur->next) {
            mapping[cur] = new Node(cur->val);
        }

        for (Node* cur = head; cur; cur = cur->next) {
            mapping[cur]->next = mapping[cur->next];
            mapping[cur]->random = mapping[cur->random];
        }

        return mapping[head];
    }
};
