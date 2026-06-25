// @leetcode id=1614 questionId=1737 slug=maximum-nesting-depth-of-the-parentheses lang=cpp site=leetcode.com title="Maximum Nesting Depth of the Parentheses"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxD = 0;
        for (char c : s) {
            if (c == '(') {
                depth++;
                maxD = max(maxD, depth);
            } else if (c == ')') {
                depth--;
            }
        }
        return maxD;
    }
};
