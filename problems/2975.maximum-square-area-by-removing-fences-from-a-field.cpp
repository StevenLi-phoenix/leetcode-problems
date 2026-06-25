// @leetcode id=2975 questionId=3250 slug=maximum-square-area-by-removing-fences-from-a-field lang=cpp site=leetcode.com title="Maximum Square Area by Removing Fences From a Field"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1000000007LL;

        // Add the unremovable border fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        int H = (int)hFences.size();
        int V = (int)vFences.size();

        // All possible heights obtainable by removing intermediate horizontal fences
        unordered_set<long long> hDiffs;
        hDiffs.reserve((size_t)H * (H - 1) / 2 * 2);

        for (int i = 0; i < H; i++) {
            for (int j = i + 1; j < H; j++) {
                hDiffs.insert((long long)hFences[j] - hFences[i]);
            }
        }

        long long bestSide = 0;
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                long long w = (long long)vFences[j] - vFences[i];
                if (w > bestSide && hDiffs.find(w) != hDiffs.end()) {
                    bestSide = w;
                }
            }
        }

        if (bestSide == 0) return -1;

        long long s = bestSide % MOD;
        return (int)((s * s) % MOD);
    }
};
