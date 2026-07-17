// @leetcode id=321 questionId=321 slug=create-maximum-number lang=cpp site=leetcode.com title="Create Maximum Number"
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int len) {
        vector<int> stack;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && stack.back() < nums[i] && (int)stack.size() - 1 + (n - i) >= len) {
                stack.pop_back();
            }
            if ((int)stack.size() < len) stack.push_back(nums[i]);
        }
        return stack;
    }

    bool greaterOrEqual(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < (int)a.size() && j < (int)b.size()) {
            if (a[i] != b[j]) return a[i] > b[j];
            i++; j++;
        }
        return i < (int)a.size();
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> result;
        int i = 0, j = 0;
        while (i < (int)a.size() || j < (int)b.size()) {
            if (greaterOrEqual(a, i, b, j)) {
                result.push_back(a[i++]);
            } else {
                result.push_back(b[j++]);
            }
        }
        return result;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> best;

        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> sub1 = maxSubsequence(nums1, i);
            vector<int> sub2 = maxSubsequence(nums2, k - i);
            vector<int> candidate = merge(sub1, sub2);
            if (best.empty() || greaterOrEqual(candidate, 0, best, 0)) {
                best = candidate;
            }
        }

        return best;
    }
};
