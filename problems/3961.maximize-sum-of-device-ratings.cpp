// @leetcode id=3961 questionId=4004 slug=maximize-sum-of-device-ratings lang=cpp site=leetcode.com title="Maximize Sum of Device Ratings"
class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        vector<long long> min1(m), min2(m);
        for (int i = 0; i < m; i++) {
            auto& u = units[i];
            long long a = LLONG_MAX, b = LLONG_MAX;
            for (int v : u) {
                if (v < a) { b = a; a = v; }
                else if (v < b) b = v;
            }
            min1[i] = a;
            min2[i] = (u.size() >= 2) ? b : a; // no genuine second value if only 1 unit
        }

        int S = 0;
        for (int i = 1; i < m; i++) if (min1[i] < min1[S]) S = i;

        // Option A: never touch S; every other device improves to max(min1,min2)
        // and dumps its removed minimum onto S, which is always safe since
        // S already holds the global minimum value.
        vector<long long> ratingA(m);
        long long optionA = 0;
        for (int i = 0; i < m; i++) {
            ratingA[i] = (i == S) ? min1[i] : max(min1[i], min2[i]);
            optionA += ratingA[i];
        }

        // Option B: also improve S, dumping its removed (globally smallest)
        // unit onto whichever other device has the smallest Option-A rating,
        // minimizing the resulting damage there.
        long long optionB = LLONG_MIN;
        if (units[S].size() >= 2 && m >= 2) {
            long long secondSmallest = LLONG_MAX;
            for (int i = 0; i < m; i++) if (i != S) secondSmallest = min(secondSmallest, ratingA[i]);
            long long gainS = max(min1[S], min2[S]) - min1[S];
            long long harm = max(0LL, secondSmallest - min1[S]);
            optionB = optionA + gainS - harm;
        }

        return max(optionA, optionB);
    }
};
