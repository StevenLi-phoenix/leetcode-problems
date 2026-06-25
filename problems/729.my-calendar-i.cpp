// @leetcode id=729 questionId=729 slug=my-calendar-i lang=cpp site=leetcode.com title="My Calendar I"
class MyCalendar {
public:
    map<int, int> events;
    
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        auto it = events.lower_bound(startTime);
        // Check if next event overlaps
        if (it != events.end() && it->first < endTime) {
            return false;
        }
        // Check if previous event overlaps
        if (it != events.begin()) {
            --it;
            if (it->second > startTime) {
                return false;
            }
        }
        events[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
