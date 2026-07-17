// @leetcode id=2213 questionId=2319 slug=longest-substring-of-one-repeating-character lang=cpp site=leetcode.com title="Longest Substring of One Repeating Character"
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        map<int, pair<int,char>> runs; // start -> (end, char)
        multiset<int> lengths;

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            runs[i] = {j, s[i]};
            lengths.insert(j - i);
            i = j;
        }

        int k = queryCharacters.size();
        vector<int> result(k);

        for (int qi = 0; qi < k; qi++) {
            int i = queryIndices[qi];
            char c = queryCharacters[qi];

            auto it = runs.upper_bound(i);
            --it;
            int start = it->first;
            int end = it->second.first;
            char oldChar = it->second.second;

            if (oldChar != c) {
                lengths.erase(lengths.find(end - start));
                runs.erase(it);

                int midStart = i, midEnd = i + 1;

                if (start < i) {
                    runs[start] = {i, oldChar};
                    lengths.insert(i - start);
                } else {
                    // start == i, check left neighbor
                    if (i > 0) {
                        auto lit = runs.upper_bound(i - 1);
                        if (lit != runs.begin()) {
                            --lit;
                            if (lit->second.first == i && lit->second.second == c) {
                                midStart = lit->first;
                                lengths.erase(lengths.find(lit->second.first - lit->first));
                                runs.erase(lit);
                            }
                        }
                    }
                }

                if (i + 1 < end) {
                    runs[i + 1] = {end, oldChar};
                    lengths.insert(end - (i + 1));
                } else {
                    // i + 1 == end, check right neighbor
                    auto rit = runs.find(end);
                    if (rit != runs.end() && rit->second.second == c) {
                        midEnd = rit->second.first;
                        lengths.erase(lengths.find(rit->second.first - rit->first));
                        runs.erase(rit);
                    }
                }

                runs[midStart] = {midEnd, c};
                lengths.insert(midEnd - midStart);
            }

            result[qi] = *lengths.rbegin();
        }

        return result;
    }
};
