// @leetcode id=1130 questionId=1228 slug=minimum-cost-tree-from-leaf-values lang=cpp site=leetcode.com title="Minimum Cost Tree From Leaf Values"
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        // Greedily remove the smallest element whenever it has a smaller
        // neighbor on either side, merging it with that neighbor: this is
        // always at least as good as any later merge, since keeping a
        // small leaf around longer only risks pairing it with something
        // larger.
        vector<int> st;
        st.push_back(INT_MAX);
        int total = 0;

        for (int v : arr) {
            while (v >= st.back() && st.size() > 1) {
                int mid = st.back();
                st.pop_back();
                total += mid * min(st.back(), v);
            }
            st.push_back(v);
        }

        while (st.size() > 2) {
            int mid = st.back();
            st.pop_back();
            total += mid * st.back();
        }
        return total;
    }
};
