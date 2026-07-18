// @leetcode id=2813 questionId=2894 slug=maximum-elegance-of-a-k-length-subsequence lang=cpp site=leetcode.com title="Maximum Elegance of a K-Length Subsequence"
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });

        int n = items.size();
        long long sum = 0;
        unordered_set<int> categories;
        vector<int> dupStack;

        for (int i = 0; i < k; i++) {
            sum += items[i][0];
            int cat = items[i][1];
            if (categories.count(cat)) {
                dupStack.push_back(items[i][0]);
            } else {
                categories.insert(cat);
            }
        }

        long long ans = sum + (long long)categories.size() * categories.size();

        for (int i = k; i < n; i++) {
            int cat = items[i][1];
            if (categories.count(cat)) continue;
            if (dupStack.empty()) break;

            sum -= dupStack.back();
            dupStack.pop_back();
            sum += items[i][0];
            categories.insert(cat);

            long long cur = sum + (long long)categories.size() * categories.size();
            ans = max(ans, cur);
        }

        return ans;
    }
};
