// @leetcode id=76 questionId=76 slug=minimum-window-substring lang=cpp site=leetcode.com title="Minimum Window Substring"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;
        
        int left = 0, right = 0;
        int valid = 0; // number of unique chars in window that satisfy need
        int start = 0, minLen = INT_MAX;
        
        while (right < (int)s.size()) {
            char c = s[right++];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
            
            // Shrink window from left when we have all required chars
            while (valid == (int)need.size()) {
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                char d = s[left++];
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
