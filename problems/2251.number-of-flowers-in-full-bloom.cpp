// @leetcode id=2251 questionId=2334 slug=number-of-flowers-in-full-bloom lang=cpp site=leetcode.com title="Number of Flowers in Full Bloom"
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts, ends;
        for (auto& f : flowers) {
            starts.push_back(f[0]);
            ends.push_back(f[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        vector<int> ans(people.size());
        for (int i = 0; i < (int)people.size(); ++i) {
            int t = people[i];
            int startedCount = upper_bound(starts.begin(), starts.end(), t) - starts.begin();
            int endedCount = lower_bound(ends.begin(), ends.end(), t) - ends.begin();
            ans[i] = startedCount - endedCount;
        }
        return ans;
    }
};
