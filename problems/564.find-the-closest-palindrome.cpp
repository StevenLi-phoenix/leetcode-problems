// @leetcode id=564 questionId=564 slug=find-the-closest-palindrome lang=cpp site=leetcode.com title="Find the Closest Palindrome"
class Solution {
public:
    string makePalindrome(string s) {
        int len = s.size();
        string half = s.substr(0, (len + 1) / 2);
        string rev = half;
        reverse(rev.begin(), rev.end());
        if (len % 2 == 0) return half + rev;
        return half + rev.substr(1);
    }

    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);
        set<long long> candidates;

        candidates.insert(stoll(makePalindrome(n)));

        long long p1 = (long long)pow(10, len - 1) - 1;
        candidates.insert(p1);
        long long p2 = (long long)pow(10, len) + 1;
        candidates.insert(p2);

        string half = n.substr(0, (len + 1) / 2);
        long long halfVal = stoll(half);

        long long halfPlus = halfVal + 1;
        long long halfMinus = halfVal - 1;

        string halfPlusStr = to_string(halfPlus);
        if ((int)halfPlusStr.size() == (int)half.size()) {
            string rev = halfPlusStr;
            reverse(rev.begin(), rev.end());
            string cand = (len % 2 == 0) ? halfPlusStr + rev : halfPlusStr + rev.substr(1);
            candidates.insert(stoll(cand));
        }

        if (halfMinus >= 0) {
            string halfMinusStr = to_string(halfMinus);
            int padLen = half.size();
            while ((int)halfMinusStr.size() < padLen) halfMinusStr = "0" + halfMinusStr;
            if ((int)halfMinusStr.size() == padLen) {
                string rev = halfMinusStr;
                reverse(rev.begin(), rev.end());
                string cand = (len % 2 == 0) ? halfMinusStr + rev : halfMinusStr + rev.substr(1);
                // strip leading zeros conceptually via stoll
                candidates.insert(stoll(cand));
            }
        }

        candidates.erase(num);

        long long best = -1;
        long long bestDiff = LLONG_MAX;
        for (long long c : candidates) {
            long long diff = llabs(c - num);
            if (diff < bestDiff || (diff == bestDiff && c < best)) {
                bestDiff = diff;
                best = c;
            }
        }

        return to_string(best);
    }
};
