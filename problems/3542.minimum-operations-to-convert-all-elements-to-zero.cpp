// @leetcode id=3542 questionId=3834 slug=minimum-operations-to-convert-all-elements-to-zero lang=cpp site=leetcode.com title="Minimum Operations to Convert All Elements to Zero"
class Solution {
    public:
    int minOperations(vector<int>& nums) {
    stack<int> st;
    st.push(0);
    int ans = 0;
    for (int x : nums) {
    while (st.top() > x) st.pop();
    if (st.top() != x) {
    st.push(x);
    if (x != 0) ans++;
    }
    }
    return ans;
    }
    };
