// @leetcode id=2334 questionId=2419 slug=subarray-with-elements-greater-than-varying-threshold lang=cpp site=leetcode.com title="Subarray With Elements Greater Than Varying Threshold"
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> left(n), right(n);
        vector<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.back()] >= nums[i]) st.pop_back();
            left[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }

        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] >= nums[i]) st.pop_back();
            right[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            long long len = right[i] - left[i] - 1;
            if ((long long)nums[i] * len > threshold) return (int)len;
        }

        return -1;
    }
};
