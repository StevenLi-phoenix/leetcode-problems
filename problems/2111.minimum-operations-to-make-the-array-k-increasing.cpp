// @leetcode id=2111 questionId=2234 slug=minimum-operations-to-make-the-array-k-increasing lang=cpp site=leetcode.com title="Minimum Operations to Make the Array K-Increasing"
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int total = 0;
        for (int start = 0; start < k; start++) {
            vector<int> seq;
            for (int i = start; i < n; i += k) seq.push_back(arr[i]);
            vector<int> tails;
            for (int v : seq) {
                auto it = upper_bound(tails.begin(), tails.end(), v);
                if (it == tails.end()) tails.push_back(v);
                else *it = v;
            }
            total += seq.size() - tails.size();
        }
        return total;
    }
};
