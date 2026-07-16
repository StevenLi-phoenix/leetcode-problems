// @leetcode id=3522 questionId=3732 slug=calculate-score-after-performing-instructions lang=cpp site=leetcode.com title="Calculate Score After Performing Instructions"
class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        vector<bool> visited(n, false);
        long long score = 0;
        int i = 0;

        while (i >= 0 && i < n && !visited[i]) {
            visited[i] = true;
            if (instructions[i] == "add") {
                score += values[i];
                i++;
            } else {
                i += values[i];
            }
        }
        return score;
    }
};
