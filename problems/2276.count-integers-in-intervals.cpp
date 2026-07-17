// @leetcode id=2276 questionId=2357 slug=count-integers-in-intervals lang=cpp site=leetcode.com title="Count Integers in Intervals"
class CountIntervals {
public:
    map<int, int> intervals; // key = left, value = right, disjoint & sorted
    long long total = 0;

    CountIntervals() {
    }

    void add(int left, int right) {
        auto it = intervals.upper_bound(left);
        if (it != intervals.begin()) {
            auto prev = std::prev(it);
            if (prev->second >= left) it = prev;
        }

        while (it != intervals.end() && it->first <= right) {
            left = min(left, it->first);
            right = max(right, it->second);
            total -= (it->second - it->first + 1);
            it = intervals.erase(it);
        }

        intervals[left] = right;
        total += (right - left + 1);
    }

    int count() {
        return (int)total;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
