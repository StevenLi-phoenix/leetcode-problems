// @leetcode id=692 questionId=692 slug=top-k-frequent-words lang=cpp site=leetcode.com title="Top K Frequent Words"
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (auto& w : words) count[w]++;

        vector<pair<string, int>> items(count.begin(), count.end());
        sort(items.begin(), items.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });

        vector<string> result;
        for (int i = 0; i < k; i++) result.push_back(items[i].first);
        return result;
    }
};
