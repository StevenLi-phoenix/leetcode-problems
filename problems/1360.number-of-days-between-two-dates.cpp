// @leetcode id=1360 questionId=1274 slug=number-of-days-between-two-dates lang=cpp site=leetcode.com title="Number of Days Between Two Dates"
class Solution {
public:
    int daysToDays(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));
        
        // Days in month (non-leap)
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        auto isLeap = [](int yr) {
            return (yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0;
        };
        
        int days = 0;
        // Add years
        for (int yr = 1971; yr < y; yr++) {
            days += isLeap(yr) ? 366 : 365;
        }
        // Add months
        for (int mo = 1; mo < m; mo++) {
            days += daysInMonth[mo];
            if (mo == 2 && isLeap(y)) days++;
        }
        days += d;
        return days;
    }
    
    int daysBetweenDates(string date1, string date2) {
        return abs(daysToDays(date1) - daysToDays(date2));
    }
};
