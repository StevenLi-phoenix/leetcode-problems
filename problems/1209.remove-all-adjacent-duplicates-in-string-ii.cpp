// @leetcode id=1209 questionId=1320 slug=remove-all-adjacent-duplicates-in-string-ii lang=cpp site=leetcode.com title="Remove All Adjacent Duplicates in String II"
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stack;
        for (char c : s) {
            if (!stack.empty() && stack.back().first == c) {
                stack.back().second++;
                if (stack.back().second == k) stack.pop_back();
            } else {
                stack.push_back({c, 1});
            }
        }

        string result;
        for (auto& [c, cnt] : stack) {
            result += string(cnt, c);
        }
        return result;
    }
};
