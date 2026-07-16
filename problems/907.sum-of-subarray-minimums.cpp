// @leetcode id=907 questionId=943 slug=sum-of-subarray-minimums lang=cpp site=leetcode.com title="Sum of Subarray Minimums"
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        vector<int> stack;

        for (int i = 0; i < n; i++) {
            while (!stack.empty() && arr[stack.back()] > arr[i]) stack.pop_back();
            left[i] = stack.empty() ? -1 : stack.back();
            stack.push_back(i);
        }

        stack.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.empty() && arr[stack.back()] >= arr[i]) stack.pop_back();
            right[i] = stack.empty() ? n : stack.back();
            stack.push_back(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;
            total = (total + (long long)arr[i] * leftCount % MOD * rightCount) % MOD;
        }
        return (int)total;
    }
};
