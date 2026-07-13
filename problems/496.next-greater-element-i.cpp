// @leetcode id=496 questionId=496 slug=next-greater-element-i lang=cpp site=leetcode.com title="Next Greater Element I"
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;
        for (int v : nums2) {
            while (!st.empty() && st.top() < v) {
                nextGreater[st.top()] = v;
                st.pop();
            }
            st.push(v);
        }

        vector<int> ans;
        for (int v : nums1) ans.push_back(nextGreater.count(v) ? nextGreater[v] : -1);
        return ans;
    }
};
