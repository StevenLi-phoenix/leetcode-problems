// @leetcode id=1178 questionId=1282 slug=number-of-valid-words-for-each-puzzle lang=cpp site=leetcode.com title="Number of Valid Words for Each Puzzle"
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> freq;
        for (auto& w : words) {
            int mask = 0;
            for (char c : w) mask |= (1 << (c - 'a'));
            freq[mask]++;
        }

        vector<int> result;
        for (auto& p : puzzles) {
            int fullMask = 0;
            for (char c : p) fullMask |= (1 << (c - 'a'));
            int firstBit = 1 << (p[0] - 'a');
            int rest = fullMask & ~firstBit;

            int count = 0;
            int sub = rest;
            while (true) {
                int candidate = sub | firstBit;
                auto it = freq.find(candidate);
                if (it != freq.end()) count += it->second;
                if (sub == 0) break;
                sub = (sub - 1) & rest;
            }
            result.push_back(count);
        }
        return result;
    }
};
