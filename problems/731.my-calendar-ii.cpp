// @leetcode id=731 questionId=731 slug=my-calendar-ii lang=cpp site=leetcode.com title="My Calendar II"
class MyCalendarTwo {
private:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlaps;

public:
    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {
        for (auto& [s, e] : overlaps) {
            if (startTime < e && s < endTime) return false;
        }

        for (auto& [s, e] : bookings) {
            int lo = max(s, startTime);
            int hi = min(e, endTime);
            if (lo < hi) overlaps.push_back({lo, hi});
        }

        bookings.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
