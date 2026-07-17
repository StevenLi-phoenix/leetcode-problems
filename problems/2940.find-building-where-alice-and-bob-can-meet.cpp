// @leetcode id=2940 questionId=3181 slug=find-building-where-alice-and-bob-can-meet lang=cpp site=leetcode.com title="Find Building Where Alice and Bob Can Meet"
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), q = queries.size();
        vector<int> ans(q, -1);
        vector<vector<pair<int,int>>> queriesAt(n);

        for (int i = 0; i < q; i++) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) swap(a, b);
            if (a == b || heights[a] < heights[b]) {
                ans[i] = b;
            } else {
                queriesAt[b].push_back({max(heights[a], heights[b]), i});
            }
        }

        vector<pair<int,int>> stack; // (height, index), descending in both as position increases

        for (int i = n - 1; i >= 0; i--) {
            for (auto& [h, qi] : queriesAt[i]) {
                int lo = 0, hi = (int)stack.size() - 1, resIdx = -1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (stack[mid].first > h) {
                        resIdx = stack[mid].second;
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                ans[qi] = resIdx;
            }

            while (!stack.empty() && stack.back().first <= heights[i]) stack.pop_back();
            stack.push_back({heights[i], i});
        }

        return ans;
    }
};
