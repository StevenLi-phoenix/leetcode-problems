// @leetcode id=1847 questionId=1957 slug=closest-room lang=cpp site=leetcode.com title="Closest Room"
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size(), k = queries.size();

        sort(rooms.begin(), rooms.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        vector<int> order(k);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a][1] > queries[b][1];
        });

        set<int> ids;
        vector<int> answer(k, -1);
        int idx = 0;

        for (int qi : order) {
            int preferred = queries[qi][0], minSize = queries[qi][1];

            while (idx < n && rooms[idx][1] >= minSize) {
                ids.insert(rooms[idx][0]);
                idx++;
            }

            if (ids.empty()) continue;

            auto it = ids.lower_bound(preferred);
            int best = -1, bestDiff = INT_MAX;

            if (it != ids.end()) {
                best = *it;
                bestDiff = abs(*it - preferred);
            }
            if (it != ids.begin()) {
                auto prevIt = prev(it);
                int diff = abs(*prevIt - preferred);
                if (diff < bestDiff || (diff == bestDiff && *prevIt < best)) {
                    best = *prevIt;
                    bestDiff = diff;
                }
            }

            answer[qi] = best;
        }

        return answer;
    }
};
