// @leetcode id=3348 questionId=3635 slug=smallest-divisible-digit-product-ii lang=cpp site=leetcode.com title="Smallest Divisible Digit Product II"
class Solution {
public:
    int digitExp[10][4]; // digit -> exponents of [2,3,5,7]
    int aMax, bMax, cMax, dMax;
    vector<int> minNeedArr; // flattened DP: minimum digits needed for remaining state
    vector<char> computedArr;

    int idx(int a, int b, int c, int d) {
        return ((a * (bMax + 1) + b) * (cMax + 1) + c) * (dMax + 1) + d;
    }

    int applyDigit(int rem, int digit, int dim, int dimMax) {
        // reduce dimension `dim`'s remaining requirement by digitExp[digit][dim]
        return max(0, rem - digitExp[digit][dim]);
    }

    int minNeed(int a, int b, int c, int d) {
        if (a == 0 && b == 0 && c == 0 && d == 0) return 0;
        int id = idx(a, b, c, d);
        if (computedArr[id]) return minNeedArr[id];
        computedArr[id] = 1;
        int best = INT_MAX;
        for (int dig = 2; dig <= 9; dig++) {
            int na = max(0, a - digitExp[dig][0]);
            int nb = max(0, b - digitExp[dig][1]);
            int nc = max(0, c - digitExp[dig][2]);
            int nd = max(0, d - digitExp[dig][3]);
            if (na == a && nb == b && nc == c && nd == d) continue; // no-op digit here, would self-loop
            int sub = minNeed(na, nb, nc, nd);
            if (sub != INT_MAX) best = min(best, 1 + sub);
        }
        minNeedArr[id] = best;
        return best;
    }

    // builds the lexicographically smallest zero-free string of exactly `len` digits
    // satisfying remaining requirement (a,b,c,d). Assumes feasible (len >= minNeed).
    string buildSuffix(int a, int b, int c, int d, int len) {
        string res;
        for (int pos = 0; pos < len; pos++) {
            int remainingAfter = len - pos - 1;
            for (int dig = 1; dig <= 9; dig++) {
                int na = max(0, a - digitExp[dig][0]);
                int nb = max(0, b - digitExp[dig][1]);
                int nc = max(0, c - digitExp[dig][2]);
                int nd = max(0, d - digitExp[dig][3]);
                int need = minNeed(na, nb, nc, nd);
                if (need <= remainingAfter) {
                    res += ('0' + dig);
                    a = na; b = nb; c = nc; d = nd;
                    break;
                }
            }
        }
        return res;
    }

    string smallestNumber(string num, long long t) {
        for (int i = 0; i < 10; i++) for (int j = 0; j < 4; j++) digitExp[i][j] = 0;
        digitExp[2][0] = 1;
        digitExp[3][1] = 1;
        digitExp[4][0] = 2;
        digitExp[5][2] = 1;
        digitExp[6][0] = 1; digitExp[6][1] = 1;
        digitExp[7][3] = 1;
        digitExp[8][0] = 3;
        digitExp[9][1] = 2;

        long long tt = t;
        int aReq = 0, bReq = 0, cReq = 0, dReq = 0;
        while (tt % 2 == 0) { tt /= 2; aReq++; }
        while (tt % 3 == 0) { tt /= 3; bReq++; }
        while (tt % 5 == 0) { tt /= 5; cReq++; }
        while (tt % 7 == 0) { tt /= 7; dReq++; }
        if (tt != 1) return "-1";

        aMax = aReq; bMax = bReq; cMax = cReq; dMax = dReq;
        int totalStates = (aMax + 1) * (bMax + 1) * (cMax + 1) * (dMax + 1);
        minNeedArr.assign(totalStates, 0);
        computedArr.assign(totalStates, 0);

        int minTotalLen = minNeed(aReq, bReq, cReq, dReq);

        int L = num.size();

        // Check if num itself already works
        {
            bool zeroFree = true;
            int a = aReq, b = bReq, c = cReq, d = dReq;
            for (char ch : num) {
                int dig = ch - '0';
                if (dig == 0) { zeroFree = false; break; }
                a = max(0, a - digitExp[dig][0]);
                b = max(0, b - digitExp[dig][1]);
                c = max(0, c - digitExp[dig][2]);
                d = max(0, d - digitExp[dig][3]);
            }
            if (zeroFree && a == 0 && b == 0 && c == 0 && d == 0) return num;
        }

        // Prefix exponent sums (only valid up to first zero digit)
        int firstZero = L;
        for (int i = 0; i < L; i++) {
            if (num[i] == '0') { firstZero = i; break; }
        }

        vector<array<int,4>> prefix(L + 1);
        prefix[0] = {0, 0, 0, 0};
        for (int i = 0; i < L; i++) {
            int dig = (i < firstZero) ? (num[i] - '0') : 1; // dummy beyond firstZero, unused
            prefix[i + 1][0] = prefix[i][0] + digitExp[dig][0];
            prefix[i + 1][1] = prefix[i][1] + digitExp[dig][1];
            prefix[i + 1][2] = prefix[i][2] + digitExp[dig][2];
            prefix[i + 1][3] = prefix[i][3] + digitExp[dig][3];
        }

        // Try same-length: rightmost feasible increment position. The digit AT firstZero
        // itself is a valid increment point (its prefix 0..firstZero-1 is zero-free); positions
        // strictly after firstZero are not (their prefix would retain the zero).
        for (int pos = min(L - 1, firstZero); pos >= 0; pos--) {
            int pa = prefix[pos][0], pb = prefix[pos][1], pc = prefix[pos][2], pd = prefix[pos][3];
            int remA = max(0, aReq - pa), remB = max(0, bReq - pb), remC = max(0, cReq - pc), remD = max(0, dReq - pd);

            int origDigit = num[pos] - '0';
            int remainingLen = L - pos - 1;

            for (int dig = origDigit + 1; dig <= 9; dig++) {
                int na = max(0, remA - digitExp[dig][0]);
                int nb = max(0, remB - digitExp[dig][1]);
                int nc = max(0, remC - digitExp[dig][2]);
                int nd = max(0, remD - digitExp[dig][3]);
                int need = minNeed(na, nb, nc, nd);
                if (need <= remainingLen) {
                    string result = num.substr(0, pos);
                    result += ('0' + dig);
                    result += buildSuffix(na, nb, nc, nd, remainingLen);
                    return result;
                }
            }
        }

        // Need length L+1 (or minTotalLen if that's larger)
        int newLen = max(L + 1, minTotalLen);
        string result = buildSuffix(aReq, bReq, cReq, dReq, newLen);
        return result;
    }
};
