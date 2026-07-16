// @leetcode id=1488 questionId=1612 slug=avoid-flood-in-the-city lang=cpp site=leetcode.com title="Avoid Flood in The City"
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> fullLakeDay; // lake -> day it was filled
        set<int> dryDays; // indices where rains[i]==0

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);
                ans[i] = 1; // placeholder, will fix unused dry days at the end
                continue;
            }

            int lake = rains[i];
            auto it = fullLakeDay.find(lake);
            if (it != fullLakeDay.end()) {
                int prevDay = it->second;
                auto dryIt = dryDays.lower_bound(prevDay);
                if (dryIt == dryDays.end()) return {};
                ans[*dryIt] = lake;
                dryDays.erase(dryIt);
            }
            fullLakeDay[lake] = i;
        }

        return ans;
    }
};
