// @leetcode id=2532 questionId=2642 slug=time-to-cross-a-bridge lang=cpp site=leetcode.com title="Time to Cross a Bridge"
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        // time[i] = [right_i, pick_i, left_i, put_i]
        auto moreEfficient = [&](int a, int b) {
            int sa = time[a][2] + time[a][0];
            int sb = time[b][2] + time[b][0];
            if (sa != sb) return sa < sb;
            return a < b;
        };
        auto cmp = [&](int a, int b) { return moreEfficient(a, b); };

        priority_queue<int, vector<int>, decltype(cmp)> waitLeft(cmp), waitRight(cmp);

        using Event = pair<long long,int>; // (finishTime, workerIdx)
        priority_queue<Event, vector<Event>, greater<>> workingRight, workingLeft;

        for (int i = 0; i < k; i++) waitLeft.push(i);

        long long currentTime = 0;
        int remainingToAssign = n;
        int delivered = 0;
        long long answer = 0;

        while (delivered < n) {
            while (!workingRight.empty() && workingRight.top().first <= currentTime) {
                waitRight.push(workingRight.top().second);
                workingRight.pop();
            }
            while (!workingLeft.empty() && workingLeft.top().first <= currentTime) {
                waitLeft.push(workingLeft.top().second);
                workingLeft.pop();
            }

            if (!waitRight.empty()) {
                int w = waitRight.top();
                waitRight.pop();
                currentTime += time[w][2];
                answer = currentTime;
                delivered++;
                workingLeft.push({currentTime + time[w][3], w});
            } else if (!waitLeft.empty() && remainingToAssign > 0) {
                int w = waitLeft.top();
                waitLeft.pop();
                currentTime += time[w][0];
                remainingToAssign--;
                workingRight.push({currentTime + time[w][1], w});
            } else {
                long long nextTime = LLONG_MAX;
                if (!workingRight.empty()) nextTime = min(nextTime, workingRight.top().first);
                if (!workingLeft.empty()) nextTime = min(nextTime, workingLeft.top().first);
                currentTime = nextTime;
            }
        }

        return (int)answer;
    }
};
