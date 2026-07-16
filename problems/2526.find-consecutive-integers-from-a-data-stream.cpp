// @leetcode id=2526 questionId=2620 slug=find-consecutive-integers-from-a-data-stream lang=cpp site=leetcode.com title="Find Consecutive Integers from a Data Stream"
class DataStream {
public:
    int value, k, streak;

    DataStream(int value_, int k_) {
        value = value_;
        k = k_;
        streak = 0;
    }

    bool consec(int num) {
        if (num == value) streak++;
        else streak = 0;
        return streak >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
