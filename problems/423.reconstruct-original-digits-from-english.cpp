// @leetcode id=423 questionId=423 slug=reconstruct-original-digits-from-english lang=cpp site=leetcode.com title="Reconstruct Original Digits from English"
class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++;

        vector<int> digits(10, 0);
        string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        digits[0] = count['z'];
        digits[2] = count['w'];
        digits[4] = count['u'];
        digits[6] = count['x'];
        digits[8] = count['g'];

        for (int i : {0, 2, 4, 6, 8}) {
            for (char c : words[i]) {
                count[c] -= digits[i];
            }
        }

        digits[3] = count['h'];
        digits[5] = count['f'];
        digits[7] = count['s'];

        for (int i : {3, 5, 7}) {
            for (char c : words[i]) {
                count[c] -= digits[i];
            }
        }

        digits[9] = count['i'];
        digits[1] = count['o'];

        string result = "";
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < digits[i]; j++) {
                result += char('0' + i);
            }
        }
        return result;
    }
};
