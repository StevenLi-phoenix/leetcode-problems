// @leetcode id=703 questionId=789 slug=kth-largest-element-in-a-stream lang=cpp site=leetcode.com title="Kth Largest Element in a Stream"
class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int x : nums) add(x);
    }

    int add(int val) {
        minHeap.push(val);
        if ((int)minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
