// @leetcode id=3403 questionId=3683 slug=find-the-lexicographically-largest-string-from-the-box-i lang=cpp site=leetcode.com title="Find the Lexicographically Largest String From the Box I"
class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1) return word;

        int maxLen = n - numFriends + 1;
        string best;
        for (int i = 0; i < n; ++i) {
            int len = min(maxLen, n - i);
            string candidate = word.substr(i, len);
            if (candidate > best) best = candidate;
        }
        return best;
    }
};
