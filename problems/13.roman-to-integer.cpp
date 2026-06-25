// @leetcode id=13 questionId=13 slug=roman-to-integer lang=cpp site=leetcode.com title="Roman to Integer"
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int ans = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int cur = val[s[i]];
            int nxt = (i + 1 < (int)s.size()) ? val[s[i + 1]] : 0;
            if (cur < nxt) ans -= cur;
            else ans += cur;
        }
        return ans;
    }
};
