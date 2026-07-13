// @leetcode id=2559 questionId=2691 slug=count-vowel-strings-in-ranges lang=cpp site=leetcode.com title="Count Vowel Strings in Ranges"
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int n = words.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            bool ok = isVowel(words[i].front()) && isVowel(words[i].back());
            prefix[i + 1] = prefix[i] + (ok ? 1 : 0);
        }

        vector<int> ans;
        for (auto& q : queries) {
            ans.push_back(prefix[q[1] + 1] - prefix[q[0]]);
        }
        return ans;
    }
};
