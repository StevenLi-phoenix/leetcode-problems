// @leetcode id=748 questionId=749 slug=shortest-completing-word lang=cpp site=leetcode.com title="Shortest Completing Word"
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int need[26] = {0};
        for (char c : licensePlate) {
            if (isalpha(c)) need[tolower(c) - 'a']++;
        }

        string best = "";
        for (const string& w : words) {
            int have[26] = {0};
            for (char c : w) have[c - 'a']++;

            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (have[i] < need[i]) { ok = false; break; }
            }

            if (ok && (best.empty() || w.size() < best.size())) best = w;
        }
        return best;
    }
};
