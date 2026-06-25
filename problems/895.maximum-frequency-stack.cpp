// @leetcode id=895 questionId=931 slug=maximum-frequency-stack lang=cpp site=leetcode.com title="Maximum Frequency Stack"
class FreqStack {
private:
    unordered_map<int, int> freq;           // value -> frequency
    unordered_map<int, stack<int>> maxFreqStack; // max frequency -> stack of values
    int maxFreq;

public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        int f = freq[val];
        maxFreqStack[f].push(val);
        maxFreq = max(maxFreq, f);
    }
    
    int pop() {
        int val = maxFreqStack[maxFreq].top();
        maxFreqStack[maxFreq].pop();
        
        freq[val]--;
        
        if (maxFreqStack[maxFreq].empty()) {
            maxFreq--;
        }
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
