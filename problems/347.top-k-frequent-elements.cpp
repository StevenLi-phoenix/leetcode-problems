// @leetcode id=347 questionId=347 slug=top-k-frequent-elements lang=cpp site=leetcode.com title="Top K Frequent Elements"
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int v : nums) freq[v]++;

        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto& [v, f] : freq) buckets[f].push_back(v);

        vector<int> result;
        for (int f = n; f >= 1 && (int)result.size() < k; f--) {
            for (int v : buckets[f]) {
                result.push_back(v);
                if ((int)result.size() == k) break;
            }
        }
        return result;
    }
};
