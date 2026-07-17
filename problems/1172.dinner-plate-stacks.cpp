// @leetcode id=1172 questionId=1270 slug=dinner-plate-stacks lang=cpp site=leetcode.com title="Dinner Plate Stacks"
class DinnerPlates {
    int cap;
    vector<vector<int>> stacks;
    priority_queue<int, vector<int>, greater<int>> available;

    void trimEmpty() {
        while (!stacks.empty() && stacks.back().empty()) stacks.pop_back();
    }

public:
    DinnerPlates(int capacity) {
        cap = capacity;
    }

    void push(int val) {
        while (!available.empty() && (available.top() >= (int)stacks.size() || (int)stacks[available.top()].size() >= cap)) {
            available.pop();
        }

        int idx;
        if (!available.empty()) {
            idx = available.top();
        } else {
            idx = stacks.size();
        }

        if (idx == (int)stacks.size()) stacks.push_back({});
        stacks[idx].push_back(val);

        if ((int)stacks[idx].size() < cap) available.push(idx);
    }

    int pop() {
        trimEmpty();
        if (stacks.empty()) return -1;
        return popAtStack(stacks.size() - 1);
    }

    int popAtStack(int index) {
        if (index >= (int)stacks.size() || stacks[index].empty()) return -1;
        int val = stacks[index].back();
        stacks[index].pop_back();
        available.push(index);
        if (index == (int)stacks.size() - 1) trimEmpty();
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
