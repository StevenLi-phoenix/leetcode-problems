// @leetcode id=3720 questionId=4020 slug=lexicographically-smallest-permutation-greater-than-target lang=cpp site=leetcode.com title="Lexicographically Smallest Permutation Greater Than Target"
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        sort(s.begin(), s.end());

        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string result = "";

        function<bool(int)> backtrack = [&](int idx) -> bool {
            if (idx == target.length()) {
                return result > target;
            }

            for (int i = target[idx] - 'a'; i < 26; i++) {
                if (freq[i] > 0) {
                    result += (char)('a' + i);
                    freq[i]--;

                    if (i > target[idx] - 'a') {
                        for (int j = 0; j < 26; j++) {
                            for (int k = 0; k < freq[j]; k++) {
                                result += (char)('a' + j);
                            }
                        }
                        return true;
                    } else if (backtrack(idx + 1)) {
                        return true;
                    }

                    result.pop_back();
                    freq[i]++;
                }
            }

            return false;
        };

        if (backtrack(0)) {
            return result;
        }
        return "";
    }
};
