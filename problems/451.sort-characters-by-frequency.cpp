// @leetcode id=451 questionId=451 slug=sort-characters-by-frequency lang=cpp site=leetcode.com title="Sort Characters By Frequency"
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        vector<pair<int,char>> v;
        for (auto& [c, f] : freq) v.push_back({f, c});
        sort(v.rbegin(), v.rend());
        string res;
        for (auto& [f, c] : v) res += string(f, c);
        return res;
    }
};
