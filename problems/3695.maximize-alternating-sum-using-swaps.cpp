// @leetcode id=3695 questionId=4010 slug=maximize-alternating-sum-using-swaps lang=cpp site=leetcode.com title="Maximize Alternating Sum Using Swaps"
class Solution {
public:
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) parent[ra] = rb;
    }

    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto& s : swaps) unite(s[0], s[1]);

        unordered_map<int, vector<int>> groupValues;
        unordered_map<int, pair<int,int>> groupCounts; // evenCount, oddCount

        for (int i = 0; i < n; i++) {
            int root = find(i);
            groupValues[root].push_back(nums[i]);
            if (i % 2 == 0) groupCounts[root].first++;
            else groupCounts[root].second++;
        }

        long long total = 0;
        for (auto& [root, values] : groupValues) {
            sort(values.begin(), values.end(), greater<int>());
            int evenCount = groupCounts[root].first;
            for (int i = 0; i < (int)values.size(); i++) {
                if (i < evenCount) total += values[i];
                else total -= values[i];
            }
        }

        return total;
    }
};
