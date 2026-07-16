// @leetcode id=1381 questionId=1497 slug=design-a-stack-with-increment-operation lang=cpp site=leetcode.com title="Design a Stack With Increment Operation"
class CustomStack {
public:
    CustomStack(int maxSize) : maxSize(maxSize) {
    }

    void push(int x) {
        if ((int)stack.size() < maxSize) stack.push_back(x);
    }

    int pop() {
        if (stack.empty()) return -1;
        int val = stack.back();
        stack.pop_back();
        return val;
    }

    void increment(int k, int val) {
        int limit = min(k, (int)stack.size());
        for (int i = 0; i < limit; i++) stack[i] += val;
    }

private:
    int maxSize;
    vector<int> stack;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
