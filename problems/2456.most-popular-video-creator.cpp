// @leetcode id=2456 questionId=2543 slug=most-popular-video-creator lang=cpp site=leetcode.com title="Most Popular Video Creator"
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long long> popularity;
        unordered_map<string, int> bestViewIdx;

        int n = creators.size();
        for (int i = 0; i < n; ++i) {
            popularity[creators[i]] += views[i];
            auto it = bestViewIdx.find(creators[i]);
            if (it == bestViewIdx.end() ||
                views[i] > views[it->second] ||
                (views[i] == views[it->second] && ids[i] < ids[it->second])) {
                bestViewIdx[creators[i]] = i;
            }
        }

        long long maxPop = LLONG_MIN;
        for (auto& [name, pop] : popularity) maxPop = max(maxPop, pop);

        vector<vector<string>> ans;
        for (auto& [name, pop] : popularity) {
            if (pop == maxPop) {
                ans.push_back({name, ids[bestViewIdx[name]]});
            }
        }
        return ans;
    }
};
