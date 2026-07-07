// @leetcode id=43 questionId=43 slug=multiply-strings lang=cpp site=leetcode.com title="Multiply Strings"
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size(), n2 = num2.size();
        vector<int> result(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int pos1 = i + j, pos2 = i + j + 1;
                int sum = mul + result[pos2];
                result[pos2] = sum % 10;
                result[pos1] += sum / 10;
            }
        }

        string s;
        for (int v : result) s += ('0' + v);

        int start = 0;
        while (start < (int)s.size() - 1 && s[start] == '0') ++start;
        return s.substr(start);
    }
};
