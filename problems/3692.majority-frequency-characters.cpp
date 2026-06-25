// @leetcode id=3692 questionId=4053 slug=majority-frequency-characters lang=cpp site=leetcode.com title="Majority Frequency Characters"
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        unordered_map<int, vector<char>> freqGroups;
        for (auto [c, f] : freq) {
            freqGroups[f].push_back(c);
        }

        int maxGroupSize = 0;
        int maxFreq = 0;
        for (auto [f, group] : freqGroups) {
            if ((int)group.size() > maxGroupSize || ((int)group.size() == maxGroupSize && f > maxFreq)) {
                maxGroupSize = group.size();
                maxFreq = f;
            }
        }

        string result = "";
        for (char c : freqGroups[maxFreq]) {
            result += c;
        }
        return result;
    }
};
