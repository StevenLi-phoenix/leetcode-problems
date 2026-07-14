// @leetcode id=2232 questionId=2328 slug=minimize-result-by-adding-parentheses-to-expression lang=cpp site=leetcode.com title="Minimize Result by Adding Parentheses to Expression"
class Solution {
public:
    string minimizeResult(string expression) {
        int plusPos = expression.find('+');
        int len = expression.size();

        long long best = LLONG_MAX;
        string bestStr;

        for (int i = 0; i <= plusPos - 1; i++) {
            for (int j = plusPos + 2; j <= len; j++) {
                string prefix = expression.substr(0, i);
                string num1 = expression.substr(i, plusPos - i);
                string num2 = expression.substr(plusPos + 1, j - plusPos - 1);
                string suffix = expression.substr(j);

                long long p = prefix.empty() ? 1 : stoll(prefix);
                long long s = suffix.empty() ? 1 : stoll(suffix);
                long long value = p * (stoll(num1) + stoll(num2)) * s;

                if (value < best) {
                    best = value;
                    bestStr = prefix + "(" + num1 + "+" + num2 + ")" + suffix;
                }
            }
        }
        return bestStr;
    }
};
