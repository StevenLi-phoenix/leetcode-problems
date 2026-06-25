// @leetcode id=641 questionId=859 slug=design-circular-deque lang=cpp site=leetcode.com title="Design Circular Deque"
class MyCircularDeque {
    vector<int> buf;
    int front, rear, size, cap;
public:
    MyCircularDeque(int k) : buf(k + 1, 0), front(0), rear(0), size(0), cap(k + 1) {}
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + cap) % cap;
        buf[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        buf[rear] = value;
        rear = (rear + 1) % cap;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % cap;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + cap) % cap;
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return buf[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return buf[(rear - 1 + cap) % cap];
    }
    
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == cap - 1; }
};
