// @leetcode id=2023 questionId=2133 slug=number-of-pairs-of-strings-with-concatenation-equal-to-target lang=cpp site=leetcode.com title="Number of Pairs of Strings With Concatenation Equal to Target"
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> freq;
        for (const string& s : nums) {
            freq[s]++;
        }
        int count = 0;
        int tlen = target.size();
        for (auto& [s, cnt] : freq) {
            int slen = s.size();
            if (slen >= tlen) continue;
            if (target.substr(0, slen) != s) continue;
            string suffix = target.substr(slen);
            if (freq.count(suffix)) {
                if (suffix == s) {
                    count += cnt * (cnt - 1);
                } else {
                    count += cnt * freq[suffix];
                }
            }
        }
        return count;
    }
};
