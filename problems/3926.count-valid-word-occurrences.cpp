// @leetcode id=3926 questionId=4293 slug=count-valid-word-occurrences lang=cpp site=leetcode.com title="Count Valid Word Occurrences"
class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s;
        for (auto& c : chunks) s += c;
        int n = s.size();

        vector<bool> wordChar(n, false);
        for (int i = 0; i < n; i++) {
            if (islower((unsigned char)s[i])) wordChar[i] = true;
            else if (s[i] == '-' && i > 0 && i < n - 1 &&
                     islower((unsigned char)s[i - 1]) && islower((unsigned char)s[i + 1])) {
                wordChar[i] = true;
            }
        }

        unordered_map<string, int> counts;
        int i = 0;
        while (i < n) {
            if (!wordChar[i]) { i++; continue; }
            int j = i;
            while (j < n && wordChar[j]) j++;
            counts[s.substr(i, j - i)]++;
            i = j;
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            auto it = counts.find(q);
            ans.push_back(it == counts.end() ? 0 : it->second);
        }
        return ans;
    }
};
