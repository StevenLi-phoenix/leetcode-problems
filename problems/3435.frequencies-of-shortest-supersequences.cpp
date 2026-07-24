// @leetcode id=3435 questionId=3713 slug=frequencies-of-shortest-supersequences lang=cpp site=leetcode.com title="Frequencies of Shortest Supersequences"
class Solution {
public:
    vector<vector<int>> supersequences(vector<string>& words) {
        // collect unique letters and map to bit indices
        vector<int> letterToBit(26, -1);
        vector<int> bitToLetter;
        for (auto& w : words) {
            for (char c : w) {
                if (letterToBit[c - 'a'] == -1) {
                    letterToBit[c - 'a'] = bitToLetter.size();
                    bitToLetter.push_back(c - 'a');
                }
            }
        }
        int m = bitToLetter.size();

        vector<int> outMask(m, 0);
        vector<bool> selfLoop(26, false);

        for (auto& w : words) {
            int x = w[0] - 'a', y = w[1] - 'a';
            if (x == y) {
                selfLoop[x] = true;
            } else {
                int bx = letterToBit[x], by = letterToBit[y];
                outMask[bx] |= (1 << by);
            }
        }

        int full = (1 << m);
        vector<char> acyclic(full, 0);
        acyclic[0] = 1;
        for (int mask = 1; mask < full; mask++) {
            for (int v = 0; v < m; v++) {
                if (!(mask & (1 << v))) continue;
                if (outMask[v] & mask) continue; // v has an outgoing edge to someone else still in mask
                if (acyclic[mask ^ (1 << v)]) {
                    acyclic[mask] = 1;
                    break;
                }
            }
        }

        // weight of a kept mask: only non-self-loop members actually reduce
        // total length by being kept (a self-loop member costs 2 either way,
        // whether kept-and-bumped or duplicated), so maximize non-self-loop
        // kept count, not raw popcount.
        int selfLoopBitMask = 0;
        for (int b = 0; b < m; b++) {
            if (selfLoop[bitToLetter[b]]) selfLoopBitMask |= (1 << b);
        }
        auto weight = [&](int mask) {
            return __builtin_popcount(mask & ~selfLoopBitMask);
        };

        int best = -1;
        for (int mask = 0; mask < full; mask++) {
            if (acyclic[mask]) best = max(best, weight(mask));
        }

        set<vector<int>> results;
        for (int mask = 0; mask < full; mask++) {
            if (acyclic[mask] && weight(mask) == best) {
                vector<int> freq(26, 0);
                for (int b = 0; b < m; b++) {
                    int letter = bitToLetter[b];
                    freq[letter] = (mask & (1 << b)) ? 1 : 2;
                }
                for (int l = 0; l < 26; l++) {
                    if (selfLoop[l]) freq[l] = max(freq[l], 2);
                }
                results.insert(freq);
            }
        }

        return vector<vector<int>>(results.begin(), results.end());
    }
};
