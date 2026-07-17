// @leetcode id=480 questionId=480 slug=sliding-window-median lang=cpp site=leetcode.com title="Sliding Window Median"
class Solution {
public:
    multiset<int> lo, hi;

    void rebalance() {
        if (lo.size() > hi.size() + 1) {
            auto it = prev(lo.end());
            hi.insert(*it);
            lo.erase(it);
        } else if (hi.size() > lo.size()) {
            auto it = hi.begin();
            lo.insert(*it);
            hi.erase(it);
        }
    }

    void addNum(int val) {
        if (lo.empty() || val <= *lo.rbegin()) lo.insert(val);
        else hi.insert(val);
        rebalance();
    }

    void removeNum(int val) {
        auto it = lo.find(val);
        if (it != lo.end()) lo.erase(it);
        else hi.erase(hi.find(val));
        rebalance();
    }

    double getMedian(int k) {
        if (k % 2 == 1) return *lo.rbegin();
        return ((double)*lo.rbegin() + (double)*hi.begin()) / 2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        lo.clear();
        hi.clear();
        vector<double> result;
        int n = nums.size();
        result.reserve(n - k + 1);

        for (int i = 0; i < k; i++) addNum(nums[i]);
        result.push_back(getMedian(k));

        for (int i = k; i < n; i++) {
            addNum(nums[i]);
            removeNum(nums[i - k]);
            result.push_back(getMedian(k));
        }

        return result;
    }
};
