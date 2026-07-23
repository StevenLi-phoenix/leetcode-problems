// @leetcode id=1185 questionId=1289 slug=day-of-the-week lang=cpp site=leetcode.com title="Day of the Week"
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        int y = year;
        if (month < 3) y -= 1;
        int w = (y + y / 4 - y / 100 + y / 400 + t[month - 1] + day) % 7;

        static vector<string> names = {"Sunday", "Monday", "Tuesday", "Wednesday",
                                        "Thursday", "Friday", "Saturday"};
        return names[w];
    }
};
