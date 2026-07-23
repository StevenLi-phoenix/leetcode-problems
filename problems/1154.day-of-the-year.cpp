// @leetcode id=1154 questionId=1260 slug=day-of-the-year lang=cpp site=leetcode.com title="Day of the Year"
class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        int daysInMonth[] = {31, isLeap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int total = day;
        for (int m = 0; m < month - 1; m++) {
            total += daysInMonth[m];
        }
        return total;
    }
};
