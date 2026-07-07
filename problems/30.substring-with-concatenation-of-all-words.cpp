// @leetcode id=30 questionId=30 slug=substring-with-concatenation-of-all-words lang=cpp site=leetcode.com title="Substring with Concatenation of All Words"
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLen = words[0].size();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int n = s.size();
        vector<int> result;
        if (n < totalLen) return result;

        unordered_map<string, int> need;
        for (auto& w : words) ++need[w];

        for (int offset = 0; offset < wordLen; ++offset) {
            unordered_map<string, int> window;
            int left = offset, count = 0;

            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string w = s.substr(right, wordLen);

                if (!need.count(w)) {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                ++window[w];
                ++count;

                while (window[w] > need[w]) {
                    string leftWord = s.substr(left, wordLen);
                    --window[leftWord];
                    --count;
                    left += wordLen;
                }

                if (count == numWords) {
                    result.push_back(left);
                    string leftWord = s.substr(left, wordLen);
                    --window[leftWord];
                    --count;
                    left += wordLen;
                }
            }
        }
        return result;
    }
};
