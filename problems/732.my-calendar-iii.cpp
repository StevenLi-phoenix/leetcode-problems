// @leetcode id=732 questionId=732 slug=my-calendar-iii lang=cpp site=leetcode.com title="My Calendar III"
class MyCalendarThree {
public:
    map<int, int> delta;

    MyCalendarThree() {}

    int book(int startTime, int endTime) {
        delta[startTime]++;
        delta[endTime]--;

        int maxK = 0, current = 0;
        for (auto& [time, d] : delta) {
            current += d;
            maxK = max(maxK, current);
        }
        return maxK;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
