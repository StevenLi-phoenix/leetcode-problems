// @leetcode id=3679 questionId=3953 slug=minimum-discards-to-balance-inventory lang=cpp site=leetcode.com title=" Minimum Discards to Balance Inventory"
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int, deque<int>> kept;
        int discards = 0;

        for (int i = 0; i < (int)arrivals.size(); ++i) {
            int day = i + 1;
            int type = arrivals[i];
            auto& q = kept[type];

            while (!q.empty() && q.front() < day - w + 1) q.pop_front();

            if ((int)q.size() < m) {
                q.push_back(day);
            } else {
                ++discards;
            }
        }
        return discards;
    }
};
