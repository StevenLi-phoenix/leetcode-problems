// @leetcode id=1732 questionId=1833 slug=find-the-highest-altitude lang=cpp site=leetcode.com title="Find the Highest Altitude"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt = 0, curr = 0;
        for (int g : gain) {
            curr += g;
            maxAlt = max(maxAlt, curr);
        }
        return maxAlt;
    }
};
