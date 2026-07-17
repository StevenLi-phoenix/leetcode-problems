// @leetcode id=3734 questionId=4037 slug=lexicographically-smallest-palindromic-permutation-greater-than-target lang=cpp site=leetcode.com title="Lexicographically Smallest Palindromic Permutation Greater Than Target"
class Solution {
public:
    string construct(string half, int middleChar) {
        string result = half;
        if (middleChar != -1) result += (char)middleChar;
        string rev = half;
        reverse(rev.begin(), rev.end());
        result += rev;
        return result;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int oddCount = 0, oddChar = -1;
        for (int c = 0; c < 26; c++) {
            if (freq[c] % 2 == 1) { oddCount++; oddChar = c; }
        }
        if (n % 2 == 0 && oddCount != 0) return "";
        if (n % 2 == 1 && oddCount != 1) return "";

        vector<int> halfFreq(26, 0);
        for (int c = 0; c < 26; c++) halfFreq[c] = freq[c] / 2;
        int middleChar = (n % 2 == 1) ? oddChar : -1;

        int h = n / 2;

        for (int i = h; i >= 0; i--) {
            vector<int> tempFreq = halfFreq;
            bool tightOk = true;
            for (int k = 0; k < i; k++) {
                int c = target[k] - 'a';
                if (tempFreq[c] == 0) { tightOk = false; break; }
                tempFreq[c]--;
            }
            if (!tightOk) continue;

            if (i == h) {
                // fully tight through the half; check middle and mirrored second half
                string half = target.substr(0, h);
                if (n % 2 == 1) {
                    if (middleChar < target[h] - 'a') continue;
                    if (middleChar > target[h] - 'a') {
                        return construct(half, 'a' + middleChar);
                    }
                    // middleChar == target[h], compare mirrored second half
                    string mirrored = half;
                    reverse(mirrored.begin(), mirrored.end());
                    string targetSecond = target.substr(h + 1);
                    if (mirrored > targetSecond) {
                        return construct(half, 'a' + middleChar);
                    }
                    continue;
                } else {
                    string mirrored = half;
                    reverse(mirrored.begin(), mirrored.end());
                    string targetSecond = target.substr(h);
                    if (mirrored > targetSecond) {
                        return construct(half, -1);
                    }
                    continue;
                }
            } else {
                int foundChar = -1;
                int targetC = target[i] - 'a';
                for (int c = targetC + 1; c < 26; c++) {
                    if (tempFreq[c] > 0) { foundChar = c; break; }
                }
                if (foundChar == -1) continue;
                tempFreq[foundChar]--;

                string half = target.substr(0, i);
                half += (char)('a' + foundChar);
                for (int c = 0; c < 26; c++) {
                    for (int cnt = 0; cnt < tempFreq[c]; cnt++) half += (char)('a' + c);
                }

                int mc = (n % 2 == 1) ? ('a' + middleChar) : -1;
                return construct(half, mc);
            }
        }

        return "";
    }
};
