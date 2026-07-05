// @leetcode id=2332 questionId=2417 slug=the-latest-time-to-catch-a-bus lang=cpp site=leetcode.com title="The Latest Time to Catch a Bus"
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        unordered_set<int> taken(passengers.begin(), passengers.end());

        int m = passengers.size();
        int pj = 0;
        int cnt = 0;
        for (int b : buses) {
            cnt = 0;
            while (pj < m && passengers[pj] <= b && cnt < capacity) {
                ++pj;
                ++cnt;
            }
        }

        int candidate = (cnt < capacity) ? buses.back() : passengers[pj - 1] - 1;
        while (taken.count(candidate)) --candidate;
        return candidate;
    }
};
