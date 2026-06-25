// @leetcode id=2042 questionId=2168 slug=check-if-numbers-are-ascending-in-a-sentence lang=cpp site=leetcode.com title="Check if Numbers Are Ascending in a Sentence"
class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> numbers;
        stringstream ss(s);
        string token;

        while (ss >> token) {
            if (isdigit(token[0])) {
                numbers.push_back(stoi(token));
            }
        }

        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] <= numbers[i-1]) {
                return false;
            }
        }

        return true;
    }
};
