// @leetcode id=2281 questionId=2368 slug=sum-of-total-strength-of-wizards lang=cpp site=leetcode.com title="Sum of Total Strength of Wizards"
class Solution {
public:
    int totalStrength(vector<int>& strength) {
        const long long MOD = 1e9 + 7;
        int n = strength.size();

        vector<int> left(n), right(n);
        vector<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && strength[st.back()] >= strength[i]) st.pop_back();
            left[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }

        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && strength[st.back()] > strength[i]) st.pop_back();
            right[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }

        vector<long long> P(n + 1, 0);
        for (int i = 0; i < n; i++) P[i + 1] = (P[i] + strength[i]) % MOD;

        vector<long long> SP(n + 2, 0);
        for (int i = 0; i <= n; i++) SP[i + 1] = (SP[i] + P[i]) % MOD;

        long long answer = 0;
        for (int i = 0; i < n; i++) {
            long long l = left[i], r = right[i];
            long long leftCount = i - l;
            long long rightCount = r - i;

            long long sumRight = (SP[r + 1] - SP[i + 1] + MOD) % MOD;
            long long sumLeft = (SP[i + 1] - SP[l + 1] + MOD) % MOD;

            long long contrib = ((leftCount % MOD) * sumRight % MOD - (rightCount % MOD) * sumLeft % MOD + MOD) % MOD;
            contrib = contrib * (strength[i] % MOD) % MOD;

            answer = (answer + contrib) % MOD;
        }

        return (int)answer;
    }
};
