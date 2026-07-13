// @leetcode id=1481 questionId=1604 slug=least-number-of-unique-integers-after-k-removals lang=cpp site=leetcode.com title="Least Number of Unique Integers after K Removals"
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (int v : arr) freq[v]++;

        vector<int> counts;
        for (auto& [v, c] : freq) counts.push_back(c);
        sort(counts.begin(), counts.end());

        int remaining = counts.size();
        for (int c : counts) {
            if (k >= c) {
                k -= c;
                remaining--;
            } else {
                break;
            }
        }
        return remaining;
    }
};
