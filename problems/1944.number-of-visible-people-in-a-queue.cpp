// @leetcode id=1944 questionId=1305 slug=number-of-visible-people-in-a-queue lang=cpp site=leetcode.com title="Number of Visible People in a Queue"
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st; // monotonic decreasing stack of heights
        
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            // pop all people shorter than heights[i] - person i can see them
            while (!st.empty() && st.top() < heights[i]) {
                st.pop();
                count++;
            }
            // if stack not empty, person i can also see the next taller person
            if (!st.empty()) count++;
            ans[i] = count;
            st.push(heights[i]);
        }
        return ans;
    }
};
