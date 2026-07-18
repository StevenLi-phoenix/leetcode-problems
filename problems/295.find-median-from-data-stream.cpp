// @leetcode id=295 questionId=295 slug=find-median-from-data-stream lang=cpp site=leetcode.com title="Find Median from Data Stream"
class MedianFinder {
public:
    priority_queue<int> lo; // max-heap, lower half
    priority_queue<int, vector<int>, greater<int>> hi; // min-heap, upper half

    MedianFinder() {

    }

    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if (hi.size() > lo.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        if (lo.size() > hi.size()) return lo.top();
        return (lo.top() + hi.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
