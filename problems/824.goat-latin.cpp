// @leetcode id=824 questionId=851 slug=goat-latin lang=cpp site=leetcode.com title="Goat Latin"
class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string word;
        string result;
        int index = 1;

        while (ss >> word) {
            if (!isVowel(word[0])) {
                word = word.substr(1) + word[0];
            }
            word += "ma";
            word += string(index, 'a');

            if (!result.empty()) result += " ";
            result += word;
            index++;
        }

        return result;
    }
};
