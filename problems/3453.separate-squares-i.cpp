// @leetcode id=3453 questionId=3763 slug=separate-squares-i lang=cpp site=leetcode.com title="Separate Squares I"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        using ll = long long;
        using ld = long double;

        ld total = 0;
        ll minY = LLONG_MAX;
        ll maxY = LLONG_MIN;

        for (auto &s : squares) {
            ll y = (ll)s[1];
            ll l = (ll)s[2];
            total += (ld)l * (ld)l;
            minY = min(minY, y);
            maxY = max(maxY, y + l);
        }

        ld half = total / 2.0L;

        auto areaBelow = [&](ld Y) -> ld {
            ld sum = 0;
            for (auto &s : squares) {
                ld y = (ld)s[1];
                ld l = (ld)s[2];
                ld top = y + l;
                if (Y <= y) continue;
                if (Y >= top) sum += l * l;
                else sum += (Y - y) * l;
            }
            return sum;
        };

        ld lo = (ld)minY, hi = (ld)maxY;

        // Binary search for smallest Y with areaBelow(Y) >= half
        for (int it = 0; it < 80; ++it) {
            ld mid = (lo + hi) / 2.0L;
            if (areaBelow(mid) >= half) hi = mid;
            else lo = mid;
        }

        return (double)hi;
    }
};
