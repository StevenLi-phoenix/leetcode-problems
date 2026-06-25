// @leetcode id=2434 questionId=2520 slug=using-a-robot-to-print-the-lexicographically-smallest-string lang=cpp site=leetcode.com title="Using a Robot to Print the Lexicographically Smallest String"
class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> minSuffix(n + 1);
        minSuffix[n] = 'z' + 1;

        for (int i = n - 1; i >= 0; i--) {
            minSuffix[i] = min(s[i], minSuffix[i + 1]);
        }

        string result = "";
        stack<char> t;

        for (int i = 0; i < n; i++) {
            t.push(s[i]);

            while (!t.empty() && t.top() <= minSuffix[i + 1]) {
                result += t.top();
                t.pop();
            }
        }

        while (!t.empty()) {
            result += t.top();
            t.pop();
        }

        return result;
    }
};
