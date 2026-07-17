// @leetcode id=1606 questionId=1710 slug=find-servers-that-handled-most-number-of-requests lang=cpp site=leetcode.com title="Find Servers That Handled Most Number of Requests"
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free;
        for (int i = 0; i < k; i++) free.insert(i);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy; // (finishTime, server)

        vector<int> count(k, 0);
        int n = arrival.size();

        for (int i = 0; i < n; i++) {
            long long t = arrival[i];

            while (!busy.empty() && busy.top().first <= t) {
                free.insert(busy.top().second);
                busy.pop();
            }

            if (free.empty()) continue;

            auto it = free.lower_bound(i % k);
            if (it == free.end()) it = free.begin();

            int server = *it;
            free.erase(it);
            count[server]++;
            busy.push({t + load[i], server});
        }

        int mx = *max_element(count.begin(), count.end());
        vector<int> answer;
        for (int i = 0; i < k; i++) if (count[i] == mx) answer.push_back(i);

        return answer;
    }
};
