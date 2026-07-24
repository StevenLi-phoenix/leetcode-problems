// @leetcode id=3645 questionId=3959 slug=maximum-total-from-optimal-activation-order lang=cpp site=leetcode.com title="Maximum Total from Optimal Activation Order"
class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) groups[limit[i]].push_back(value[i]);

        long long total = 0;
        for (auto& [L, vals] : groups) {
            sort(vals.begin(), vals.end(), greater<int>());
            int take = min((int)vals.size(), L);
            for (int i = 0; i < take; i++) total += vals[i];
        }
        return total;
    }
};
