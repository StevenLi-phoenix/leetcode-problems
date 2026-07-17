// @leetcode id=3008 questionId=3303 slug=find-beautiful-indices-in-the-given-array-ii lang=cpp site=leetcode.com title="Find Beautiful Indices in the Given Array II"
class Solution {
public:
    vector<int> kmpSearch(const string& text, const string& pattern) {
        int m = pattern.size();
        vector<int> fail(m, 0);
        for (int i = 1; i < m; i++) {
            int j = fail[i - 1];
            while (j > 0 && pattern[i] != pattern[j]) j = fail[j - 1];
            if (pattern[i] == pattern[j]) j++;
            fail[i] = j;
        }

        vector<int> matches;
        int j = 0;
        for (int i = 0; i < (int)text.size(); i++) {
            while (j > 0 && text[i] != pattern[j]) j = fail[j - 1];
            if (text[i] == pattern[j]) j++;
            if (j == m) {
                matches.push_back(i - m + 1);
                j = fail[j - 1];
            }
        }
        return matches;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> aMatches = kmpSearch(s, a);
        vector<int> bMatches = kmpSearch(s, b);

        vector<int> result;
        int j = 0;
        int m = bMatches.size();

        for (int i : aMatches) {
            while (j < m && bMatches[j] < i - k) j++;
            if (j < m && bMatches[j] <= i + k) {
                result.push_back(i);
            }
        }

        return result;
    }
};
