// @leetcode id=352 questionId=352 slug=data-stream-as-disjoint-intervals lang=cpp site=leetcode.com title="Data Stream as Disjoint Intervals"
class SummaryRanges {
public:
    map<int, int> intervals; // start -> end

    SummaryRanges() {

    }

    void addNum(int value) {
        auto it = intervals.upper_bound(value);
        if (it != intervals.begin()) {
            auto prev = it;
            --prev;
            if (prev->second >= value) return; // already covered
            if (prev->second == value - 1) {
                // extend prev
                if (it != intervals.end() && it->first == value + 1) {
                    prev->second = it->second;
                    intervals.erase(it);
                } else {
                    prev->second = value;
                }
                return;
            }
        }
        if (it != intervals.end() && it->first == value + 1) {
            int end = it->second;
            intervals.erase(it);
            intervals[value] = end;
            return;
        }
        intervals[value] = value;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& p : intervals) res.push_back({p.first, p.second});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
