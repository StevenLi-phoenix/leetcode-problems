// @leetcode id=1678 questionId=1797 slug=goal-parser-interpretation lang=cpp site=leetcode.com title="Goal Parser Interpretation"
class Solution {
public:
    string interpret(string command) {
        string result = "";
        for (int i = 0; i < command.length(); i++) {
            if (command[i] == 'G') {
                result += 'G';
            } else if (command[i] == '(') {
                if (command[i+1] == ')') {
                    result += 'o';
                    i += 1;
                } else {
                    result += "al";
                    i += 2;
                }
            }
        }
        return result;
    }
};
