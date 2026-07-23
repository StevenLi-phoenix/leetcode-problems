// @leetcode id=1475 questionId=1570 slug=final-prices-with-a-special-discount-in-a-shop lang=cpp site=leetcode.com title="Final Prices With a Special Discount in a Shop"
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> answer = prices;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                answer[st.top()] = prices[st.top()] - prices[i];
                st.pop();
            }
            st.push(i);
        }

        return answer;
    }
};
