// @leetcode id=1882 questionId=2012 slug=process-tasks-using-servers lang=cpp site=leetcode.com title="Process Tasks Using Servers"
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        // free: (weight, idx)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> freeHeap;
        // busy: (freeTime, weight, idx)
        priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<>> busyHeap;

        for (int i = 0; i < n; i++) freeHeap.push({servers[i], i});

        vector<int> ans(m);
        long long currentTime = 0;
        for (int j = 0; j < m; j++) {
            long long t = max(currentTime, (long long)j);
            while (!busyHeap.empty() && busyHeap.top()[0] <= t) {
                auto top = busyHeap.top(); busyHeap.pop();
                freeHeap.push({(int)top[1], (int)top[2]});
            }
            if (freeHeap.empty()) {
                auto top = busyHeap.top(); busyHeap.pop();
                t = top[0];
                freeHeap.push({(int)top[1], (int)top[2]});
                while (!busyHeap.empty() && busyHeap.top()[0] <= t) {
                    auto top2 = busyHeap.top(); busyHeap.pop();
                    freeHeap.push({(int)top2[1], (int)top2[2]});
                }
            }
            auto [weight, idx] = freeHeap.top(); freeHeap.pop();
            ans[j] = idx;
            currentTime = t;
            busyHeap.push({t + tasks[j], weight, idx});
        }
        return ans;
    }
};
