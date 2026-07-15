// @leetcode id=1186 questionId=1288 slug=maximum-subarray-sum-with-one-deletion lang=cpp site=leetcode.com title="Maximum Subarray Sum with One Deletion"
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int noDelete = arr[0], withDelete = 0;
        int best = arr[0];

        for (int i = 1; i < n; i++) {
            withDelete = max(withDelete + arr[i], noDelete);
            noDelete = max(noDelete + arr[i], arr[i]);
            best = max({best, noDelete, withDelete});
        }
        return best;
    }
};
