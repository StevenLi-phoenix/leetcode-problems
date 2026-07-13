// @leetcode id=2284 questionId=2378 slug=sender-with-largest-word-count lang=cpp site=leetcode.com title="Sender With Largest Word Count"
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> count;
        for (size_t i = 0; i < messages.size(); i++) {
            int words = 1;
            for (char c : messages[i]) if (c == ' ') words++;
            count[senders[i]] += words;
        }

        string best;
        int bestCount = -1;
        for (auto& [name, c] : count) {
            if (c > bestCount || (c == bestCount && name > best)) {
                bestCount = c;
                best = name;
            }
        }
        return best;
    }
};
