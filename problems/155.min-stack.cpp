// @leetcode id=155 questionId=155 slug=min-stack lang=cpp site=leetcode.com title="Min Stack"
class MinStack {
public:
    MinStack() {
    }

    void push(int value) {
        data.push_back(value);
        if (minStack.empty() || value <= minStack.back()) {
            minStack.push_back(value);
        } else {
            minStack.push_back(minStack.back());
        }
    }

    void pop() {
        data.pop_back();
        minStack.pop_back();
    }

    int top() {
        return data.back();
    }

    int getMin() {
        return minStack.back();
    }

private:
    vector<int> data;
    vector<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
