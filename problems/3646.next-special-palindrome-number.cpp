// @leetcode id=3646 questionId=3951 slug=next-special-palindrome-number lang=cpp site=leetcode.com title="Next Special Palindrome Number"
class Solution {
public:
    string nStr;
    int h;
    int avail[10];
    int midDigit; // -1 if none
    string result;
    bool found;

    void rec(int pos, bool tight, string& half) {
        if (found) return;
        if (pos == h) {
            string cand = half;
            if (midDigit != -1) cand += ('0' + midDigit);
            string rev = half;
            reverse(rev.begin(), rev.end());
            cand += rev;
            if (!tight) {
                result = cand;
                found = true;
            } else {
                if (cand > nStr) {
                    result = cand;
                    found = true;
                }
            }
            return;
        }
        int lowBound = tight ? (nStr[pos] - '0') : 0;
        for (int d = lowBound; d <= 9; d++) {
            if (avail[d] <= 0) continue;
            bool newTight = tight && (d == lowBound);
            avail[d]--;
            half.push_back('0' + d);
            rec(pos + 1, newTight, half);
            half.pop_back();
            avail[d]++;
            if (found) return;
        }
    }

    long long specialPalindrome(long long n) {
        nStr = to_string(n);
        int nLen = nStr.size();

        long long best = -1;

        for (int mask = 0; mask < 16; mask++) { // subset of {2,4,6,8} bits 0..3
            vector<int> evens;
            int evenSum = 0;
            for (int b = 0; b < 4; b++) {
                if (mask & (1 << b)) {
                    int d = (b + 1) * 2;
                    evens.push_back(d);
                    evenSum += d;
                }
            }
            vector<int> oddOptions = {-1, 1, 3, 5, 7, 9};
            for (int oddD : oddOptions) {
                int L = evenSum + (oddD == -1 ? 0 : oddD);
                if (L == 0) continue;
                if (L < nLen) continue;

                for (int d = 0; d <= 9; d++) avail[d] = 0;
                for (int d : evens) avail[d] = d / 2;
                midDigit = -1;
                if (oddD != -1) {
                    avail[oddD] = oddD / 2;
                    midDigit = oddD;
                }
                h = L / 2;

                string cand;
                if (L > nLen) {
                    // smallest arrangement: ascending half
                    string half = "";
                    for (int d = 1; d <= 9; d++) {
                        for (int c = 0; c < avail[d]; c++) half.push_back('0' + d);
                    }
                    if (half.empty() && midDigit == -1) continue;
                    cand = half;
                    if (midDigit != -1) cand += ('0' + midDigit);
                    string rev = half;
                    reverse(rev.begin(), rev.end());
                    cand += rev;
                } else {
                    // L == nLen, backtrack
                    found = false;
                    result = "";
                    string half = "";
                    rec(0, true, half);
                    if (!found) continue;
                    cand = result;
                }

                if (cand.size() > 18) continue; // guard against overflow beyond long long
                long long val = stoll(cand);
                if (best == -1 || val < best) best = val;
            }
        }

        return best;
    }
};
