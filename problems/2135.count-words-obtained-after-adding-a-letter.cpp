// @leetcode id=2135 questionId=2256 slug=count-words-obtained-after-adding-a-letter lang=cpp site=leetcode.com title="Count Words Obtained After Adding a Letter"
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        auto toMask = [](const string& s) {
            int mask = 0;
            for (char c : s) mask |= (1 << (c - 'a'));
            return mask;
        };

        unordered_set<int> startMasks;
        for (auto& s : startWords) startMasks.insert(toMask(s));

        int count = 0;
        for (auto& t : targetWords) {
            int mask = toMask(t);
            for (char c : t) {
                int without = mask & ~(1 << (c - 'a'));
                if (startMasks.count(without)) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
