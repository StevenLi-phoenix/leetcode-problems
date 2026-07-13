// @leetcode id=1054 questionId=1140 slug=distant-barcodes lang=cpp site=leetcode.com title="Distant Barcodes"
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> count;
        for (int v : barcodes) count[v]++;

        vector<pair<int, int>> items(count.begin(), count.end());
        sort(items.begin(), items.end(), [](auto& a, auto& b) { return a.second > b.second; });

        int n = barcodes.size();
        vector<int> result(n);
        int idx = 0;
        for (auto& [val, cnt] : items) {
            for (int i = 0; i < cnt; i++) {
                if (idx >= n) idx = 1;
                result[idx] = val;
                idx += 2;
            }
        }
        return result;
    }
};
