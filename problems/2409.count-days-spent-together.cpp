// @leetcode id=2409 questionId=2496 slug=count-days-spent-together lang=cpp site=leetcode.com title="Count Days Spent Together"
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto toDayOfYear = [&](const string& s) {
            int month = stoi(s.substr(0, 2));
            int day = stoi(s.substr(3, 2));
            int total = day;
            for (int m = 0; m < month - 1; ++m) total += daysInMonth[m];
            return total;
        };

        int a1 = toDayOfYear(arriveAlice), a2 = toDayOfYear(leaveAlice);
        int b1 = toDayOfYear(arriveBob), b2 = toDayOfYear(leaveBob);

        int start = max(a1, b1), end = min(a2, b2);
        return max(0, end - start + 1);
    }
};
