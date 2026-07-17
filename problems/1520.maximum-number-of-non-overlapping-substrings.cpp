// @leetcode id=1520 questionId=1644 slug=maximum-number-of-non-overlapping-substrings lang=cpp site=leetcode.com title="Maximum Number of Non-Overlapping Substrings"
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int,int>> candidates;
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) continue;
            int i = first[c], r = last[c];
            bool valid = true;
            int j = i;
            while (j <= r) {
                int cj = s[j] - 'a';
                if (first[cj] < i) { valid = false; break; }
                r = max(r, last[cj]);
                j++;
            }
            if (valid) candidates.push_back({i, r});
        }

        sort(candidates.begin(), candidates.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        });

        vector<string> result;
        int lastEnd = -1;
        for (auto& [start, end] : candidates) {
            if (start > lastEnd) {
                result.push_back(s.substr(start, end - start + 1));
                lastEnd = end;
            }
        }

        return result;
    }
};
