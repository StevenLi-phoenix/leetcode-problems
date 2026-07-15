// @leetcode id=306 questionId=306 slug=additive-number lang=cpp site=leetcode.com title="Additive Number"
class Solution {
public:
    string addStrings(const string& a, const string& b) {
        string result;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            result += ('0' + sum % 10);
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool isValid(const string& s) {
        return s.size() == 1 || s[0] != '0';
    }

    bool dfs(const string& num, int i, const string& first, const string& second) {
        if (i == (int)num.size()) return true;
        string sum = addStrings(first, second);
        if (num.compare(i, sum.size(), sum) != 0) return false;
        return dfs(num, i + sum.size(), second, sum);
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int len1 = 1; len1 <= n / 2; len1++) {
            string first = num.substr(0, len1);
            if (!isValid(first)) continue;
            for (int len2 = 1; len1 + len2 <= n; len2++) {
                string second = num.substr(len1, len2);
                if (!isValid(second)) continue;
                if (len1 + len2 == n) continue;
                if (dfs(num, len1 + len2, first, second)) return true;
            }
        }
        return false;
    }
};
