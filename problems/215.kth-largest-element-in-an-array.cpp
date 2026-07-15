// @leetcode id=215 questionId=215 slug=kth-largest-element-in-an-array lang=cpp site=leetcode.com title="Kth Largest Element in an Array"
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (int x : nums) {
            minHeap.push(x);
            if ((int)minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};
