// @leetcode id=1477 questionId=1573 slug=find-two-non-overlapping-sub-arrays-each-with-target-sum lang=cpp site=leetcode.com title="Find Two Non-overlapping Sub-arrays Each With Target Sum"
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, sum = 0;
        int ans = INT_MAX;
        vector<int> best(n, INT_MAX);

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (right > 0) {
                best[right] = best[right - 1];
            }

            if (sum == target) {
                int len = right - left + 1;
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, best[left - 1] + len);
                }
                best[right] = min(best[right], len);
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
