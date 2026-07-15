// @leetcode id=3805 questionId=4183 slug=count-caesar-cipher-pairs lang=cpp site=leetcode.com title="Count Caesar Cipher Pairs"
class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, long long> freq;
        for (string w : words) {
            int shift = w[0] - 'a';
            for (char& c : w) {
                c = 'a' + ((c - 'a' - shift + 26) % 26);
            }
            freq[w]++;
        }

        long long total = 0;
        for (auto& [key, cnt] : freq) {
            total += cnt * (cnt - 1) / 2;
        }
        return total;
    }
};
