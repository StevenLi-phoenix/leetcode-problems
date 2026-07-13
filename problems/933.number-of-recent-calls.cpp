// @leetcode id=933 questionId=969 slug=number-of-recent-calls lang=cpp site=leetcode.com title="Number of Recent Calls"
class RecentCounter {
public:
    RecentCounter() {}

    int ping(int t) {
        q.push_back(t);
        while (q.front() < t - 3000) q.pop_front();
        return q.size();
    }

private:
    deque<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
