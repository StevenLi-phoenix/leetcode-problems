// @leetcode id=3074 questionId=3334 slug=apple-redistribution-into-boxes lang=cpp site=leetcode.com title="Apple Redistribution into Boxes"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for (int x : apple) total += x;

        sort(capacity.begin(), capacity.end(), greater<int>());

        int used = 0, sumCap = 0;
        for (int c : capacity) {
            sumCap += c;
            used++;
            if (sumCap >= total) return used;
        }
        return used; // guaranteed possible by problem statement
    }
};
