// @leetcode id=3433 questionId=3721 slug=count-mentions-per-user lang=cpp site=leetcode.com title="Count Mentions Per User"
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = events.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            long long ta = stoll(events[a][1]);
            long long tb = stoll(events[b][1]);
            if (ta != tb) return ta < tb;
            bool offA = events[a][0] == "OFFLINE";
            bool offB = events[b][0] == "OFFLINE";
            return offA && !offB;
        });

        vector<long long> offlineUntil(numberOfUsers, 0);
        vector<int> mentions(numberOfUsers, 0);

        for (int i : idx) {
            long long t = stoll(events[i][1]);
            if (events[i][0] == "OFFLINE") {
                int id = stoi(events[i][2]);
                offlineUntil[id] = t + 60;
            } else {
                string& s = events[i][2];
                if (s == "ALL") {
                    for (int u = 0; u < numberOfUsers; u++) mentions[u]++;
                } else if (s == "HERE") {
                    for (int u = 0; u < numberOfUsers; u++) {
                        if (offlineUntil[u] <= t) mentions[u]++;
                    }
                } else {
                    stringstream ss(s);
                    string token;
                    while (ss >> token) {
                        int id = stoi(token.substr(2));
                        mentions[id]++;
                    }
                }
            }
        }
        return mentions;
    }
};
