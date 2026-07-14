// @leetcode id=843 questionId=873 slug=guess-the-word lang=cpp site=leetcode.com title="Guess the Word"
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int matches(const string& a, const string& b) {
        int m = 0;
        for (int i = 0; i < 6; i++) if (a[i] == b[i]) m++;
        return m;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> candidates = words;
        for (int round = 0; round < 30 && !candidates.empty(); round++) {
            // Minimax: for each candidate as a hypothetical guess, bucket the
            // rest by match count against it; the worst-case bucket size is
            // the number of candidates that would remain if the adversary
            // picks the least informative match count. Pick the guess that
            // minimizes that worst case, so every round shrinks the pool as
            // much as the adversary allows.
            string guess;
            int bestWorst = INT_MAX;
            for (auto& g : candidates) {
                array<int, 7> bucket{};
                for (auto& w : candidates) bucket[matches(w, g)]++;
                int worst = *max_element(bucket.begin(), bucket.end());
                if (worst < bestWorst) { bestWorst = worst; guess = g; }
            }

            int m = master.guess(guess);
            if (m == 6) return;
            vector<string> next;
            for (auto& w : candidates) {
                if (w != guess && matches(w, guess) == m) next.push_back(w);
            }
            candidates = next;
        }
    }
};
