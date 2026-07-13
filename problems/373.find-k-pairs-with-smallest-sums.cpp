// @leetcode id=373 questionId=373 slug=find-k-pairs-with-smallest-sums lang=cpp site=leetcode.com title="Find K Pairs with Smallest Sums"
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> result;
        if (n == 0 || m == 0 || k == 0) return result;

        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0; i < n && i < k; i++) {
            pq.push({(long long)nums1[i] + nums2[0], i, 0});
        }

        while (k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            result.push_back({nums1[i], nums2[j]});
            if (j + 1 < m) {
                pq.push({(long long)nums1[i] + nums2[j + 1], i, j + 1});
            }
        }
        return result;
    }
};
