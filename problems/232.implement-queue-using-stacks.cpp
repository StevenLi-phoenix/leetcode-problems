// @leetcode id=232 questionId=232 slug=implement-queue-using-stacks lang=cpp site=leetcode.com title="Implement Queue using Stacks"
class MyQueue {
    stack<int> in, out;
    void transfer() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }
public:
    MyQueue() {

    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        transfer();
        int val = out.top();
        out.pop();
        return val;
    }

    int peek() {
        transfer();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
