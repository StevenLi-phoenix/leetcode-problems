// @leetcode id=3690 questionId=3928 slug=split-and-merge-array-transformation lang=cpp site=leetcode.com title="Split and Merge Array Transformation"
class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if (nums1 == nums2) return 0;

        int n = nums1.size();
        map<vector<int>, int> visited;
        queue<pair<vector<int>, int>> q;

        q.push({nums1, 0});
        visited[nums1] = 0;

        while (!q.empty()) {
            auto [curr, ops] = q.front();
            q.pop();

            for (int L = 0; L < n; L++) {
                for (int R = L; R < n; R++) {
                    vector<int> subarray(curr.begin() + L, curr.begin() + R + 1);
                    vector<int> remaining;
                    for (int i = 0; i < L; i++) remaining.push_back(curr[i]);
                    for (int i = R + 1; i < n; i++) remaining.push_back(curr[i]);

                    for (int pos = 0; pos <= (int)remaining.size(); pos++) {
                        vector<int> next;
                        for (int i = 0; i < pos; i++) next.push_back(remaining[i]);
                        for (int x : subarray) next.push_back(x);
                        for (int i = pos; i < (int)remaining.size(); i++) next.push_back(remaining[i]);

                        if (next == nums2) return ops + 1;

                        if (visited.find(next) == visited.end()) {
                            visited[next] = ops + 1;
                            q.push({next, ops + 1});
                        }
                    }
                }
            }
        }

        return -1;
    }
};
