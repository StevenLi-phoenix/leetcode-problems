// @leetcode id=2030 questionId=2157 slug=smallest-k-length-subsequence-with-occurrences-of-a-letter lang=cpp site=leetcode.com title="Smallest K-Length Subsequence With Occurrences of a Letter"
class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n = s.size();
        vector<int> suffixCount(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffixCount[i] = suffixCount[i + 1] + (s[i] == letter ? 1 : 0);
        }

        string stack;
        int letterCountInStack = 0;

        int budget = k - repetition; // max non-letter chars allowed in stack

        for (int i = 0; i < n; i++) {
            char c = s[i];
            while (!stack.empty() &&
                   ((int)stack.size() - 1 + (n - i)) >= k &&
                   (stack.back() != letter || (letterCountInStack - 1 + suffixCount[i]) >= repetition) &&
                   (stack.back() > c ||
                    (stack.back() != letter && ((int)stack.size() - letterCountInStack) > budget))) {
                if (stack.back() == letter) letterCountInStack--;
                stack.pop_back();
            }

            if ((int)stack.size() < k) {
                stack.push_back(c);
                if (c == letter) letterCountInStack++;
            }
        }

        return stack;
    }
};
