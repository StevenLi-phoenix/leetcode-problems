// @leetcode id=707 questionId=838 slug=design-linked-list lang=cpp site=leetcode.com title="Design Linked List"
class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    Node* head; // sentinel, does not hold real data
    int size;

public:
    MyLinkedList() {
        head = new Node(-1);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* cur = head->next;
        for (int i = 0; i < index; ++i) cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;

        Node* prev = head;
        for (int i = 0; i < index; ++i) prev = prev->next;

        Node* node = new Node(val);
        node->next = prev->next;
        prev->next = node;
        ++size;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        Node* prev = head;
        for (int i = 0; i < index; ++i) prev = prev->next;

        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
