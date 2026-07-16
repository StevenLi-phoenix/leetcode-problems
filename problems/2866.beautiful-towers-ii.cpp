// @leetcode id=2866 questionId=3113 slug=beautiful-towers-ii lang=cpp site=leetcode.com title="Beautiful Towers II"
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> left(n), right(n);
        vector<int> stack;

        for (int i = 0; i < n; i++) {
            while (!stack.empty() && maxHeights[stack.back()] > maxHeights[i]) {
                stack.pop_back();
            }
            if (stack.empty()) {
                left[i] = (long long)maxHeights[i] * (i + 1);
            } else {
                int k = stack.back();
                left[i] = left[k] + (long long)maxHeights[i] * (i - k);
            }
            stack.push_back(i);
        }

        stack.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.empty() && maxHeights[stack.back()] > maxHeights[i]) {
                stack.pop_back();
            }
            if (stack.empty()) {
                right[i] = (long long)maxHeights[i] * (n - i);
            } else {
                int k = stack.back();
                right[i] = right[k] + (long long)maxHeights[i] * (k - i);
            }
            stack.push_back(i);
        }

        long long best = 0;
        for (int i = 0; i < n; i++) {
            best = max(best, left[i] + right[i] - (long long)maxHeights[i]);
        }
        return best;
    }
};
