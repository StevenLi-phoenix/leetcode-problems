// @leetcode id=2024 questionId=2134 slug=maximize-the-confusion-of-an-exam lang=cpp site=leetcode.com title="Maximize the Confusion of an Exam"
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(longestWindow(answerKey, k, 'T'), longestWindow(answerKey, k, 'F'));
    }

private:
    int longestWindow(const string& s, int k, char target) {
        int left = 0, count = 0, best = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            if (s[right] != target) ++count;
            while (count > k) {
                if (s[left] != target) --count;
                ++left;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
