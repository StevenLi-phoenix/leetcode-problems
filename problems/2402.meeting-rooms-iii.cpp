// @leetcode id=2402 questionId=2479 slug=meeting-rooms-iii lang=cpp site=leetcode.com title="Meeting Rooms III"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); // sort by start (unique)

        // available rooms: smallest index first
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) freeRooms.push(i);

        // busy rooms: (endTime, room), earliest endTime first, then smallest room
        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>> busy;

        vector<long long> cnt(n, 0);

        for (auto &mt : meetings) {
            long long start = mt[0];
            long long end = mt[1];
            long long dur = end - start;

            // free up rooms that have finished by 'start'
            while (!busy.empty() && busy.top().first <= start) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                cnt[room]++;
                busy.push({end, room});
            } else {
                // delay to the earliest finishing room
                auto [t, room] = busy.top();
                busy.pop();
                cnt[room]++;
                busy.push({t + dur, room});
            }
        }

        int bestRoom = 0;
        for (int i = 1; i < n; i++) {
            if (cnt[i] > cnt[bestRoom]) bestRoom = i;
        }
        return bestRoom;
    }
};
