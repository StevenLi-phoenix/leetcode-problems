// @leetcode id=2147 questionId=2251 slug=number-of-ways-to-divide-a-long-corridor lang=cpp site=leetcode.com title="Number of Ways to Divide a Long Corridor"
class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        vector<int> seats;
        for (int i = 0; i < (int)corridor.size(); i++) {
            if (corridor[i] == 'S') seats.push_back(i);
        }

        int m = seats.size();
        if (m == 0 || m % 2 != 0) return 0;

        long long answer = 1;
        for (int k = 2; k < m; k += 2) {
            long long gap = seats[k] - seats[k - 1];
            answer = (answer * gap) % MOD;
        }

        return (int)answer;
    }
};
