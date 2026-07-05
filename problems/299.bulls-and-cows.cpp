// @leetcode id=299 questionId=299 slug=bulls-and-cows lang=cpp site=leetcode.com title="Bulls and Cows"
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int secretCount[10] = {0}, guessCount[10] = {0};
        for (int i = 0; i < (int)secret.size(); ++i) {
            if (secret[i] == guess[i]) ++bulls;
            else {
                ++secretCount[secret[i] - '0'];
                ++guessCount[guess[i] - '0'];
            }
        }
        for (int d = 0; d < 10; ++d) cows += min(secretCount[d], guessCount[d]);
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
