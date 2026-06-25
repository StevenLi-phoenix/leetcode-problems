// @leetcode id=3478 questionId=3759 slug=choose-k-elements-with-maximum-sum lang=cpp site=leetcode.com title="Choose K Elements With Maximum Sum"
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> ans(n, 0);

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums1[i] < nums1[j];
        });

        priority_queue<int, vector<int>, greater<int>> minheap;
        long long sum = 0;
        int i = 0;

        while (i < n) {
            int curr_val = nums1[idx[i]];
            vector<int> group_indices;
            vector<int> group_nums2;

            while (i < n && nums1[idx[i]] == curr_val) {
                group_indices.push_back(idx[i]);
                group_nums2.push_back(nums2[idx[i]]);
                i++;
            }

            for (int gi = 0; gi < (int)group_indices.size(); gi++) {
                ans[group_indices[gi]] = sum;
            }

            for (int gi = 0; gi < (int)group_indices.size(); gi++) {
                int v = group_nums2[gi];
                if ((int)minheap.size() < k) {
                    minheap.push(v);
                    sum += v;
                } else if (v > minheap.top()) {
                    sum -= minheap.top();
                    minheap.pop();
                    minheap.push(v);
                    sum += v;
                }
            }
        }

        return ans;
    }
};
