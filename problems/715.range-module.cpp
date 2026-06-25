// @leetcode id=715 questionId=715 slug=range-module lang=cpp site=leetcode.com title="Range Module"
class RangeModule {
private:
    set<pair<int, int>> ranges;

public:
    RangeModule() {}

    void addRange(int left, int right) {
        auto it = ranges.lower_bound({left, 0});
        if (it != ranges.begin()) {
            --it;
            if (it->second < left) {
                ++it;
            }
        }

        int new_left = left, new_right = right;

        while (it != ranges.end() && it->first <= right) {
            new_left = min(new_left, it->first);
            new_right = max(new_right, it->second);
            it = ranges.erase(it);
        }

        ranges.insert({new_left, new_right});
    }

    bool queryRange(int left, int right) {
        auto it = ranges.upper_bound({left, INT_MAX});
        if (it == ranges.begin()) return false;
        --it;
        return it->first <= left && it->second >= right;
    }

    void removeRange(int left, int right) {
        auto it = ranges.lower_bound({left, 0});
        if (it != ranges.begin()) {
            --it;
            if (it->second < left) {
                ++it;
            }
        }

        vector<pair<int, int>> to_add;

        while (it != ranges.end() && it->first < right) {
            if (it->second > right) {
                to_add.push_back({right, it->second});
            }
            if (it->first < left) {
                to_add.push_back({it->first, left});
            }
            it = ranges.erase(it);
        }

        for (auto& p : to_add) {
            ranges.insert(p);
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
