// @leetcode id=819 questionId=837 slug=most-common-word lang=cpp site=leetcode.com title="Most Common Word"
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        string word;
        for (char c : paragraph) {
            if (isalpha(c)) {
                word += tolower(c);
            } else if (!word.empty()) {
                if (!bannedSet.count(word)) freq[word]++;
                word.clear();
            }
        }
        if (!word.empty() && !bannedSet.count(word)) freq[word]++;

        string best;
        int bestCount = 0;
        for (auto& [w, count] : freq) {
            if (count > bestCount) {
                bestCount = count;
                best = w;
            }
        }
        return best;
    }
};
