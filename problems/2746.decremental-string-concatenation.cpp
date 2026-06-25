// @leetcode id=2746 questionId=2854 slug=decremental-string-concatenation lang=cpp site=leetcode.com title="Decremental String Concatenation"
class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        map<tuple<int, char, char>, int> memo;

        function<int(int, char, char)> dfs = [&](int idx, char first, char last) -> int {
            if (idx == words.size()) {
                return 0;
            }

            auto key = make_tuple(idx, first, last);
            if (memo.count(key)) return memo[key];

            string& word = words[idx];
            char word_first = word[0];
            char word_last = word[word.length() - 1];

            int join1_len = word.length();
            if (last == word_first) join1_len--;

            int join2_len = word.length();
            if (word_last == first) join2_len--;

            int res1 = join1_len + dfs(idx + 1, first, word_last);
            int res2 = join2_len + dfs(idx + 1, word_first, last);

            return memo[key] = min(res1, res2);
        };

        int total_len = words[0].length();
        return total_len + dfs(1, words[0][0], words[0][words[0].length() - 1]);
    }
};
