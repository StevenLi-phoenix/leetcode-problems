// @leetcode id=1307 questionId=1429 slug=verbal-arithmetic-puzzle lang=cpp site=leetcode.com title="Verbal Arithmetic Puzzle"
class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        // Each letter contributes coeff[letter] = sum of +/- 10^position
        // across all occurrences (positive in words, negative in result);
        // the puzzle is solvable iff some digit assignment makes the
        // weighted sum zero. Backtrack over letters sorted by |coeff|
        // descending, pruning branches that can't reach zero even in the
        // best case for the remaining letters.
        unordered_map<char, long long> coeffMap;
        unordered_set<char> leadingZeroForbidden;

        auto addWord = [&](const string& w, int sign) {
            long long pow10 = 1;
            for (int i = w.size() - 1; i >= 0; i--) {
                coeffMap[w[i]] += sign * pow10;
                pow10 *= 10;
            }
            if (w.size() > 1) leadingZeroForbidden.insert(w[0]);
            else if (w.size() == 1) { /* single-char words may be zero */ }
        };
        for (auto& w : words) addWord(w, 1);
        addWord(result, -1);

        vector<char> letters;
        for (auto& [c, v] : coeffMap) letters.push_back(c);
        sort(letters.begin(), letters.end(), [&](char a, char b) {
            return abs(coeffMap[a]) > abs(coeffMap[b]);
        });

        int m = letters.size();
        vector<long long> coeff(m);
        vector<bool> forbidZero(m);
        for (int i = 0; i < m; i++) {
            coeff[i] = coeffMap[letters[i]];
            forbidZero[i] = leadingZeroForbidden.count(letters[i]) > 0;
        }
        if (m > 10) return false;

        vector<long long> suffixMaxAbs(m + 1, 0);
        for (int i = m - 1; i >= 0; i--) suffixMaxAbs[i] = suffixMaxAbs[i + 1] + abs(coeff[i]) * 9;

        vector<int> usedDigit(10, -1); // digit -> letter index used, -1 if free
        function<bool(int, long long)> backtrack = [&](int idx, long long partialSum) -> bool {
            if (idx == m) return partialSum == 0;
            if (llabs(partialSum) > suffixMaxAbs[idx]) return false;
            for (int d = 0; d <= 9; d++) {
                if (usedDigit[d] != -1) continue;
                if (d == 0 && forbidZero[idx]) continue;
                usedDigit[d] = idx;
                if (backtrack(idx + 1, partialSum + coeff[idx] * d)) {
                    usedDigit[d] = -1;
                    return true;
                }
                usedDigit[d] = -1;
            }
            return false;
        };

        return backtrack(0, 0);
    }
};
