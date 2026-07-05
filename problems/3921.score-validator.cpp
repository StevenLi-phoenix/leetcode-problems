// @leetcode id=3921 questionId=4281 slug=score-validator lang=cpp site=leetcode.com title="Score Validator"
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;
        for (auto& e : events) {
            if (counter == 10) break;
            if (e == "W") ++counter;
            else if (e == "WD" || e == "NB") score += 1;
            else score += stoi(e);
        }
        return {score, counter};
    }
};
