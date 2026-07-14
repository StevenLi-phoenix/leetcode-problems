// @leetcode id=948 questionId=985 slug=bag-of-tokens lang=cpp site=leetcode.com title="Bag of Tokens"
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int lo = 0, hi = tokens.size() - 1;
        int score = 0, best = 0;
        long long p = power;

        while (lo <= hi) {
            if (p >= tokens[lo]) {
                p -= tokens[lo++];
                score++;
                best = max(best, score);
            } else if (score > 0) {
                p += tokens[hi--];
                score--;
            } else {
                break;
            }
        }
        return best;
    }
};
