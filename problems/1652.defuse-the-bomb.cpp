// @leetcode id=1652 questionId=1755 slug=defuse-the-bomb lang=cpp site=leetcode.com title="Defuse the Bomb"
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        if (k == 0) return result;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            if (k > 0) {
                for (int j = 1; j <= k; j++) sum += code[(i + j) % n];
            } else {
                for (int j = 1; j <= -k; j++) sum += code[((i - j) % n + n) % n];
            }
            result[i] = sum;
        }
        return result;
    }
};
